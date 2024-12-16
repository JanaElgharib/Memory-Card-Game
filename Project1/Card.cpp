#include "Card.h"
//Construtcors 
Card::Card(int n) {
    number = n;
    flag = false;
}

//Getters & Setters
int Card::getNumber() {
    return this->number;
}
void Card::setNumber(int n) {
    this->number = n;
}
bool Card::getFlag() {
    return this->flag;
}
void Card::setFlag(int f) {
    this->flag = f;
}

void Card::display() {
    if (flag) {
        cout << number;
    }
    else {
        cout << "*";
    }
}

//Destructor
Card::~Card() { 
    //cout << "Card matched: "<<endl; 
}


void Card::flip() {
    if(flag)
        setFlag(0);
    else {
        setFlag(1);
    }
}

//new methods
//reveal
void Card::reveal() { 
    setFlag(1);
}

//hide
void Card::hide() { 
    setFlag(0);
}