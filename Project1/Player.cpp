#include "Player.h"
//Constructors
Player::Player(string n) { name = n;score = 0; }
void Player::displayScore() { cout << "Score: " << score << endl; }

//Getters & Setters
string Player::getName() {
    return this->name;
}
void Player::setName(string s) {
    this->name = s;
}
int Player::getScore() {
    return this->score;
}
void Player::addScore(int s) {
    score += s;
}
//void Player::setScore(StandardCard* k) {
//    this->score += 1;
//}
//void Player::setScore(BonusCard* k) {
//    this->score += 1;
//}
//void Player::setScore(PenaltyCard* k) {
//    this->score -= 1;
//}

//Destructor
Player::~Player() { cout << "Blabeezo :(" << endl; }