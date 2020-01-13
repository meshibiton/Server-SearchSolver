//
// Created by raph on 1/13/20.
//

#ifndef FINALPROJECTPART2_CACHEMANAGER_H
#define FINALPROJECTPART2_CACHEMANAGER_H

#include <stdio.h>
#include <iostream>
#include <bits/unordered_map.h>
#include<iterator>
#include <unordered_map>

using namespace  std;
class CacheManager {
// Data members of class



public:
// Pure Virtual Function
    virtual bool isExist (string);
    virtual void pushSolution(string, string);
    virtual string popSolution (string);
    virtual ~CacheManager(){}
/* Other members */

};


#endif //FINALPROJECTPART2_CACHEMANAGER_H
