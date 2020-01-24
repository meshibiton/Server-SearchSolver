//
// Created by meshi on 13/01/2020.
//

#include "MySerialServer.h"
#include "Server.h"
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>

using namespace server_side;

void MySerialServer::open(int port, ClientHandler *clientHandler) {
    cout << "how are you" << endl;

    //----create socket-----------
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    //we need to convert our number to a number that the network understands.
    //----the actual bind command----
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return;
    }

    //   std::thread thread1(&MySerialServer::serverSide,this,port,clientHandler);
    //------create a sperate thread that will handle client-----
    std::thread thread1(&MySerialServer::serverSide, this, socketfd, clientHandler);
    if (thread1.joinable()) {
        thread1.join();
    }
    close(socketfd);
}

void MySerialServer::stop() {
    this->serverStop = true;
}

void MySerialServer::serverSide(int socketfd, ClientHandler *clientHandler) {
    struct sockaddr_in address;
    while (!this->serverStop) {
        //making socket listen to the port
        if (listen(socketfd, 1) == -1) {
            std::cout << "Error during listening command" << std::endl;
            return;
        } else {
            std::cout << "Server is now listening ..." << std::endl;
        }
        //before doing accept we will declare the time we are gonna waite before time-out
        struct timeval tv;
        tv.tv_sec = 120;
        tv.tv_usec = 0;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
        //it time out occur

        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                   (socklen_t *) &address);
        if (client_socket < 0) {
            //in case of time out
            if ((errno == EWOULDBLOCK) || (errno == EAGAIN)) {
                this->stop();
                std::cerr << "TIME OUT!!" << std::endl;

                //in case of other error
            } else {
                if (client_socket == -1) {
                    std::cerr << "Error accepting client" << std::endl;
                    return;
                }
            }
        } else {
            //we will send the client to handle the client we received
            clientHandler->handlerClient(client_socket);
        }
    }
}

