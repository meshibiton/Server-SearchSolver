//
// Created by raph on 1/13/20.
//
#pragma once

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
    pthread_mutex_t mutex;

public:
//    void updateMap(string problem,string nameFile);
    bool isExitFile(string problem);
    int hashFunc(string);
    bool isExist (string);
    void pushSolution(string, string);
    string popSolution (string);
     ~FileCacheManager();
    /* Other members */

};


#endif //FINALPROJECTPART2_FILECACHEMANAGER_H
