//
// Created by raph on 1/13/20.
//
#pragma once

#ifndef FINALPROJECTPART2_SOLVER_H
#define FINALPROJECTPART2_SOLVER_H

#include <string>

using namespace  std;
template<class Solution, class Problem>
class Solver {
public:
// Pure Virtual Function
    virtual string solve(Problem)= 0;
    virtual ~Solver(){}

};

#endif //FINALPROJECTPART2_SOLVER_H
