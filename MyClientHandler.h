//
// Created by raph on 1/13/20.
//

#ifndef FINALPROJECTPART2_MYCLIENTHANDLER_H
#define FINALPROJECTPART2_MYCLIENTHANDLER_H
using namespace  std;

#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"

class MyClientHandler:public ClientHandler {
// Data members of class
private:
    Solver<string,string> *solver;
    CacheManager *cacheManager;

public:
   MyClientHandler(Solver<string,string> *s, CacheManager *c) {
       this->solver=s;
       this->cacheManager=c;
    }
// Pure Virtual Function
    void handlerClient(int socket);
    virtual ~MyClientHandler(){}
/* Other members */
};


#endif //FINALPROJECTPART2_MYCLIENTHANDLER_H
