//
// Created by raph on 1/17/20.
//

#ifndef FINALPROJECTPART2_BFSSEARCHER_H
#define FINALPROJECTPART2_BFSSEARCHER_H


#include "SearcherAbstract.h"

using namespace std;
#include <queue>
template <class T>
// An abstract class
class BFSSearcher: SearcherAbstract{
private:

    queue<State<T>*> openList;

    int openListSize() {
        return (int) openList.size();
    }

    bool openContains(State<T> *state) {

        return  isExist(*state);
    }
    State<T>* popOpenList(){
        return  openList.pop();
    }

    void addOpenList(State<T> *s){
        this->evaluateNodes++;
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
        this->evaluateNodes = 0;
        vector<State<T>*> closeVec;
        //add the init to the queue
        this->addOpenList(searchable->getInitialState());
        //while ther are nod in the queue continue
        while (this->openListSize() > 0) {
            State<T> *curState = this->popOpenList();
            //check if exist in the visited nod
            if (!this->containsClose(closeVec, curState))
                closeVec.push_back(curState);

            if (searchable->isGoalState(curState))
                return this->reversePath(curState, searchable->getInitialState());
            //return the all Neighbors
            vector<State<T>*> statesVec = searchable->getAllPossibleStates(curState);
            for (State<T> *s : statesVec) {
                if (!this->containsClose(closeVec, s) && !this->openContains(s)) {
                    this->addOpenList(s);
                }
            }
        }
        return nullptr;
    }





    ~BFSSearcher(){}


};




#endif //FINALPROJECTPART2_BFSSEARCHER_H
