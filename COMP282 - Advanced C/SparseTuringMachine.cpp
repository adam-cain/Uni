#include "SparseTuringMachine.h"
#include "TuringMachineState.h"
#include "DenseTuringMachine.h"
#include <algorithm>

// Define the find() method to search for a state with given x and y values
TuringMachineState *SparseTuringMachine::find(int state, int content)
{
    for (TuringMachineState &tm : states_)
    {
        if (tm.getCurrentState() == state && tm.getCurrentContent() == content)
        {
            return &tm;
        }
    }
    return nullptr; // Return nul lptr if no such state is found
}

// Define the add() method to add a new TuringMachineState to the vector
void SparseTuringMachine::add(TuringMachineState &s)
{
    states_.push_back(s);
}

// Define the getAll() method to return a pointer to the vector of all TuringMachinestates
std::vector<TuringMachineState> *SparseTuringMachine::getAll()
{
    return &states_;
}
