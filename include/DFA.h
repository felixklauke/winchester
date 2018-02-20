//
// Created by Felix Klauke on 20.02.18.
//

#ifndef WINCHESTER_DFA_H
#define WINCHESTER_DFA_H

#include <set>
#include <State.h>

class DFA {
public:
    explicit DFA(std::set<State> states, const std::set<char> &alphabet);

private:
    std::set<State> states;
    std::set<char> alphabet;
};

#endif //WINCHESTER_DFA_H
