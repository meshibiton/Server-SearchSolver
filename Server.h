//
// Created by meshi on 13/01/2020.
//

#ifndef FINALPROJECTPART2_SERVER_H
#define FINALPROJECTPART2_SERVER_H

#include "ClientHandler"

class Server {
    virtual void open(int port,ClientHandler clientHandler) = 0;
    virtual void stop() = 0;
};


#endif //FINALPROJECTPART2_SERVER_H
