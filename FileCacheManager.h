//
// Created by raph on 1/13/20.
//

#ifndef FINALPROJECTPART2_FILECACHEMANAGER_H
#define FINALPROJECTPART2_FILECACHEMANAGER_H


#include <bits/stdc++.h>
#include "CacheManager.h"
#include <bits/unordered_map.h>
#include<iterator>
#include <unordered_map>

using namespace  std;

class FileCacheManager : public CacheManager{
// Data members of class
private:
    unordered_map<string, string> mapCachProblem;

public:
// Pure Virtual Function
    bool isExist (string);
    void pushSolution(string, string);
    string popSolution (string);
    virtual ~FileCacheManager(){}
/* Other members */

};


#endif //FINALPROJECTPART2_FILECACHEMANAGER_H
