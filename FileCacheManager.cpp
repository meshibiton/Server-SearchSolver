//
// Created by raph on 1/13/20.
//

// CPP code to check if a key is present
// in an unordered_map
#include "FileCacheManager.h"
using namespace  std;

bool FileCacheManager::isExist(string problem){


    if (this->mapCachProblem.find(problem) == this->mapCachProblem.end()){
        return false;
    } else{
        return true;
    }
}
void FileCacheManager::pushSolution(string problem, string solution) {
    this->mapCachProblem[problem] = solution;


}
string FileCacheManager::popSolution(string problem){
    return this->mapCachProblem.find(problem)->second;
}
