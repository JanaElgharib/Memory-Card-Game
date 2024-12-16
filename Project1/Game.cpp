#include "Card.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
//Constructors
Game::Game() {
    p1 = new Player("");
    p2 = new Player("");
    deck = new Deck();
    turn = 0;
    bool skipTurn = false;
    //grid = new Card * *[4]; //ask marie
    //for (int i = 0; i < 4; ++i) {
    //    grid[i] = new Card * [4]; // Inner arrays for columns
    //}
}

Game::Game(Player* player1, Player* player2, Deck* d, int t) {
    p1 = new Player(player1->getName());
    p2 = new Player(player2->getName());
    deck = d;
    //grid = new Card **[4]; //ask marie
    //for (int i = 0; i < 4; ++i) {
    //    grid[i] = new Card * [4]; // Inner arrays for columns
    //}
    turn = t;
}

//Getters & Setters
int Game::getTurn() {
    return this->turn;
}
void Game::setTurn(int t) {
    this->turn = t;
}

Player* Game::getPlayer1() {
    return this->p1;
}
//void Game::setPlayer1(Player* player1) {
//    p1->setName(player1->getName());
//    p1->addScore(player1->getScore());
//}

Player* Game::getPlayer2() {
    return this->p2;
}
//void Game::setPlayer2(Player* player2) {
//    p2->setName(player2->getName());
//    p2->addScore(player2->getScore());
//}

Deck* Game::getDeck() {
    return deck;
}
void Game::setDeck(Deck* d) {
    deck = d;
}

//Card*** Game::getGrid() {
//    return grid;
//}
//void Game::setGrid(Card*** g) {
//    grid = g;
//}

/*//initializeGrid
void Game::initializeGrid() {
    int index = 0;
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            grid[row][col] = deck->getCards()[index];
            ++index;
            cout << index;
        }
    }
}*/

int Game::getIndex() {
    int attempts = 0;
    const int MAX_ATTEMPTS = 5;
    while (attempts < MAX_ATTEMPTS) {
        int row, col;
        cout << "Enter the coordinates of the card to flip (row and column):" << endl;
        cout << "Row(1-4): ";
        cin >> row;
        cout << "Column(1-4): ";
        cin >> col;

        if (row >= 1 && row <= 4 && col >= 1 && col <= 4) {
            int index = (row - 1) * 4 + (col - 1);
            if (deck->getCardFromInput(index) == nullptr) {
                cout << "this card has been removed"<<endl;
            }
            else {
                return index; // Adjust for 0-based indexing
            }
        }
        cout << "Invalid coordinates. Please try again." << endl;
        attempts++;

    }
    if (attempts >= MAX_ATTEMPTS) {
        cout << "Too many invalid attempts. Exiting..." << endl;
    }
}

