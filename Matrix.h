

//
// Created by meshi on 15/01/2020.
//
#pragma once
#ifndef FINALPROJECTPART2_MATRIX_H
#define FINALPROJECTPART2_MATRIX_H



#include "Searchable.h"


using namespace std;

class Matrix : public Searchable<pair<int, int>> {
private:
    State<pair<int, int>> *initialState;
    State<pair<int, int>> *goalState;
    vector<vector<double >> matrix;
    int numRows;
    int numColumn;
public:
    Matrix(const vector<vector<double >> &matrix1) {
        //num of vectors in the vector of vectores
        this->numRows = matrix1.size() -2;
        //num of element in each vector
        this->numColumn = matrix1[0].size();
        //first we take the values pair of start and end points,means row and column
        pair<int, int> PairInitialState = {(int) matrix1[numRows ][0], (int) matrix1[numRows ][1]};
        pair<int, int> PairGoalState = {(int) matrix1[numRows + 1][0], (int) matrix1[numRows + 1][1]};
        //we save the cost in var which is exactly the value in the cell in the matrix
        double costGoal = matrix1[PairGoalState.first][PairGoalState.second];
        double costInitial = matrix1[PairInitialState.first][PairInitialState.second];
        //create the object of goal and initial state
        this->goalState = new State<pair<int, int>>(PairGoalState, costGoal , nullptr);
        this->initialState = new State<pair<int, int>>(PairInitialState, costInitial, nullptr);
        this->matrix = matrix1;
    }

    //check whether its the goal or not
    bool isGoalState(State<pair<int, int>> *checkIfGoal);
    State<pair<int,int>>* getGoalState();
//    vector<State<pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *current, State<pair<int, int>> *goal) {
//
//
//    }

    vector<State<pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *state);

    State< pair<int, int> >* getInitialState() {
        return this->initialState;
    }
};

#endif //FINALPROJECTPART2_MATRIX_H
