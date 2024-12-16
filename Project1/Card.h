#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card {
private:
    int number;
    bool flag;
public:
    //Consturctors 
    Card(int n);
    Card() = default;

    //Setters & Getters
    int getNumber();
    void setNumber(int n);

    bool getFlag();
    void setFlag(int f);

    //Display
    virtual void display();

    //Destructor
    virtual ~Card();

    //Flip Cardd
    void flip(); //changed to reveal & hide 

    //new methods
    //reveal
    void reveal();

    //hide
    void hide();
};
#endif
