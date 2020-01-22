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
        State<T> *goal = searchable->getGoalState();
        this->addOpenList(init);
        vector<State<T> *> closeVec;
        while (!this->isEmpty()) {
            //start develop the node
            State<T> *minState = this->popOpenList();
            this->addNumOfNodesEvaluated();
            closeVec.push_back(minState);
            //if we got to the goal
            //if the state is the goal
            if (searchable->isGoalState(minState)) {
                return this->reversePath(minState, init);
            }

            vector<State<T> *> successors = searchable->getAllPossibleState(minState);
            for (int i = 0; i < successors.size(); ++i) {
                if (!this->openContains(successors[i]) && ! this->containInClose(closeVec, successors[i])) {
                    this->addOpenList(successors[i]);


                } else if (!this->openContains(successors[i])) {
                    State<T> *item = this->find(successors[i]);
                    State<T> *current = successors[i];
                    if (item != NULL) {
                        if (current->getCost() < item->getCost()) {
                            this->erase(item);
                            this->addOpenList(current);
                        }
                    }
                }
            }
        }

        vector<State<T> *> emptyVector;
//        this->clearAll(emptyVector,&pqs);
        return emptyVector;
    }



    ~AStarSearcher(){}

};


#endif //FINALPROJECTPART2_ASTARSEARCHER_H
