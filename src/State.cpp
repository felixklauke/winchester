//
// Created by Felix Klauke on 20.02.18.
//

#include "State.h"

State::State(int id, const std::string &label, bool isFinal) : isFinal(isFinal) {
    this->id = id;
    this->label = label;
}

bool State::IsFinalState() const {
    return isFinal;
}

bool operator<(const State &left, const State &right) {
    return left.id < right.id;
}

std::string State::GetLabel() const {
    return label;
}
