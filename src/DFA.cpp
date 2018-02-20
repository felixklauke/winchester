//
// Created by Felix Klauke on 20.02.18.
//

#include <set>
#include <DFA.h>

DFA::DFA(std::set<State> states, std::set<char> alphabet, std::map<State, std::set<Transition>> stateTransitions,
         State startState)
        : alphabet(std::move(alphabet)), states(std::move(states)), stateTransitions(std::move(stateTransitions)),
          currentState(startState), startState(startState) {
}

bool DFA::ProcessInput(std::string input) {
    Reset();

    for (char &c : input) {
        auto currentTransitions = stateTransitions.at(this->currentState);

        for (const Transition &transition : currentTransitions) {
            if (transition.IsAcceptingInput(c)) {
                currentState = transition.ToState();
            }
        }
    }

    return currentState.IsFinalState();
}

void DFA::Reset() {
    currentState = startState;
}

void DFA::AddTransition(const State &fromState, Transition transition) {
    if (stateTransitions.count(fromState) == 0) {
        stateTransitions.insert(std::pair<State, std::set<Transition>>(fromState, std::set<Transition>()));
    }

    auto transitions = stateTransitions.at(fromState);
    transitions.insert(transition);
}
