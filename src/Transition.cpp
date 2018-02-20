//
// Created by Felix Klauke on 20.02.18.
//

#include "Transition.h"

Transition::Transition(char input, State toState)
        : input(input), toState(toState) {
}

bool Transition::IsAcceptingInput(char actualInput) const {
    return input == actualInput;
}

State Transition::ToState() const {
    return toState;
}
