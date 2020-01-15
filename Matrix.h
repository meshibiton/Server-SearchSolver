
Matrix::Matrix() {}
//
// Created by meshi on 15/01/2020.
//

#ifndef FINALPROJECTPART2_MATRIX_H
#define FINALPROJECTPART2_MATRIX_H

#include <vector>
#include "Searchable.h"
#include "State.h"
#include <algorithm>

using namespace std;

class Matrix : public Searchable<pair<int, int>> {
private:
    State<pair<int, int>> *initialState;
    State<pair<int, int>> *goalState;
    vector<vector<double >> matrix;
    int numRows;
    int numColumn;
public:
    Matrix(const vector<vector<double >> &matrix) {
        //num of vectors in the vector of vectores
        this->numRows = matrix.size()-2;
        //num of element in each vector
        this->numColumn=matrix[0].size();
        //first we take the values pair of start and end points,means row and column
        pair<int, int> PairInitialState = {(int) matrix[numRows +1][0], (int) matrix[numRows + 1][1]};
        pair<int, int> PairGoalState = {(int) matrix[numRows +2][0], (int) matrix[numRows +2][1]};
        //we save the cost in var which is exactly the value in the cell in the matrix
        double costGoal = matrix[PairGoalState.first][PairGoalState.second];
        double costInitial = matrix[PairInitialState.first][PairInitialState.second];
        //create the object of goal and initial state
        this->goalState = new State<pair<int, int>>(PairGoalState, , nullptr);
        this->initialState = new State<pair<int, int>>(PairInitialState, costInitial, nullptr);
        this->matrix = matrix;
    }

    //check whether its the goal or not
    bool isGoalState(State<pair<int, int>> *checkIfGoal) {
        //check if the giving node is goal state(in this case couldnt be more than one)
        //check if the pair equals
        if (this->goalState->getState().first == checkIfGoal->getState().first &&
            this->goalState->getState().second == checkIfGoal->getState().second) {
            return true;
        } else {
            //if not found
            return false;
        }

    }

//    vector<State<pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *current, State<pair<int, int>> *goal) {
//
//
//    }

    vector<State<pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *state) {
        int currentRowState=state->getState().first;
        int currentColumnState=state->getState().second;
        vector<State<pair<int, int>> *> possibleStates;
        //check whether you can go up
        if(currentRowState>0){
            //create new possible state
            State<pair<int, int>>* up = new State<pair<int, int>>(make_pair(currentRowState - 1,
                    currentColumnState),state->getCost() + matrix[currentRowState - 1][currentColumnState],state);
            possibleStates.push_back(up);
        }
        //check whether you can go down
        if(currentRowState<this->numRows-1){
            State<pair<int, int>>* down = new State<pair<int, int>>(make_pair(currentRowState +1,
                    currentColumnState),state->getCost() + matrix[currentRowState + 1][currentColumnState],state);
            possibleStates.push_back(down);
        }
        //check whether you can go left
        if(currentColumnState>0){
            State<pair<int, int>>* left = new State<pair<int, int>>(make_pair(currentRowState,
             currentColumnState-1),state->getCost() + matrix[currentRowState][currentColumnState-1],state);
            possibleStates.push_back(left);
        }
        //check whether you can go right
        if(currentColumnState<numColumn-1){
            State<pair<int, int>>* right = new State<pair<int, int>>(make_pair(currentRowState,
             currentColumnState+1),state->getCost() + matrix[currentRowState][currentColumnState+1],state);
            possibleStates.push_back(right);
        }
        return possibleStates;
    }

};

#endif //FINALPROJECTPART2_MATRIX_H
