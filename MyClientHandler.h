//
// Created by raph on 1/13/20.
//

#ifndef FINALPROJECTPART2_MYCLIENTHANDLER_H
#define FINALPROJECTPART2_MYCLIENTHANDLER_H


#include "Solver.h"

class MyClientHandler {
// Data members of class
Solver solver;
CacheManager cm;

public:
// Pure Virtual Function
    virtual void solve(Problem)= 0;
    virtual ~MyClientHandler(){}
/* Other members */
};


#endif //FINALPROJECTPART2_MYCLIENTHANDLER_H
