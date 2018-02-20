//
// Created by Felix Klauke on 20.02.18.
//

#include <set>
#include <DFA.h>

DFA::DFA(std::set<State> states, std::set<char> alphabet, std::map<State, Transition> stateTransitions,
         const State &startState)
        : alphabet(std::move(alphabet)), states(std::move(states)), stateTransitions(std::move(stateTransitions)),
          currentState(startState), startState(startState) {
}

bool DFA::ProcessInput(std::string input) {
    Reset();
    return false;
}

void DFA::Reset() {
    currentState = startState;
}
