//
// Created by Felix Klauke on 20.02.18.
//

#include <set>
#include <DFA.h>

DFA::DFA(std::set<State> states, const std::set<char> &alphabet) : alphabet(alphabet), states(states) {
    this->alphabet = alphabet;
    this->states = states;
}
