//
// Created by meshi on 14/01/2020.
//
#pragma once
#ifndef FINALPROJECTPART2_SEARCHABLE_H
#define FINALPROJECTPART2_SEARCHABLE_H

#include "State.h"
#include <vector>
template <class T>
class Searchable {
public:
    virtual State<T> * getInitialState() = 0;
    //check whether its the goal or not
    virtual bool isGoalState(State<T> *) = 0;
    virtual State<T> * getGoalState() = 0;
    //virtual vector<State<T>*> getAllPossibleState( State<T> *current,  State<T> *goal)=0;
    virtual vector< State<T> *> getAllPossibleState(State<T> *state) = 0;
    virtual ~Searchable(){}
};
#endif //FINALPROJECTPART2_SEARCHABLE_H
