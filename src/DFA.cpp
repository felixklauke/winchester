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
    std::cout << "Resetting current state." << std::endl;
    Reset();

    std::cout << "Checking state machine for transition completeness." << std::endl;
    auto transitionComplete = ValidateTransitionComplete();
    if (!transitionComplete) {
        std::cout << "Warning: The provided automaton is not transition complete!" << std::endl;
        return false;
    }

    std::cout << "Checking for sufficient final states (min 1)." << std::endl;
    bool sufficientFinalStates = ValidateSufficientFinalStates();
    if (!sufficientFinalStates) {
        std::cout << "A DFA has to have at least one final state!" << std::endl;
        return false;
    }

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
}

bool DFA::ValidateTransitionComplete() {
    for (const State &state : states) {
        auto &currentTransitions = stateTransitions.at(state);

        std::cout << "Checking transition completeness of state " << state.GetLabel() << std::endl;

        if (currentTransitions.size() != alphabet.size()) {
            std::cout << "State " << state.GetLabel() << " doesn't have enough transitions ("
                      << currentTransitions.size() << " of " << alphabet.size() << ")." << std::endl;
            return false;
        }

        for (const char &character : alphabet) {
            bool accepts = false;

            std::cout << "Checking for transition from " << state.GetLabel() << " With " << character << std::endl;

            for (const Transition &transition : currentTransitions) {
                if (transition.IsAcceptingInput(character)) {
                    accepts = true;
                }
            }

            if (!accepts) {
                std::cout << "The state " << state.GetLabel() + " doesn't have a transition for letter " << character
                          << "." << std::endl;
                return false;
            }
        }
    }

    return true;
}

bool DFA::ValidateSufficientFinalStates() {
    for (const State &state : states) {
        if (state.IsFinalState()) {
            return true;
        }
    }

    return false;
}

DFA DFA::BuildComplement() {
    auto complementStates = std::set<State>();

    for (const State &state : states) {
        complementStates.insert(State(state.GetId(), state.GetLabel(), !state.IsFinalState()));
    }

    return DFA(complementStates, alphabet, stateTransitions, startState);
}

DFA DFA::BuildComplement() {
    auto complementStates = std::set<State>();

    for (const State &state : states) {
        complementStates.insert(State(state.GetId(), state.GetLabel(), !state.IsFinalState()));
    }

    return DFA(complementStates, alphabet, stateTransitions, startState);
}
