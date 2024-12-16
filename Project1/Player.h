#ifndef PLAYER_H
#define PLAYER_H

#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"

#include <iostream>
using namespace std;


class Player {
private:
    string name;
    int score;
public:
    //Constructors
    Player() = default;
    Player(string n);

    //Getters & Setters
    string getName();
    void setName(string s);

    int getScore();
    void addScore(int s); //replaced by 3 methods
    //void setScore(StandardCard* k);
    //void setScore(BonusCard* k);
    //void setScore(PenaltyCard* k);


    //Display
    void displayScore();

    //Destructor
    ~Player();
};
#endif
