//
// Created by raph on 1/15/20.
//

#ifndef FINALPROJECTPART2_MYPRIORTYQUEUE_H
#define FINALPROJECTPART2_MYPRIORTYQUEUE_H

#include "State.h"
#include <vector>
#include "DataStrucForSearcher.h"
#include <queue>
#include "State.h"

using namespace std;

//6.4 - object functions
struct comperFuncState {
    template<class T>
    bool operator()(State<T> *stateCmp, State<T> *otherState) const {
        return stateCmp->getCost() > stateCmp->getCost();

    }
};

template<class T>
// An abstract class
class MyPriorityQueue  {
    // Data members of class
private:
    //// Syntax to create a min heap for priority queue
    //priority_queue <type, vector<type>, loading func for min >>
    priority_queue<State<T> *, vector<State<T> *>, comperFuncState()> priortyQueue;
public:
    void push(State<T> *state) {
        priortyQueue.push(state);
    }

    State<T> *pop() {
        State<T> *firstState = top();
        this->priortyQueue.pop();
        return firstState;
    }

    State<T> *top() {
        State<T> *firstState = top();
        return this->priortyQueue.pop();
    }

    bool isEmpty() {
        return priortyQueue().empty();
    }

    unsigned long size() {
        return priortyQueue().size();
    }

    State<T> *find(State<T> *state) {
        vector<State<T> *> vecStates;
        State<T> *tempState;
        State<T> *returnState = nullptr;

        //remove all the state from the queue and check if the state exist
        while (!isEmpty()) {
            tempState = this->pop();
            vecStates.push_back(tempState);
            if (*tempState == *state) {
                returnState = state;
                break;
            }
        }
        //return the queue to the first state
        for (const auto &state : vecStates) {
            this->push(state);
        }
        return returnState;
    }
    void erase(State<T>* state){
        vector<State<T> *> vecStates;
        State<T> *tempState;
        //pop all the state from the queue and check if the state exist
        while (!isEmpty()) {
            tempState = this->pop();
            if (*tempState == *state) {
                free(state);
                delete(state);
                break;
            } else {
                vecStates.push_back(tempState);
            }
        }
        //return the queue to the first state
        for (const auto &state : vecStates) {
            this->push(state);
        }
    }
    bool isExist(State<T>* state){
        State<T> *tempState;
        tempState=this->find(state);
        if (tempState == nullptr){
            return false;
        }
        return true;
    }
};

#endif //FINALPROJECTPART2_MYPRIORTYQUEUE_H
