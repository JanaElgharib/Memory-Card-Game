#include "Deck.h"
//Constructor
Deck::Deck() {
    cards = new Card * [16];
    int c = 1;
    for (int i = 0; i < 16; i++) {
        if (i < 12) {
            cards[i] = new StandardCard(c);
            if (i % 2 != 0) {
                c++;
            }
        }
        else if (i < 14) {
            cards[i] = new BonusCard(7, 3);
        }
        else {
            cards[i] = new PenaltyCard(8, 2);
        }

    }

}
Deck::Deck(Card** c) {
    cards = c;
}

//Getters & Setters
Card** Deck::getCards() {
    return cards;
}
void Deck::setCards(Card** c) {
    //ask marie
    delete[] cards; // Free existing memory to avoid leaks
    cards = new Card*[16]; // Allocate new memory for the array
    for (int i = 0; i < 16; i++) {
        cards[i] = c[i];
    }
}

//Shuffle
void Deck::shuffle() {
    int totalCards = 16; 

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Shuffle the cards manually
    for (int i = totalCards - 1; i > 0; --i) {
        int j = std::rand() % (i + 1); // Generate a random index
        std::swap(cards[i], cards[j]); // Swap cards[i] with cards[j]
    }
}

//Display
void Deck::displayGrid() {
    int c = 0;
    for (int row = 0; row < 4; ++row) {
        cout << " ___ ___ ___ ___" << endl;
        for (int col = 0; col < 4; ++col) {
            cout << "| ";
            if (cards[c] != nullptr) {
                cards[c]->display();
            }
            else {
                cout << " "; // Empty space for removed cards
            }
            cout << " ";
            c++;
        }
        cout << "|" << endl;
    }
    cout << " --- --- --- ---" << endl;
}
//Destructor
Deck:: ~Deck() {
    for (int i = 0; i < 16; i++) {
        delete cards[i]; // Delete each card object
    }
    delete[] cards; // Delete the array itself
    cout << "Deck deleted" << endl;
}

void Deck::flipAllCards() {
    for (int i = 0; i < 16; i++) { 
        cards[i]->flip(); 
    }
}

//new method
Card* Deck::getCardFromInput(int index) {
    //Check if card is already chosen or flipped
    if (cards[index] == nullptr) {
        return nullptr; // Return nullptr if the card is already removed
    }
    //Took care of that in initializegame()
    //if (cards[index]->getFlag() == 1) {
    //    cout << "Card already flipped. Choose another card." << endl;
    //    return getCardFromInput(); // Recursively prompt for input
    //}

    return cards[index]; // Return the selected card
}

//new method
//removeCard
void Deck::removeCard(int index) {
    if (cards[index] != nullptr) {
        delete cards[index];
        cards[index] = nullptr;
    }
}

//isEmpty
bool Deck::isEmpty() {
    for (int i = 0;i < 16;i++) {
        if (cards[i] != nullptr)
            return false;
    }
    return true;
}

bool Deck::isLast() {
    int c = 0;
    for (int i = 0;i < 16;i++) {
        if (cards[i] != nullptr)
            c++;
    }
    if (c == 1)
        return true;

    return false;

}