//
// Created by meshi on 14/01/2020.
//
#pragma once
#ifndef FINALPROJECTPART2_SEARCHERSOLVER_H
#define FINALPROJECTPART2_SEARCHERSOLVER_H


#include "Matrix.h"
#include "Searcher.h"
#include "BestFirstSearcher.h"
#include "BFSSearcher.h"
#include "DFSSearcher.h"
#include "AStarSearcher.h"



using namespace  std;
//template <class T, class Solution>
class SearcherSolver: public Solver<string,vector<vector<double >>>{

public:

    string solve(vector<vector<double >> problem) {
        //create the problem we want, this is for matrix problem
        Searcher<pair<int, int>, vector<State<pair<int, int> > *>> *searcher = new AStarSearcher <pair<int, int>>();
        //create data base that contain all the details for solving the problem
        Searchable<pair<int, int>> *searchable = new Matrix(problem);
        //after data Analysis of the four algorithms we find out that A*  running fastest of all
        vector<State<pair<int, int> > *> solution = searcher->search(searchable);
        //print the num of the node we visited will the algorithm run
        cout <<"Total visited nodes: "+  to_string(searcher->getNumOfNodesEvaluated())<< endl;
        if (solution.size() == 0) {
            return "No path";

        }
        //translate the vector state to string vec with information on the path of the algorithm
        string solutionString = FromVecToString(solution);
        return solutionString;
    }
    string FromVecToString(vector<State<pair<int, int> > *> solution) {
        string solutionString = "";
        unsigned  i;
        for (i = 0; i < solution.size()-1 ; i++) {
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
            if (nextMove.second < curPlace.second) {
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
