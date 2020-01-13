//
// Created by meshi on 13/01/2020.
//

#ifndef FINALPROJECTPART2_SERVER_H
#define FINALPROJECTPART2_SERVER_H

#include "ClientHandler.h"
namespace server_side{
class Server {
public:
    //open the server and waite for clients
    virtual void open(int port, ClientHandler clientHandler) = 0;
    //close the server
    virtual void stop() = 0;

    virtual ~Server() {}
};

}
#endif //FINALPROJECTPART2_SERVER_H
