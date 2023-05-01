#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm>

#include "MenuSystem.h"
#include "TuringMachine.h"
#include "DenseTuringMachine.h"
#include "TuringTape.h"
#include "SparseTuringMachine.h"

using namespace std;

void MenuSystem::displayMenu()
{
    cout << "1. Create dense Turing machine" << endl;
    cout << "2. Create sparse Turing machine" << endl;
    cout << "3. Add state to Turing machine" << endl;
    cout << "4. Compact Turing machine" << endl;
    cout << "5. Execute Turing machine" << endl;
    cout << "6. Output current information" << endl;
    cout << "Write q or Q to quit" << endl;
    cout << "Enter Option " << endl;
}

void MenuSystem::menu()
{
    int tapeLength = 0;
    string option;
    int currentContent = 0, currentState = 0;
    int
        maxState = numeric_limits<int>::max(),
        maxContent = numeric_limits<int>::max();

    int totalSteps = 0;

    TuringMachine *tm = nullptr;

    cout << "How long should the tape be?" << endl;
    cin >> tapeLength;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    TuringTape tape(tapeLength);

    while (true)
    {
        displayMenu();
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (option == "1")
        {
            int x, y;
            cout << "What is the maximum state and what is the maximum content?" << endl;
            cin >> x;
            cin >> y;
            DenseTuringMachine *dtm = new DenseTuringMachine(x, y);
            tm = dtm;
        }
        else if (option == "2")
        {
            SparseTuringMachine *stm = new SparseTuringMachine();
            tm = stm;
        }
        else if (option == "3")
        {
            cout << "What state do you wish to add?" << endl;
            string line;
            getline(cin, line);

            stringstream ss(line);

            int currState, currContent, nextState, nextContent;
            string direction;

            ss >> currState >> currContent >> nextState >> nextContent >> direction;

            TuringMachineState newState(currState, currContent, nextState, nextContent, direction);
            tm->add(newState);
        }
        else if (option == "4")
        {
            vector<TuringMachineState> *vec = tm->getAll();

            vector<TuringMachineState *> states;

            for (auto &state : *vec)
            {
                states.push_back(&state);
            }

            std::sort(states.begin(), states.end(),
                      [](TuringMachineState *state1, TuringMachineState *state2)
                      {
                          return state1->getCurrentState() < state2->getCurrentState();
                      });

            int previousState = -1;
            int currentIndex = -1;
            for (size_t i = 0; i < states.size(); i++)
            {
                if (states[i]->getCurrentState() != previousState)
                {
                    // New currentState value, increment currentIndex
                    currentIndex++;
                }
                previousState = states[i]->getCurrentState();
                states[i]->setCurrentState(currentIndex);
            }

            std::sort(states.begin(), states.end(),
                      [](TuringMachineState *state1, TuringMachineState *state2)
                      {
                          return state1->getCurrentContent() < state2->getCurrentContent();
                      });

            int previousContent = -1;
            int currentContentIndex = -1;
            for (size_t i = 0; i < states.size(); i++)
            {
                if (states[i]->getCurrentContent() != previousContent)
                {
                    // New currentContent value, increment currentContentIndex
                    currentContentIndex++;
                }
                previousContent = states[i]->getCurrentContent();

                states[i]->setCurrentContent(currentContentIndex);
            }

            std::sort(states.begin(), states.end(),
                      [](TuringMachineState *state1, TuringMachineState *state2)
                      {
                          return state1->getNextState() < state2->getNextState();
                      });

            int previousNextState = -1;
            int currentNextStateIndex = -1;
            for (size_t i = 0; i < states.size(); i++)
            {
                if (states[i]->getNextState() != previousNextState)
                {
                    // New nextState value, increment currentNextStateIndex
                    currentNextStateIndex++;
                }
                previousNextState = states[i]->getNextState();

                states[i]->setNextState(currentNextStateIndex);
            }

            std::sort(states.begin(), states.end(),
                      [](TuringMachineState *state1, TuringMachineState *state2)
                      {
                          return state1->getNextContent() < state2->getNextContent();
                      });

            int previousNextContent = -1;
            int currentNextContentIndex = -1;
            for (size_t i = 0; i < states.size(); i++)
            {
                if (states[i]->getNextContent() != previousNextContent)
                {
                    // New nextContent value, increment currentIndex
                    currentNextContentIndex++;
                }
                previousNextContent = states[i]->getNextContent();
                states[i]->setNextContent(currentNextContentIndex);
            }
        }
        else if (option == "5")
        {
            int steps;
            cout << "How many steps do you wish to execute?" << endl;
            cin >> steps;

            for (int i = 1; i <= steps; ++i)
            {
                totalSteps++;
                int position = tape.getPosition();
                if (position < 0 || position >= tapeLength)
                {
                    cout << "In step " << totalSteps << ", the position is " << position << ", but that is outside the tape." << endl;
                    break;
                }

                currentContent = tape.getContent();

                TuringMachineState *state = tm->find(currentState, currentContent);

                if (state == nullptr)
                {
                    cout << "In step " << totalSteps << ", there is no Turing machine state with state " << currentState << " and content " << currentContent << endl;
                    break;
                }

                currentState = state->getNextState();
                tape.setContent(state->getNextContent());
                if (state->getMoveDirection() == "->")
                {
                    tape.moveRight();
                }
                else if (state->getMoveDirection() == "<-")
                {
                    tape.moveLeft();
                }
            }
        }
        else if (option == "6")
        {
            cout << "The current state is " << currentState << "." << endl;
            cout << "The current position is " << tape.getPosition() << "." << endl;
            cout << "The content of the tape is " << tape << "." << endl;
            cout << "The turing machine has states:";
            vector<TuringMachineState> vec = *tm->getAll();
            for (auto s : vec)
            {
                cout << " <" << s << ">";
            }
            cout << endl;
        }
        else if (option == "Q" || option == "q")
        {
            break;
        }
    }
}
