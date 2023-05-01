#include "TuringTape.h"
#include <limits>

TuringTape::TuringTape(int n)
{
    if (n == -1)
    {
        this->n = std::numeric_limits<int>::max();
    }
    else
    {
        this->n = n;
    }
    tape.push_back(0);
    position = 0; 
}

bool TuringTape::moveRight()
{
    position++;
    if(tape.size() >= position  && position < n){
        tape.push_back(0);
        return true;
    }
    return false;
}

bool TuringTape::moveLeft()
{
    position--;
    if (position < 0)
    {
        return false;
    }
    return true;
}

int TuringTape::getContent()
{
    if (position >= 0 && position < tape.size())
    {
        return tape[position];
    }
    return 0;
}

void TuringTape::setContent(int c)
{
    if (position >= 0 && position < n)
    {
        if (position >= tape.size())
        {
            tape.push_back(c);
        }
        else
        {
            tape[position] = c;
        }
    }
}

int TuringTape::getPosition()
{
    return position;
}

std::ostream &operator<<(std::ostream &out, const TuringTape &T)
{
    for (int i = 0; i < T.tape.size(); i++)
    {
        out << T.tape[i]; 
    }
    return out;
}
