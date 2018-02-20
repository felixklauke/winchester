//
// Created by Felix Klauke on 20.02.18.
//

#ifndef WINCHESTER_DFA_H
#define WINCHESTER_DFA_H

#include <set>
#include <State.h>
#include <map>
#include <Transition.h>

class DFA {
public:
    explicit DFA(std::set<State> states, const std::set<char> &alphabet, std::map<State, Transition> stateTransitions);

    bool ProcessInput(std::string input);

private:
    std::set<State> states;
    std::set<char> alphabet;
    std::map<State, Transition> stateTransitions;
};

#endif //WINCHESTER_DFA_H
