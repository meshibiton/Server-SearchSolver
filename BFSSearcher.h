//
// Created by raph on 1/17/20.
//

#ifndef FINALPROJECTPART2_BFSSEARCHER_H
#define FINALPROJECTPART2_BFSSEARCHER_H


#include <iostream>
#include <queue>
#include "SearcherAbstract.h"

using namespace std;

template <class T>

class BFSSearcher: public SearcherAbstract<T>  {
private:

    queue<State<T>*> openList;

    int openListSize() {
        return (int) openList.size();
    }

    bool openContains(State<T> *state) {

        return  isExist(state);
    }
    State<T> *popOpenList() {
        return pop();
    }

    State<T> *pop() {
        State<T> *firstState = openList.front();
        this->openList.pop();
        return firstState;
    }

    void addOpenList(State<T> *s){
//        this->evaluateNodes++;
        openList.push(s);
    }

    bool isExist(State<T> *state) {
        vector<State<T> *> vecStates;
        State<T> *tempState;
        bool flag = false;
        //pop all the state from the queue and check if the state exist
        while (!openList.empty()) {
            tempState = this->popOpenList();
            if (*tempState == *state) {
                flag = true;
            } else {
                vecStates.push_back(tempState);
            }
        }
        //return the queue to the first state
        for (const auto &state : vecStates) {
            this->addOpenList(state);
        }
        return flag;
    }


public:


    vector<State<T> *> search(Searchable<T> *searchable) {
        //initial with 0
        this->zeroNumOfNodesEvaluated();
        vector<State<T> *> closeVec;
        //add the init to the queue
        this->addOpenList(searchable->getInitialState());
        //while ther are nod in the queue continue
        while (this->openListSize() > 0) {
            this->addNumOfNodesEvaluated();
            State<T> *curState = this->popOpenList();

            if (searchable->isGoalState(curState)) {
                return this->reversePath(curState, searchable->getInitialState());
            }

//            //check if exist in the visited nod
//            if (!this->containInClose(closeVec, curState)) {
//                closeVec.push_back(curState);
//            }

            //return the all Neighbors
            vector<State<T>*> statesVec = searchable->getAllPossibleState(curState);
            for (State<T> *s : statesVec) {
                //check if exist in the visited nod
                if (!this->containInClose(closeVec, s)) {
                    // add to the queue
                    this->addOpenList(s);
                    // add to the visted node vector
                    closeVec.push_back(s);
                }



//                if (!this->containInClose(closeVec, s) && !this->openContains(s)) {


            }
        }
        vector<State<T> *> emptyVec;
        //there is not path
        return emptyVec;
    }





    ~BFSSearcher(){}


};




#endif //FINALPROJECTPART2_BFSSEARCHER_H
