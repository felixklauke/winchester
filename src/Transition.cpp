//
// Created by Felix Klauke on 20.02.18.
//

#include "Transition.h"

Transition::Transition(char input, State toState)
        : input(input), toState(std::move(toState)) {
}

bool Transition::IsAcceptingInput(char actualInput) const {
    return input == actualInput;
}

State Transition::ToState() const {
    return toState;
}

bool operator<(const Transition &left, const Transition &right) {
    return left.input < right.input;
}

char Transition::GetInput() const {
    return input;
}
