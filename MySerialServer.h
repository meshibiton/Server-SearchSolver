//
// Created by meshi on 13/01/2020.
//

#ifndef FINALPROJECTPART2_MYSERIALSERVER_H
#define FINALPROJECTPART2_MYSERIALSERVER_H
#include "Server.h"

class MySerialServer :public Server{
private:
    Solver solver;
    CachManager cm;
public:
    virtual ~MySerialServer(){}
};


#endif //FINALPROJECTPART2_MYSERIALSERVER_H
