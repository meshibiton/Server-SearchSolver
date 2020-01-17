//
// Created by meshi on 14/01/2020.
//
#pragma once
#ifndef FINALPROJECTPART2_SEARCHERSOLVER_H
#define FINALPROJECTPART2_SEARCHERSOLVER_H


#include "Matrix.h"
#include "Searcher.h"
#include "BestFirstSearcher.h"


using namespace  std;
//template <class T, class Solution>
class SearcherSolver: public Solver<string,vector<vector<double >>>{
private:
  //  Searcher<pair<int, int>, vector<State<pair<int, int> > *>> *searcher;
public:
//    SearcherSolver() {
//        //need func that will return the best algo,now its best
//        this->searcher = new BestFirstSearcher<pair<int, int>>();
////        this->searcher = new DFSSearcher<pair<int, int>>();
//    }


    string solve(vector<vector<double >> problem) {
        //create the problem we want, this is for matrix problem
        Searcher<pair<int, int>, vector<State<pair<int, int> > *>> *searcher = new BestFirstSearcher<pair<int, int>>();
        Searchable<pair<int, int>> *searchable = new Matrix(problem);
        vector<State<pair<int, int> > *> solution = searcher->search(searchable);
        if (solution.size() == 0) {
            return "No path";

        }
        string solutionString = FromVecToString(solution);
        return solutionString;
    }
    string FromVecToString(vector<State<pair<int, int> > *> solution) {
        string solutionString = "";
        int i;
        for (i = 0; i < solution.size() - 1; i++) {
            pair<int, int> curPlace = solution[i]->getState();
            pair<int, int> nextMove = solution[i + 1]->getState();
            string cost = to_string((int) solution[i + 1]->getCost());
            //if the row number got heigher that means we go down in the matrix
            if (nextMove.first > curPlace.first) {
                solutionString = solutionString + "Down";
            }
            //if the column got heigher that means we go right
            if (nextMove.second > curPlace.second) {
                solutionString = solutionString + "Right";
            }
            //if the row became less that means we go up
            if (nextMove.first < curPlace.first) {
                solutionString = solutionString + "Up";
            }
            //if the column became less that means we go left
            if (nextMove.first < curPlace.first) {
                solutionString = solutionString + "Left";
            }
            solutionString = solutionString + "(" + cost + ")";
            //add comma between each other
            if (i != solution.size() - 2) {
                solutionString = solutionString + ",";
            }
        }
        return solutionString;
    }
};




#endif //FINALPROJECTPART2_SEARCHERSOLVER_H
