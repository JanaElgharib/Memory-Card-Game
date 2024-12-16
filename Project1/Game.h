#ifndef PROG3GAME_GAME_H
#define PROG3GAME_GAME_H
#include "Player.h"
#include "Deck.h"
#include "Card.h"
// ask ahmed marie about design of turn
class Game {
private:
    int turn;
    bool skipTurn;
    Player* p1;
    Player* p2;
    Deck* deck;
 //   Card*** grid;

//    void initializeGrid();
public:
    //Constructors
    Game();
    // Turn 0 for p1 and 1 for p2
    // add points attribite
    Game(Player* player1, Player* player2, Deck* d, int turn = 0);

    //Getters & Setters
    int getTurn();
    void setTurn(int t);

    Player* getPlayer1();
    //void setPlayer1(Player* player1);

    Player* getPlayer2();
    //void setPlayer2(Player* player2);

    Deck* getDeck();
    void setDeck(Deck* d);

    //Card*** getGrid();
    //void setGrid(Card*** g);

    //IntializeGame
    void initializeGame();

    //Destructor
    ~Game();

private:
    //getting index for cards in deck
    int getIndex();
    void playround(Player*);
};

#endif
