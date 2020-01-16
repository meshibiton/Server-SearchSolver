//
// Created by raph on 1/13/20.
//
#pragma once

#ifndef FINALPROJECTPART2_CACHEMANAGER_H
#define FINALPROJECTPART2_CACHEMANAGER_H

#include <stdio.h>
#include <iostream>
#include<iterator>
#include <unordered_map>

using namespace  std;
class CacheManager {
// Data members of class



public:
// Pure Virtual Function
    virtual bool isExist (string) = 0;
    virtual void pushSolution(string, string) = 0;
    virtual string popSolution (string) = 0;
    virtual ~CacheManager(){}
/* Other members */

};


#endif //FINALPROJECTPART2_CACHEMANAGER_H
