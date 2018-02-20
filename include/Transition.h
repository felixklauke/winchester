//
// Created by Felix Klauke on 20.02.18.
//

#ifndef WINCHESTER_TRANSITION_H
#define WINCHESTER_TRANSITION_H


#include "State.h"

class Transition {
public:
    Transition(char input, State toState);

    bool IsAcceptingInput(char actualInput)const;

    State ToState()const;

private:
    State toState;
    char input;
};


#endif //WINCHESTER_TRANSITION_H
