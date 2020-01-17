//
// Created by raph on 1/17/20.
//
#pragma once

#ifndef FINALPROJECTPART2_BESTFIRSTSEARCHER_H
#define FINALPROJECTPART2_BESTFIRSTSEARCHER_H




#include "MyPriorityQueue.h"

template<class T>
class BestFirstSearcher : public MyPriorityQueue<T> {

public:
    vector<State<T> *> search(Searchable<T> *searchable) {

        this->evaluateNodes = 0;
        //add initial state to the priory Queue
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        this->addOpenList(init);
        vector<State<T> *> closeVec;
        //if there is not any other State in the queue
        while (!this->isEmpty()) {
            //// this->numOfNodesEvaluated++;
            //start with the min state in the queue
            State<T> *minState = this->popOpenList();
            closeVec.push_back(minState);
            //if the state is the goal
            if (searchable->isGoalState(minState)) {
                return this->reversePath(minState, init);
            }
            //return the all Neighbors
            vector<State<T> *> statesVecNeighbors = searchable->getAllPossibleState(minState);
            for (State<T> *s : statesVecNeighbors) {
                if (!this->containInClose(closeVec, s) && !this->openContains(s)) {
                    //add the Neighbor to the queue
                    this->addOpenList(s);
                } else {
                    if (!this->containInClose(closeVec, s)) {
                        //if we found shorter path we will replace it
                        this->replacePathIfShorter(closeVec,s);
                    }
                }
            }
        }
    }
    ~BestFirstSearcher(){}
};

#endif //FINALPROJECTPART2_BESTFIRSTSEARCHER_H
