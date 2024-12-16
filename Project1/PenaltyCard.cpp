#include "PenaltyCard.h"
//Constructor
PenaltyCard::PenaltyCard(int n, int d) : Card(n) { deduct = d; }
//void PenaltyCard::display() { Card::display(); }

//Getters & Setters
int PenaltyCard::getDeduct() {
    return this->deduct;
}
void PenaltyCard::setDeduct(int d) {
    this->deduct = d;
}

//Destructor
PenaltyCard::~PenaltyCard() { cout << "Penalty :)" << endl; }

//Flip
//void PenaltyCard::flip() {
//    Card::flip();
//}