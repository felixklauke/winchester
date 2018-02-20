//
// Created by Felix Klauke on 20.02.18.
//

#include "State.h"

State::State(int id, const std::string &label, bool isFinal) : isFinal(isFinal) {
    this->id = id;
    this->label = label;
    this->isFinal = isFinal;
}
