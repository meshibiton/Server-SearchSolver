//
// Created by raph on 1/13/20.
//

#ifndef FINALPROJECTPART2_MYCLIENTHANDLER_H
#define FINALPROJECTPART2_MYCLIENTHANDLER_H
using namespace  std;

#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"
#include <iostream>
#include <vector>

class MyClientHandler:public ClientHandler {
// Data members of class
private:
    Solver<string,vector<vector<double >>> *solver;
    CacheManager *cacheManager;

public:
   vector<vector<double >> fromStringToVec(string row);
   MyClientHandler(Solver<string,vector<vector<double >>> *solver1, CacheManager *cacheManager1) {
       this->solver=solver1;
       this->cacheManager=cacheManager1;
    }
// Pure Virtual Function
    void handlerClient(int socket);
    ~MyClientHandler() {
        delete (solver);
        delete(cacheManager);
    }
/* Other members */
};


#endif //FINALPROJECTPART2_MYCLIENTHANDLER_H
