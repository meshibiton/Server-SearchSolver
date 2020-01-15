//
// Created by meshi on 16/01/2020.
//
#include "Matrix.h"

bool Matrix::isGoalState(State<pair<int, int>> *checkIfGoal) {
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

vector<State<pair<int, int>> *>Matrix::getAllPossibleState(State<pair<int, int>>*state) {
    int currentRowState = state->getState().first;
    int currentColumnState = state->getState().second;
    vector<State<pair<int, int>> *>
            possibleStates;
    //check whether you can go up
    if (currentRowState > 0) {
    //create new possible state
        State<pair<int, int>> *up = new State<pair<int, int>>(make_pair(currentRowState - 1,
          currentColumnState), state->getCost() + matrix[currentRowState - 1][currentColumnState],state);
        possibleStates.push_back(up);
    }
    //check whether you can go down
    if (currentRowState < this->numRows - 1) {
        State<pair<int, int>> *down = new State<pair<int, int>>(make_pair(currentRowState + 1,
         currentColumnState), state->getCost() + matrix[currentRowState +1][currentColumnState], state);
        possibleStates.push_back(down);
    }
    //check whether you can go left
    if (currentColumnState > 0) {
        State<pair<int, int>> *left = new State<pair<int, int>>(make_pair(currentRowState, currentColumnState - 1), state->getCost() +
         matrix[currentRowState][ currentColumnState -  1], state);
        possibleStates.push_back(left);
    }
    //check whether you can go right
    if (currentColumnState < numColumn - 1) {
        State<pair<int, int>> *right = new State<pair<int, int>>(make_pair(currentRowState,currentColumnState + 1), state->getCost() +
          matrix[currentRowState][ currentColumnState +1], state);
        possibleStates.push_back(right);
    }
    return possibleStates;

}

