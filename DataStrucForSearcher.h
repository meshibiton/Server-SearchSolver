////
//// Created by raph on 1/15/20.
////
//
//#ifndef FINALPROJECTPART2_DATASTRUCFORSEARCHER_H
//#define FINALPROJECTPART2_DATASTRUCFORSEARCHER_H
//#include "State.h"
//#include <vector>
//using namespace  std;
//
//template <class T>
//// An abstract class
//class DataStrucForSearcher
//{
//    // Data members of class
//protected:
//    vector<State<T> >  closedList ;
//public:
//
//    virtual State<T> *popFromCloseStuct(int socket){
//        State<T> *tampState = this->closedList.back();
//        closedList.pop_back();
//        return tampState;
//    }
//    virtual State<T> *popFromOpenStuct()= 0;
//    virtual  bool isEmptyClose(){
//        return closedList.empty();
//    }
//    virtual  bool isEmptyOpen()=0;
//
//    virtual  void pushCloseStruc(State<T> *state){
//        closedList.push_back(state);
//    }
//    virtual  void pushOpevStruc() = 0;
//
//    virtual bool findIfStateInClose(State<T> *state){
//        for (const auto& stateInClose : closedList)
//        {
//            if (stateInClose == state)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//
//        virtual ~DataStrucForSearcher(){};
//    /* Other members */
//};
//
//
//#endif //FINALPROJECTPART2_DATASTRUCFORSEARCHER_H
