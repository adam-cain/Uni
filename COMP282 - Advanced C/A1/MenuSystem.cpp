#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>

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

    TuringMachine tm;

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
            tm = DenseTuringMachine(x, y);
        }
        else if (option == "2")
        {
            tm = SparseTuringMachine();
        }
        else if (option == "3")
        {
            cout << "What state do you wish to add?" << endl;
            string input;
            getline(cin, input);

            istringstream iss(input);

            int currState, currContent, nextState, nextContent;
            string direction;

            if (iss >> currState >> currContent >> nextState >> nextContent >> direction)
            {
                TuringMachineState newState(currState, currContent, nextState, nextContent, direction);
                tm.add(newState);
            }
        }
        else if (option == "4")
        {
            DenseTuringMachine dtm(tm.getAll(), maxState, maxContent);
            dtm.densify();
        }
        else if (option == "5")
        {
            int steps;
            cout << "How many steps do you wish to execute?" << endl;
            cin >> steps;

            for (int i = 0; i < steps; ++i)
            {
                int position = tape.getPosition();
                if (position < 0 || position >= tapeLength)
                {
                    cout << "In step " << steps << ", the position is " << position << ", but that is outside the tape" << endl;
                    break;
                }

                currentContent = tape.getContent();

                TuringMachineState *state = tm.find(currentState, currentContent);

                if (state == nullptr)
                {
                    cout << "In step" << steps << ", there is no Turing machine state with state " << currentState << " and content " << currentContent << endl;
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
            cout << "The current state is " << currentState << endl;
            cout << "The current position is " << tape.getPosition() << endl;
            cout << "The content of the tape is " << tape << endl;
            vector<TuringMachineState> vec = *tm.getAll();
            cout << "size of vec is " << vec.size() << endl;
            cout << "The states of the Turing machine has states:";

            for (auto s : vec)
            {
                cout << " <" << s << ">";
            }
        }
        else if (option == "Q" || option == "q")
        {
            break;
        }
    }
}
