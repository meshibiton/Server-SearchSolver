//
// Created by meshi on 13/01/2020.
//
#pragma once
#ifndef FINALPROJECTPART2_MYPARALLELSERVER_H
#define FINALPROJECTPART2_MYPARALLELSERVER_H
#include "Server.h"
#include <thread>
#include <netinet/in.h>
#include <iostream>
#include <queue>
#include <list>
#include "Server.h"

using namespace  std;
using namespace server_side;

class MyParallelServer : public server_side::Server {

public:
    MyParallelServer() = default;


    void open(int port, ClientHandler *clientHandler);

    void stop();

};

#endif //FINALPROJECTPART2_MYPARALLELSERVER_H
