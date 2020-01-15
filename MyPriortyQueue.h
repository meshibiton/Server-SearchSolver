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
    //push stat to the queue
    void push(State<T> *state) {
        priortyQueue.push(state);
    }
    //get state from the queue, and remove the state
    State<T> *pop() {
        State<T> *firstState = top();
        this->priortyQueue.pop();
        return firstState;
    }
    //get the top state
    State<T> *top() {
        State<T> *firstState = top();
        return this->priortyQueue.pop();
    }
    //check if the state is empty
    bool isEmpty() {
        return priortyQueue().empty();
    }

    //get the size of the queue
    unsigned long size() {
        return priortyQueue().size();
    }
    //find iter of the queue if does not find return nullptr
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
    // check if exist
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
