#include "MenuSystem.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "TuringMachine.h"
#include "DenseTuringMachine.h"
#include "TuringTape.h"

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
    int tapeLength = 0;   // Tape length provided by user
    string option;        // User input for menu option

    // Display initial message and wait for input of an int for tape length
    cout << "How long should the tape be?";
    cin >> tapeLength;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore rest of the input buffer

    // Create a Turing machine object
    TuringMachine dtm;
    TuringTape tape(tapeLength);
    // Main menu loop
    while (true)
    {
        displayMenu();
        cin >> option;
        // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore rest of the input buffer

        if (option == "1")
        {
            int x, y;
            cout << "What is the maximum state and what is the maximum content?";
            cin >> x;
            cin >> y;
            dtm = DenseTuringMachine(x, y);
        }
        else if (option == "2")
        {
            // TODO: Later Task
        }
        else if (option == "3")
        {
            cout << "What state do you wish to add?";
            std::string input;
            std::getline(std::cin, input);

            std::istringstream iss(input);

            int currentState, currentContent, nextState, nextContent;
            std::string direction;

            if (iss >> currentState >> currentContent >> nextState >> nextContent >> direction)
            {
                TuringMachineState state = TuringMachineState(currentState, currentContent, nextState, nextContent, direction);
                dtm.add(state);
            }
        }else if (option == "4")
        {
            // TODO: Later Task
        }
        else if (option == "5")
        {
            int steps;
            cout << "How many steps do you wish to execute?";
            cin >> steps;
            
        for (int i = 0; i < steps; ++i) {

            int position = tape.getPosition();
            if (position < 0 || position >= tapeLength) {
                cout << "In step "<< steps <<", the position is "<< position <<", but that is outside the tape";
                break;
            }

            

            int state = tape.getPosition();
            int content = tape.getContent();
            
            if(){
                cout << "In step" << steps <<", there is no Turing machine state with state "<< state <<" and content "<< content;
                break;
            }

            tape.moveRight();


            // Display current state and content
        }
            

        }
        else if (option == "6")
        {
            int maxState, maxContent, numSteps;
            cout << "Enter the maximum state: ";
            cin >> maxState;
            cout << "Enter the maximum content: ";
            cin >> maxContent;
            cout << "How many steps do you wish to execute? ";
            cin >> numSteps;
            tm.outputCurrentInfo(maxState, maxContent, numSteps);
        }
        else if (option == "Q" || option == "q")
        {
            cout << "Quitting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
