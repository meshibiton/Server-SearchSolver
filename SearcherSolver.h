//
// Created by meshi on 14/01/2020.
//

#ifndef FINALPROJECTPART2_SEARCHERSOLVER_H
#define FINALPROJECTPART2_SEARCHERSOLVER_H

#include <vector>
#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"

using namespace  std;
template <class T, class Solution>
class SearcherSolver: public Solver<string,vector<vector<double >>>{
private:
    Searcher<T,Solution> *searcher;
public:
    SearcherSolver() {
        this->searcher=;
        // Searcher<pair<int,int>,vector<State<pair<int,int>>*>> *searcher=new searcher();
        //need func that will return the best algo
    }

    string solve(vector<vector<double >> problem){
        Searchable<pair<int,int>>* searchable=new Matrix(problem);
        vector<State<pair<int, int> > *> solution = this->searcher->search(searchable);


    }
};




#endif //FINALPROJECTPART2_SEARCHERSOLVER_H
