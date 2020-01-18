//
// Created by meshi on 16/01/2020.
//
#pragma once

#ifndef FINALPROJECTPART2_SEARCHERABSTRACT_H
#define FINALPROJECTPART2_SEARCHERABSTRACT_H


#include "Searcher.h"

using namespace  std;
template <class T>
class SearcherAbstract: public Searcher<T, vector<State<T> *>>{
protected:
    int evaluateNodes;


public:
    SearcherAbstract() {
        evaluateNodes = 0;
    }

    //for the algo
    int getNumOfNodesEvaluated() {
        return this->evaluateNodes;
    }
    //for the algo
    int addNumOfNodesEvaluated() {
        this->evaluateNodes++;
    }


    //return the reverse path
    vector<State<T> *> reversePath(State<T> *lastState, State<T> *init) {

        vector<State<T> *> shortPath;
        stack <State<T> *> shortPathStack;
        while (!(lastState->equals(init))) {
            shortPathStack.push(lastState);
            lastState = lastState->getCamefrom();
        }
        shortPathStack.push(lastState);
        while (!shortPathStack.empty()){
            shortPath.push_back(shortPathStack.top());
            shortPathStack.pop();
        }

        return shortPath;
    }
    bool containInClose(vector<State<T>*> closeVec,State<T> *s) {
        for (const auto &state : closeVec) {
            if(s->equals(state))
                return true;
        }
        return false;
    }

};

#endif //FINALPROJECTPART2_SEARCHERABSTRACT_H
