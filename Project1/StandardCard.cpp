#include "StandardCard.h"
//constructors
StandardCard::StandardCard(int n) : Card(n) {}
//void StandardCard::display() { Card::display(); }

//Destructor
StandardCard::~StandardCard() { cout << "Standard :)" << endl; }

//Flip
//void StandardCard::flip() {
//    Card::flip();
//}