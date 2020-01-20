//
// Created by meshi on 13/01/2020.
//

#include "MyParallelServer.h"

using namespace std;

//call the fun handler client,she will read data and return result
void parallel(ClientHandler *clientHandler, int new_sock) {
    clientHandler->handlerClient(new_sock);

}
//static parmeter that indicaties if we need to stop-in case of error/time out
bool parallelStop;


//open sereval clients threads
void openParallel(ClientHandler *clientHandler, int port) {
   //create new socket
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    //queue of threads we will open so we can join and delete them
    queue<thread *> threads;
    list<bool *> isRunning;
    bool isFirst = true;

    bind(s, (sockaddr *) &serv, sizeof(serv));
    listen(s, 10000);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);
//set time out to 2 min
    timeval timeout;
    timeout.tv_sec = 120;
    timeout.tv_usec = 0;

    while (!parallelStop) {
        try {
            int new_sock;
            setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
            new_sock = accept(s, (struct sockaddr *) &client, &clilen);

            bool isTimeOut = !isFirst;
            for (auto &run : isRunning) {
                if (*run) {
                    isTimeOut = false;
                    break;
                }
            }
            //in case of time out we stop
            if (isTimeOut) {
                if (new_sock < 0) {
                    if (errno == EWOULDBLOCK) {
                        cout << "paralel timeout!" << endl;
                        break;
                    } else {
                        perror("other error");
                        break;
                    }
                }
            }

            if (new_sock >= 0) {
                bool *isRun = new bool;
                isRunning.push_back(isRun);
                //
                threads.push(new thread(parallel, clientHandler, new_sock));

                isFirst = false;
            }
        } catch (...) {
            cout << "Connection with client stopped" << endl;
        }
    }
    while (!threads.empty()) {
        //make sure to waite until each thread finish and then delete them
        threads.front()->join();
        delete threads.front();
        threads.pop();
    }
    for (auto &i : isRunning) {
        delete i;
    }
}

void MyParallelServer::open(int port, ClientHandler *clientHandler) {
//initialize the static parameter
    parallelStop = false;
    thread *t = new thread(openParallel, clientHandler, port);
    t->join();
    delete t;
}

void MyParallelServer::stop() {
    parallelStop = true;
}
