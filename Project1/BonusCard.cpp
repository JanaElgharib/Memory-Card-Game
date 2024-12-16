#include "BonusCard.h"
//Constructors
BonusCard::BonusCard(int n, int b) :Card(n) { bonus = b; }
//void BonusCard::display() { Card::display(); }

//Getters & Setters
int BonusCard::getBonus() {
    return this->bonus;
}
void BonusCard::setBonus(int b) {
    this->bonus = b;
}

//Destructor
BonusCard::~BonusCard() { cout << "Bonus :)" << endl; }

//void BonusCard::flip() {
//    Card::flip();
//}