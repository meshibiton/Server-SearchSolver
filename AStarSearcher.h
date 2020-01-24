//
// Created by raph on 1/17/20.
//

#ifndef FINALPROJECTPART2_ASTARSEARCHER_H
#define FINALPROJECTPART2_ASTARSEARCHER_H


#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "SearcherAbstract.h"
#include "MyPriorityQueue.h"


template<class T>
class AStarSearcher : public MyPriorityQueue<T> {

public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        this->zeroNumOfNodesEvaluated();
        //adding the initalState to the open list.
        State<T> *init = searchable->getInitialState();
//        State<T> *goal = searchable->getGoalState();
        this->addOpenList(init);
        vector<State<T> *> closeVec;
        while (!this->isEmpty()) {
            //start develop the node
            State<T> *minState = this->popOpenList();
            this->addNumOfNodesEvaluated();
            closeVec.push_back(minState);
            //if the state is the goal
            if (searchable->isGoalState(minState)) {
                return this->reversePath(minState, init);
            }
            //input the all Neighbors
            vector<State<T> *> statesVecNeighbors = searchable->getAllPossibleState(minState);
            for (unsigned int i = 0; i < statesVecNeighbors.size(); ++i) {
                if (!this->openContains(statesVecNeighbors[i]) && ! this->containInClose(closeVec, statesVecNeighbors[i])) {
                    this->addOpenList(statesVecNeighbors[i]);

                } else if (!this->openContains(statesVecNeighbors[i])) {
                    State<T> *tempState = this->find(statesVecNeighbors[i]);
                    State<T> *current = statesVecNeighbors[i];
                    if (tempState != NULL) {
                        //equal which state is greater  and add him to the open list
                        if (current->getCost() < tempState->getCost()) {
                            this->erase(tempState);
                            this->addOpenList(current);
                        }
                    }
                }
            }
        }
        //there is not path return null empty vec
        vector<State<T> *> emptyVector;
        return emptyVector;
    }

    ~AStarSearcher(){}

};


#endif //FINALPROJECTPART2_ASTARSEARCHER_H
