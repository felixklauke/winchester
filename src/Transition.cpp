//
// Created by Felix Klauke on 20.02.18.
//

#include "Transition.h"

Transition::Transition(char input, State toState)
        : input(input), toState(toState) {
    this->input = input;
    this->toState = toState;
}