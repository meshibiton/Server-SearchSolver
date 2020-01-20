//
// Created by meshi on 13/01/2020.
//

#include "MyParallelServer.h"

using namespace std;


void parallel(ClientHandler *clientHandler, int new_sock) {
    clientHandler->handlerClient(new_sock);

}

bool parallelStop;

void openParallel(ClientHandler *clientHandler, int port) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    queue<thread *> threads;
    list<bool *> isRunning;
    bool isFirst = true;

    bind(s, (sockaddr *) &serv, sizeof(serv));
    listen(s, 20000);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 120;
    timeout.tv_usec = 0;

    while (!parallelStop) {
        try {
            int new_sock;
            setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
            new_sock = accept(s, (struct sockaddr *) &client, &clilen);

            bool isTimeOut = !isFirst;
            for (auto &r : isRunning) {
                if (*r) {
                    isTimeOut = false;
                    break;
                }
            }
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
                //threads.push(new thread(parallel, clientHandler, new_sock, isRun));
                threads.push(new thread(parallel, clientHandler, new_sock));
                isFirst = false;
            }
        } catch (...) {
            cout << "connection with client stopped" << endl;
        }
    }
    while (!threads.empty()) {
        threads.front()->join();
        delete threads.front();
        threads.pop();
    }
    for (auto &i : isRunning) {
        delete i;
    }
}

void MyParallelServer::open(int port, ClientHandler *clientHandler) {

    parallelStop = false;
    thread *t = new thread(openParallel, clientHandler, port);
    t->join();
    delete t;
}


void MyParallelServer::stop() {
     parallelStop = true;
}