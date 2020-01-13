//
// Created by raph on 1/13/20.
//

#ifndef FINALPROJECTPART2_SOLVER_H
#define FINALPROJECTPART2_SOLVER_H

#include <string>

using namespace  std;
template<class Problem, class Solution>
class Solver {

public:
// Pure Virtual Function
    virtual string solve(string)= 0;
    virtual ~Solver(){}
/* Other members */
};

#endif //FINALPROJECTPART2_SOLVER_H
