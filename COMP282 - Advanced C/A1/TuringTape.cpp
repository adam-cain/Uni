#include "TuringTape.h"

TuringTape::TuringTape(int n) {
    this->n = n;
    tape = new int[n];
    for (int i = 0; i < n; i++) {
        tape[i] = 0; // Initialize tape with 0
    }
    position = 0; // Set initial position to 0
    highestPosition = 0; // Set highest position to 0
}

bool TuringTape::moveRight() {
    position++;
    if(position > highestPosition){
        highestPosition = position;
    }
    if(position > n || position < 0){
        return false;
    }
    return true;
}

bool TuringTape::moveLeft() {
    position--;
    if (position < 0 || position > n) {
        return false;
    }
    return true;
}

int TuringTape::getContent() {
    if (position >= 0 && position < n) {
        return tape[position];
    }
    return 0;
}

void TuringTape::setContent(int c) {
    if (position >= 0 && position < n) {
        tape[position] = c;
    }
}

int TuringTape::getPosition() {
    return position;
}

std::ostream& operator<<(std::ostream& out, const TuringTape& T) {
    for (int i = 0; i <= T.highestPosition; i++) {
        out << T.tape[i]; // Output content of the tape
    }
    return out;
}