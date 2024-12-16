#ifndef PENALTYCARD_H
#define PENALTYCARD_H
#include "Card.h"
class PenaltyCard :public Card {
private:
    int deduct;
public:
    //Constructors
    PenaltyCard(int n, int d);
    PenaltyCard() = default;

    //Getters & Setters
    int getDeduct();
    void setDeduct(int d);

    //Display
    //void display();

    //Destructor
    ~PenaltyCard();

    //Flip
    //void flip();
};
#endif
