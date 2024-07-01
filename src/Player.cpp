#include "Player.h"

Player::Player(const std::string& id, const std::pair<int, int>& startPos, PlayerTurn playerTurn)
    : playerID(id), currentPosition(startPos), hasWon(false), turn(playerTurn), whosNextTurn(playerTurn2) {}

std::string Player::getPlayerID() const {
    return playerID;
}

std::pair<int, int> Player::getCurrentPosition() const {
    return currentPosition;
}

bool Player::getHasWon() const {
    return hasWon;
}

PlayerTurn Player::getTurn() const {
    return turn;
}

void Player::setPlayerID(const std::string& id) {
    playerID = id;
}

void Player::setCurrentPosition(const std::pair<int, int>& pos) {
    currentPosition = pos;
}

void Player::setHasWon(bool won) {
    hasWon = won;
}

void Player::setTurn(PlayerTurn playerTurn) {
    turn = playerTurn;
}

void Player::setNextTurn(PlayerTurn playerTurn2) {
    whosNextTurn = playerTurn2;
}

