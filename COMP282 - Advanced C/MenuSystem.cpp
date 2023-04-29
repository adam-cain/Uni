#include "MenuSystem.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>

#include "TuringMachine.h"
#include "DenseTuringMachine.h"
#include "TuringTape.h"
#include "SparseTuringMachine.h"

using namespace std;

// Function to display the menu
void displayMenu()
{
    cout << "1. Create dense Turing machine" << endl;
    cout << "3. Add state to Turing machine" << endl;
    cout << "5. Execute Turing machine" << endl;
    cout << "6. Output current information" << endl;
    cout << "Write q or Q to quit" << endl;
    cout << "Enter Option: ";
}

int main()
{
    int tapeLength = 0; // Tape length provided by user
    string option;      // User input for menu option
    int currentContent = 0, currentState = 0;
    int 
    maxState = std::numeric_limits<int>::max(), 
    maxContent = std::numeric_limits<int>::max();

    cout << "How long should the tape be?";
    cin >> tapeLength;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore rest of the input buffer

    // Create a Turing machine object
    TuringMachine tm;

    TuringTape tape(tapeLength);
    // Main menu loop
    while (true)
    {
        displayMenu();
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore rest of the input buffer

        if (option == "1")
        {
            int x, y;
            cout << "What is the maximum state and what is the maximum content?";
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
            cout << "What state do you wish to add?";
            std::string input;
            std::getline(std::cin, input);

            std::istringstream iss(input);

            int currState, currContent, nextState, nextContent;
            std::string direction;

            if (iss >> currState >> currContent >> nextState >> nextContent >> direction)
            {
                TuringMachineState state = TuringMachineState(currState, currContent, nextState, nextContent, direction);
                tm.add(state);
            }
        }
        else if (option == "4")
        {
            DenseTuringMachine dtm(tm.getAll(),maxState,maxContent);
            dtm.densify();
        }
        else if (option == "5")
        {
            int steps;
            cout << "How many steps do you wish to execute?";
            cin >> steps;

            for (int i = 0; i < steps; ++i)
            {

                int position = tape.getPosition();
                if (position < 0 || position >= tapeLength)
                {
                    cout << "In step " << steps << ", the position is " << position << ", but that is outside the tape";
                    break;
                }

                currentContent = tape.getContent();

                TuringMachineState *state = tm.find(currentState, currentContent);

                if (state == nullptr)
                {
                    cout << "In step" << steps << ", there is no Turing machine state with state " << currentState << " and content " << currentContent;
                    break;
                }

                currentState = state->getNextState();
                tape.setContent(state->getNextContent());
                if(state->getMoveDirection() == "->"){
                    tape.moveRight();
                }else if(state->getMoveDirection() == "<-"){
                    tape.moveLeft();
                }
            }
        }
        else if (option == "6")
        {
            cout << "The current state is "<< currentState <<". The current content is "<< tape.getContent() <<". The current position is x" << endl;
            cout << "The content of the tape is " << tape << endl;
            cout << "The states of the Turing machine is " << tm.getAll();
        }
        else if (option == "Q" || option == "q")
        {
            cout << "Quitting..." << endl;
            break;
        }
    }

    return 0;
}
