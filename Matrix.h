

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
        this->numRows = matrix.size() - 2;
        //num of element in each vector
        this->numColumn = matrix[0].size();
        //first we take the values pair of start and end points,means row and column
        pair<int, int> PairInitialState = {(int) matrix[numRows + 1][0], (int) matrix[numRows + 1][1]};
        pair<int, int> PairGoalState = {(int) matrix[numRows + 2][0], (int) matrix[numRows + 2][1]};
        //we save the cost in var which is exactly the value in the cell in the matrix
        double costGoal = matrix[PairGoalState.first][PairGoalState.second];
        double costInitial = matrix[PairInitialState.first][PairInitialState.second];
        //create the object of goal and initial state
        this->goalState = new State<pair<int, int>>(PairGoalState, , nullptr);
        this->initialState = new State<pair<int, int>>(PairInitialState, costInitial, nullptr);
        this->matrix = matrix;
    }

    //check whether its the goal or not
    bool isGoalState(State<pair<int, int>> *checkIfGoal);

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
