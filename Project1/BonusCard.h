#ifndef BONUSCARD_H
#define BONUSCARD_H
#include "Card.h"

class BonusCard :public Card {
private:
    int bonus;
public:
    //Constructors
    BonusCard(int n, int b);
    BonusCard() = default;

    //Getters & Setters 
    int getBonus();
    void setBonus(int b);

    //Display
    //void display();

    //Destructor
    ~BonusCard();

    //Flip
    //void flip();
};
#endif