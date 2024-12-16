#ifndef STANDARDCARD_H
#define STANDARDCARD_H
#include "Card.h"


class StandardCard :public Card {
public:
    //Constructors
    StandardCard(int n);
    StandardCard() = default;

    //Display;
    //void display();

    //Destructor
    ~StandardCard();

    //Flip
    //void flip();
};
#endif
