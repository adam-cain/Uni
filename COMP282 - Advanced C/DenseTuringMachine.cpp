#include "DenseTuringMachine.h"

DenseTuringMachine::DenseTuringMachine(int state, int content) {
    maxCurrentState_ = state;
    maxCurrentContent_ = content;
    states_.reserve(state * content); // Reserve space for the states_
    
}

TuringMachineState* DenseTuringMachine::find(int state, int content) {
    // Iterate through the states_ and find the one with the given current state and current content
    for (TuringMachineState& tm : states_) {
        if (tm.getCurrentState() == state && tm.getCurrentContent() == content) {
            return &tm;
        }
    }
    return nullptr; // Return nul lptr if no such state is found
}

bool DenseTuringMachine::isWithinBounds(int state, int content) {
    // Check if state and content are within the upper bounds
    if (state <= maxCurrentState_ && content <= maxCurrentContent_) {
        return true;
    } else {
        return false;
    }
}

void DenseTuringMachine::add(TuringMachineState& s) {
    // Add the given state to the vector of states_
    if(isWithinBounds(s.getCurrentState(), s.getCurrentContent())){
       states_.push_back(s);
    }
}

std::vector<TuringMachineState>* DenseTuringMachine::getAll() {
    // Return a pointer to the vector of all TuringMachinestates_
    return &states_;
}
