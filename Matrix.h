
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
    State<pair<int, int>> initialState;
    vector<State<pair<int, int>>> goalState;
public:
    Matrix(vector<vector<double >> );

    State<pair<int, int>> *getInitialState() {
        return this->initialState;
    }

    //check whether its the goal or not
    bool isGoalState(State<pair<int, int>> *checkIfGoal) {
        // using std::find with vector and iterator:
        std::vector<State<pair<int, int>>>::iterator it;
        //check if the giving node is goal state(could be more than one goal state)
        int i;
        for (i = 0; i < this->goalState.size(); i++) {
            //check if the pair equals
            if ((this->goalState[i].getState().first == checkIfGoal->getState().first)
                && (this->goalState[i].getState().second == checkIfGoal->getState().second)) {
                return true;
            }
        }
        //if not found
        return false;
    }

    vector<State<pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *current, State<pair<int, int>> *goal){




    }
    vector< State<pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *state){

    }

};

#endif //FINALPROJECTPART2_MATRIX_H
