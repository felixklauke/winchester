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
    DFA(std::set<State> states, std::set<char> alphabet, std::map<State, std::set<Transition>> stateTransitions,
        State startState);

    bool ProcessInput(std::string input);

    void Reset();

    void AddTransition(const State &fromState, Transition transition);

    DFA BuildComplement();

    bool ValidateTransitionComplete();

    bool ValidateSufficientFinalStates();

    DFA *Minimize();

    void Visualize();

    const std::string EPSILON = "ɛ";

private:
    std::set<State> states;
    std::set<char> alphabet;
    std::map<State, std::set<Transition>> stateTransitions;
    State startState;
    State currentState;

    void DeleteUnreachableStates();
};

#endif //WINCHESTER_DFA_H
