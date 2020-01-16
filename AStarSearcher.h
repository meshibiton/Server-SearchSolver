//
// Created by raph on 1/17/20.
//

#ifndef FINALPROJECTPART2_ASTARSEARCHER_H
#define FINALPROJECTPART2_ASTARSEARCHER_H



#pragma once

#include "MyPriorityQueue.h"

template<class T>
class AStarSearcher : public MyPriorityQueue<Solution, T> {

public:
    vector<State<T> *> search(Searchable<T> *searchable) {

        this->numOfNodesEvaluated = 0;
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
            closeVec.insert(minState);
            //if the state is the goal
            if (searchable->isGoalState(minState)) {
                return this->reversePath(minState, init);
            }
            //return the all Neighbors
            vector<State<T> *> statesVecNeighbors = searchable->getAllPossibleStates(minState);
            for (State<T> *s : statesVecNeighbors) {
                if (!containInClose(closeVec, s) && !this->openContains(s)) {
                    //add the Neighbor to the queue
                    this->addOpenList(s);
                    //if not in the open list
                } else if (!this->openContains(s)) {
                    {
                        //find the  other option and check and check if they chipper
                        //then the exist node
                        State<T> *otherState = find(s);
                        if (otherState->getCost() < minState->getCost()) {
                            //remove the old state with the long path
                            this->erase(minState);
                            //add the sort path
                            this->addOpenList(s);
                        }
                    }
                }

            }
        }
        //there is not path
        return nullptr;

    }

    ~AStarSearcher() {}
};




#endif //FINALPROJECTPART2_ASTARSEARCHER_H
