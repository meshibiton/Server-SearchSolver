//
// Created by raph on 1/17/20.
//

#ifndef FINALPROJECTPART2_ASTARSEARCHER_H
#define FINALPROJECTPART2_ASTARSEARCHER_H


#pragma once

#include "MyPriorityQueue.h"
#include <math.h>
#include "State.h"
#include <vector>

template<class T>
class AStarSearcher : public MyPriorityQueue<T> {
private:
    int heuristicCost(State<T> *current, State<T> *goal) {
        pair<int, int> currentPair = current->getState();
        pair<int, int> goalPair = goal->getState();

        int x = currentPair.first - goalPair.first;
        int y = currentPair.second - goalPair.second;

//        return (int) sqrt((x * x) + (y * y));
        return x+y;
    }


public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        //add initial state to the priory Queue
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        this->addOpenList(init);
        vector<State<T> *> closeVec;
        //if there is not any other State in the queue
        init->setCost(this->heuristicCost(init,goal)+ init->getCost());
        while (!this->openList.empty()) {
            auto minState = this->popOpenList();
            this->addNumOfNodesEvaluated();
            //if the state is the goal
            if (searchable->isGoalState(minState)) {
                return this->reversePath(minState, init);
            }
            // open.pop();
            closeVec.push_back(minState);
            //return the all Neighbors
            vector<State<T> *> statesVecNeighbors = searchable->getAllPossibleState(minState);
            for (State<T> *s : statesVecNeighbors) {
                if (s == nullptr || s->getCost() == -1) {
                    continue;
                }
                // mark all states as visited or not

                bool inClosevec = false;
                for (auto &vertex : closeVec) {
                    if (s->equals(vertex)) {
                        inClosevec = true;
                        break;
                    }
                }
                // Ignore the neighbor which is already evaluated
                if (inClosevec) {
                    continue;
                }
                int tentative_gScore = minState->getCost();//gScore[current] +cost

                if (!this->openContains(s)) { // Discover a new node
                    this->addOpenList(s);
                } else if (tentative_gScore >= s->getCost()) {
                    continue;
                }
                // This path is the best until now. Record it!
                s->setCamefrom(minState);
                s->setCost(heuristicCost(s, goal) + s->getCost());
            }
        }
        vector<State<T> *> emptyVec;
    //there is not path
    return emptyVec;
}

//
//template<class T>
//class AStarSearcher : public MyPriorityQueue<T> {
//
//public:
//    vector<State<T> *> search(Searchable<T> *searchable) {
//
//        this->zeroNumOfNodesEvaluated();
//        //add initial state to the priory Queue
//        State<T> *init = searchable->getInitialState();
//        State<T> *goal = searchable->getGoalState();
//        this->addOpenList(init);
//        vector<State<T> *> closeVec;
//        //if there is not any other State in the queue
//        while (!this->isEmpty()) {
//             this->addNumOfNodesEvaluated();
//            //start with the min state in the queue
//            State<T> *minState = this->popOpenList();
//            closeVec.push_back(minState);
//            //if the state is the goal
//            if (searchable->isGoalState(minState)) {
//                return this->reversePath(minState, init);
//            }
//
//            //return the all Neighbors
//            vector<State<T> *> statesVecNeighbors = searchable->getAllPossibleState(minState);
//            for (State<T> *s : statesVecNeighbors) {
//                if (!this->containInClose(closeVec, s) && !this->openContains(s)) {
//                    //add the Neighbor to the queue
//                    this->addOpenList(s);
//                    //if not in the open list
//                } else if (!this->openContains(s)) {
//                    {
//                        //find the  other option and check and check if they chipper
//                        //then the exist node
//                        State<T> *otherState = this->find(s);
//                        if (otherState != NULL) {
//                            if (otherState->getCost() < minState->getCost()) {
//                                //remove the old state with the long path
//                                this->erase(minState);
//                                //add the sort path
//                                this->addOpenList(s);
//                            }
//                        }
//                    }
//                }
//
//            }
//        }
//        vector<State<T> *> emptyVec;
//        //there is not path
//        return emptyVec;
//
//    }

    ~AStarSearcher() {}
};


#endif //FINALPROJECTPART2_ASTARSEARCHER_H
