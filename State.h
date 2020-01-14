//
// Created by meshi on 15/01/2020.
//

#ifndef FINALPROJECTPART2_STATE_H
#define FINALPROJECTPART2_STATE_H
using namespace std;

#include <algorithm>

template<class T>
class State {
private:
    T state;//the state represented by a string
    double cost;//cost to reach this state(set by setter)
    State<T> camefrom;//the state we came from to this state(setter)
public:
    State(T state1) {
        this->state = state1;
    }

    T getState() const {
        return state;
    }

    bool Equals(State<T> s) {//we overload objects Equals method
        return equal(this->state, s.state);
    }

    void setState(T state);

    void setCost(double cost);

    void setCamefrom(const State<T> &camefrom);
};

template<class T>
void State<T>::setState(T state) {
    State::state = state;
}

template<class T>
void State<T>::setCost(double cost) {
    State::cost = cost;
}

template<class T>
void State<T>::setCamefrom(const State<T> &camefrom) {
    State::camefrom = camefrom;
}

#endif //FINALPROJECTPART2_STATE_H
