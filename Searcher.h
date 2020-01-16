//
// Created by meshi on 14/01/2020.
//
#pragma once
#ifndef FINALPROJECTPART2_SEARCHER_H
#define FINALPROJECTPART2_SEARCHER_H


#include "Searchable.h"

template <class T, class Solution>
class Searcher {
public:
    //get the solution from searcher
    virtual Solution search(Searchable<T>* searchable) = 0;
    virtual int getNumOfNodesEvaluated()= 0;
    virtual ~Searcher(){}
};

#endif //FINALPROJECTPART2_SEARCHER_H
