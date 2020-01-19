//
// Created by meshi on 13/01/2020.
//
#pragma once
#ifndef FINALPROJECTPART2_MYPARALLELSERVER_H
#define FINALPROJECTPART2_MYPARALLELSERVER_H
#include "Server.h"

//#include "ClientHandler.h"
#include <thread>
#include <netinet/in.h>
#include <iostream>
#include <queue>
#include <list>
#include "Server.h"

using namespace  std;
using namespace server_side;
//bool serialStop;



//void parallel(ClientHandler *clientHandler, int new_sock, bool *isRun) {
//    cout << "start" << endl;
//    string nextBuffer, connectedBuffer;
//    char buffer[4096];
//    string strBuff;
//    *isRun = true;
//
//    try {
//        while (!parallelStop) {
//            bzero(buffer, 256);
//            read(new_sock, buffer, 255);
//            connectedBuffer += buffer;
//            string strBuff(connectedBuffer);
//            if (strBuff.find("end") != string::npos) {
//                string answer;
//                //clientHandler->handleClient(connectedBuffer, answer);
//                const char *cstr = answer.c_str();
//                write(new_sock, cstr, answer.size());
//                break;
//            }
//        }
//    } catch (...) {
//        cout << "catch" << endl;
//    }
//    close(new_sock);
//    *isRun = false;
//    cout << "stop" << endl;
//}
//





class MyParallelServer : public server_side::Server {

public:
    MyParallelServer() = default;


    void open(int port, ClientHandler *clientHandler);

    void stop();

};

#endif //FINALPROJECTPART2_MYPARALLELSERVER_H
