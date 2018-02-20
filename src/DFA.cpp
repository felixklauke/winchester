//
// Created by Felix Klauke on 20.02.18.
//

#include <set>
#include <DFA.h>

DFA::DFA(const std::set<char> &alphabet, std::set<State> states) : alphabet(alphabet), states(states) {
    this->alphabet = alphabet;
    this->states = states;
}
