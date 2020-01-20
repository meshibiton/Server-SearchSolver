//
// Created by meshi on 15/01/2020.
//
#pragma once

#ifndef FINALPROJECTPART2_STATE_H
#define FINALPROJECTPART2_STATE_H
using namespace std;

template<class T>
class State {
private:
    //the state represented by a string
    T state;
    double cost;//cost to reach this state(set by setter)
    State<T> *camefrom;//the state we came from to this state(setter)
public:
    State<T>(T state1,double cost1,State<T> *came1) {
        this->state=state1;
        this->cost=cost1;
        this->camefrom=came1;
    }

    T getState() const {
        return state;
    }
    bool operator==(State<T> s) {
        return (getState() == s.getState());
    }




    bool equals(State<T> *state1){
        return this->state == state1->state;
    }
    void setState(T state);

    void setCost(double cost);



    double getCost() const;

    State<T> *getCamefrom() const;

    void setCamefrom(State<T> *camefrom);
};

template<class T>
void State<T>::setState(T state1) {
    State::state = state1;
}

template<class T>
void State<T>::setCost(double cost1) {
    State::cost = cost1;
}

template<class T>
double State<T>::getCost() const {
    return cost;
}

template<class T>
State<T> *State<T>::getCamefrom() const {
    return camefrom;
}

template<class T>
void State<T>::setCamefrom(State<T> *camefrom1) {
    State::camefrom = camefrom1;
}


#endif //FINALPROJECTPART2_STATE_H
