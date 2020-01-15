//
// Created by raph on 1/15/20.
//

#ifndef FINALPROJECTPART2_SEARCHERABSTRACT_H
#define FINALPROJECTPART2_SEARCHERABSTRACT_H

#include "Searcher.h"
#include "MyPriortyQueue.h"
#include "State.h"
#include "Searchable.h"
using namespace  std;
    class SearcherAbstract: public Searcher <class T, class Solution>{
    private:
        MyPriorityQueue<State<T>> openList;
        int evaluateNodes;


    public:
        SearcherAbstract() {
            openList = new MyPriorityQueue<State<T>>();
            evaluateNodes = 0;
        }
        int openListSize(){
            return openList.size();
        }
        int getNumberOfevaluateNodes(){
            return this->evaluateNodes;
        }

        virtual Solution search(Searchable<T> searchable) = 0;

    protected:
        State<T> popOpenList(){
            evaluateNodes++;
            return openList.pop();
        }

    };
#endif //FINALPROJECTPART2_SEARCHERABSTRACT_H