void Game::playround(Player* curr) {
    //cout << "Total Turns: " << totalTurns << endl;
    cout << "Player 1: " << p1->getName() << "   Score: " << p1->getScore() << endl;
    cout << "Player 2: " << p2->getName() << "   Score: " << p2->getScore() << endl;
    cout << "Current player: " << curr->getName() << endl;

    // First card selection
    cout << curr->getName() << ", select the first card:" << endl;
    int firstIndex = getIndex();
    Card* firstCard = deck->getCardFromInput(firstIndex);
    firstCard->reveal();
    deck->displayGrid();

    if (deck->isLast()) {
        cout << "Only one card is remaining. Automatically handling it." << endl;

        // Handle bonus or penalty for the last card
        if (firstCard->getNumber() == 7) {
            cout << "The last card is a Bonus Card. Adding 1 point to " << curr->getName() << "." << endl;
            curr->addScore(1);  // For one bonus
        }
        else if (firstCard->getNumber() == 8) {
            cout << "The last card is a Penalty Card. Subtracting 1 point from " << curr->getName() << "." << endl;
            curr->addScore(-1);  // For one penalty
        }

        deck->removeCard(firstIndex); // Remove the last card
        deck->displayGrid();
        return; // End the game
    }

    // Second card selection
    cout << curr->getName() << ", select the second card:" << endl;
    int secondIndex = getIndex();
    while (secondIndex == firstIndex) {
        cout << "Card already flipped. Choose another card." << endl;
        secondIndex = getIndex();
    }

    Card* secondCard = deck->getCardFromInput(secondIndex);
    secondCard->reveal();
    deck->displayGrid();

    // Card comparison and scoring logic
    if (firstCard->getNumber() == secondCard->getNumber()) {
        if (firstCard->getNumber() < 7) {
            cout << "Congrats! You've chosen a pair of Standard cards." << endl;
            curr->addScore(1);  // For Standard 
            deck->removeCard(firstIndex);
            deck->removeCard(secondIndex);
        }
        else if (firstCard->getNumber() == 7) {
            cout << "Congrats! You've chosen a pair of bonus cards." << endl;
            cout << "Enter 1 --> gain 2 points or Enter 2 --> and gain 1 point and take another turn: ";
            int choice;
            cin >> choice;

            curr->addScore(1);  
            if (choice == 2) {
                deck->displayGrid();
                playround(curr); // Player gets another turn
            }
            else {
                curr->addScore(1);  // player gets to take the 2 points of the bouns
            }
            deck->removeCard(firstIndex);
            deck->removeCard(secondIndex);
        }
        else if (firstCard->getNumber() == 8) {
            cout << "You've chosen a pair of penalty cards." << endl;
            cout << "Enter 1 --> lose 2 points or Enter 2 --> lose 1 point and skip the next turn: ";
            int choice;
            cin >> choice;
            deck->removeCard(firstIndex);
            deck->removeCard(secondIndex);
            if (choice == 1) {
                curr->addScore(-2);  // For pairs of penalty
            }
            else {
                curr->addScore(-1);  // player chooses to skip a turn
                skipTurn = true;
                curr = (curr == p1) ? p2 : p1;
                deck->displayGrid();
                playround(curr);
            }
        }
    }
    else {
        if ((firstCard->getNumber() == 8 && secondCard->getNumber() < 7) ||
            (secondCard->getNumber() == 8 && firstCard->getNumber() < 7)) {
            cout << "Penalty card and standard card are revealed." << endl;
            curr->addScore(-1);  // For penalty
            deck->removeCard(firstCard->getNumber() == 8 ? firstIndex : secondIndex);
            if (firstCard->getNumber() < 7) {
                firstCard->hide();
            }
            if (secondCard->getNumber() < 7) {
                secondCard->hide();
            }
        }
        else if ((firstCard->getNumber() == 7 && secondCard->getNumber() < 7) ||
            (secondCard->getNumber() == 7 && firstCard->getNumber() < 7)) {
            cout << "Bonus card and standard card are revealed." << endl;
            curr->addScore(1);  // For bonus
            deck->removeCard(firstCard->getNumber() == 7 ? firstIndex : secondIndex);
            if (firstCard->getNumber() < 7) {
                firstCard->hide();
            }
            if (secondCard->getNumber() < 7) {
                secondCard->hide();
            }
        }
        else if ((firstCard->getNumber() == 8 && secondCard->getNumber() == 7) ||
            (firstCard->getNumber() == 7 && secondCard->getNumber() == 8)) {
            cout << "A Penalty card and A Bonus card are revealed." << endl;
            deck->removeCard(firstIndex);
            deck->removeCard(secondIndex);
        }
        else {
            cout << "2 standard unmatched cards are revealed"<<endl;
            firstCard->hide();
            secondCard->hide();
        }
        
    }
    deck->displayGrid();

}

//IntializeGame
void Game::initializeGame() {
    cout << "Please enter Name of Player one: ";
    string p1Name;
    cin >> p1Name;
    p1->setName(p1Name);
    cout << "Please enter Name of Player two: ";
    string p2Name;
    cin >> p2Name;
    p2->setName(p2Name);

    cout << "Choose which player wants to begin (if Player one, enter 0; if Player two, enter 1): ";
    int t;
    cin >> t;
    turn = t;

    deck->shuffle();

    // Debug/testing purposes: Show grid initially
    //deck->flipAllCards();
    //deck->displayGrid();
    //deck->flipAllCards();

    cout << "Game has started" << endl;
    deck->displayGrid();

    Player* curr = (turn % 2 == 0) ? p1 : p2;

    while (!deck->isEmpty()) {
        // Handle skipped turns
        if (skipTurn) {
            curr = (curr == p1) ? p2 : p1;
            cout << curr->getName() << " is skipping this turn." << endl;
            skipTurn = false;  // Reset skipTurn flag
            curr = (curr == p1) ? p2 : p1;
        }

        playround(curr);

        // Update turn and current player
        turn++;
        curr = (turn % 2 == 0) ? p1 : p2;
    }

    cout << "Game Over!" << endl;
    //deck->displayGrid();
    if (p1->getScore() > p2->getScore()) {
        cout << "Player " << p1->getName() << " wins with a score of " << p1->getScore() << "!" << endl;
    }
    else if (p2->getScore() > p1->getScore()) {
        cout << "Player " << p2->getName() << " wins with a score of " << p2->getScore() << "!" << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }
}



//Destructor
Game:: ~Game() {
    delete p1;
    cout << "P1 destroyed" << endl;
    delete p2;   
    cout << "P1=2 destroyed" << endl;


 /* for (int i = 0; i < 4; ++i) {
        delete[] grid[i];  // Delete each row (which is an array of Card*)
    }
    cout << "whole deck destoryed" << endl;

    // Now, delete the array of pointers (the rows themselves)
    delete[] grid;  // Delete the array holding the pointers to the rows
    cout << "grid destroyed" << endl;*/
    
    //   delete[] deck->getCards(); //ask marie
    //for (int i = 0; i < 16; i++) {
    //    cout<< deck[i].;
    //}
    delete deck;
}

//Main
int main() {
    Game game;
    game.initializeGame();

    return 0;
}