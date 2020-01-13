//
// Created by raph on 1/13/20.
//

#ifndef FINALPROJECTPART2_MYCLIENTHANDLER_H
#define FINALPROJECTPART2_MYCLIENTHANDLER_H
using namespace  std;

#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"

class MyClientHandler: ClientHandler {
// Data members of class
private:
    Solver<string,string>* solver;
    CacheManager *cm;

public:
// Pure Virtual Function
    void handlerClient(int socket);
    virtual ~MyClientHandler(){}
/* Other members */
};


#endif //FINALPROJECTPART2_MYCLIENTHANDLER_H
