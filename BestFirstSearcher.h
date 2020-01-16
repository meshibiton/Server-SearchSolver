//
// Created by raph on 1/16/20.
//
#pragma once

#ifndef FINALPROJECTPART2_BESTFIRSTSEARCHER_H
#define FINALPROJECTPART2_BESTFIRSTSEARCHER_H

#include "MyPriorityQueue.h"

class BestFirstSearcher : public MyPriorityQueue<Solution, T> {

public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        vector<State<T> *> closeVec;

        return closeVec;
    }

//    ~BestFirstSearcher() {}
};


#endif //FINALPROJECTPART2_BESTFIRSTSEARCHER_H
