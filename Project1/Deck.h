#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"

class Deck {
private:
    Card** cards;
public:
    //Constructors
    Deck();
    Deck(Card** c);

    //Getters & Setters
    Card** getCards();
    void setCards(Card** c);

    //Shuffle 
    void shuffle();

    //Desplay (check the grid display with the lines)
    void displayGrid();

    //Destructor
    ~Deck();

    //Flip all cards in the Deck
    void flipAllCards();

    //get card with input from user
    Card* getCardFromInput(int index);

    //new method
    //removeCard set card to null
    void removeCard(int x);

    bool isEmpty();

    bool isLast();

};
#endif

