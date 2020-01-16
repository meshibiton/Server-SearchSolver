//
// Created by meshi on 16/01/2020.
//

#ifndef FINALPROJECTPART2_SEARCHERABSTRACT_H
#define FINALPROJECTPART2_SEARCHERABSTRACT_H


#include "Searcher.h"
#include "MyPriorityQueue.h"
#include "State.h"
#include "Searchable.h"

using namespace  std;

class SearcherAbstract: public Searcher <class T, class Solution>{
private:
    int evaluateNodes;


public:
    SearcherAbstract() {
        evaluateNodes = 0;
    }

    //for the algo
    int getNumberOfNodesEvaluate() {
        return this->evaluateNodes;
    }


    //return the reverse path
    vector<State<T> *> reversePath(State<T> *lastState, Searchable<T> *init) {

        vector<State<T> *> shortPath;

        while (!(lastState->Equals(init))) {
            shortPath.push_back(lastState);
            lastState = lastState->getCamefrom();
        }
        shortPath.push_back(lastState);
        return shortPath;
    }


    virtual Solution search(Searchable<T> searchable) = 0;


};

#endif //FINALPROJECTPART2_SEARCHERABSTRACT_H
