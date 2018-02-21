//
// Created by Felix Klauke on 20.02.18.
//

#ifndef WINCHESTER_STATE_H
#define WINCHESTER_STATE_H

#include <string>

class State {
public:
    State(int id, const std::string &label, bool isFinal);

    bool IsFinalState();

    std::string GetLabel() const;

    friend bool operator<(const State &left, const State &right);

private:
    int id;
    std::string label;
    bool isFinal;
};


#endif //WINCHESTER_STATE_H
