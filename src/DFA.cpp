//
// Created by Felix Klauke on 20.02.18.
//

#include <set>
#include <DFA.h>
#include <iostream>

DFA::DFA(std::set<State> states, std::set<char> alphabet, std::map<State, std::set<Transition>> stateTransitions,
         State startState)
        : alphabet(std::move(alphabet)), states(std::move(states)), stateTransitions(std::move(stateTransitions)),
          currentState(startState), startState(startState) {
}

bool DFA::ProcessInput(std::string input) {
    Reset();

    for (char &c : input) {
        std::cout << "Working on " << c << " with current state " << currentState.GetLabel() << std::endl;

        auto currentTransitions = stateTransitions.at(currentState);

        std::cout << "Found transitions: " << currentTransitions.size() << std::endl;

        for (const Transition &transition : currentTransitions) {
            if (transition.IsAcceptingInput(c)) {
                currentState = transition.ToState();
            }
        }

        std::cout << "Current state: " << currentState.GetLabel() << std::endl;
    }
    return currentState.IsFinalState();
}

void DFA::Reset() {
    currentState = startState;
}

void DFA::AddTransition(const State &fromState, Transition transition) {
    if (stateTransitions.count(fromState) == 0) {
        std::cout << "No transition set until now for: " << fromState.GetLabel() << std::endl;
        stateTransitions.insert(std::pair<State, std::set<Transition>>(fromState, std::set<Transition>()));
    }

    auto &transitions = stateTransitions.at(fromState);
    transitions.insert(transition);

    std::cout << "LOL: " << transitions.size() << std::endl;
}
