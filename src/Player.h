#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <utility>

enum class PlayerTurn { PLAYER1, PLAYER2 };

class Player {
private:
    std::string playerID;
    std::pair<int, int> currentPosition;
    bool hasWon;
    PlayerTurn turn;
    PlayerTurn whosNextTurn;

public:
    Player(const std::string& id, const std::pair<int, int>& startPos, PlayerTurn playerTurn, PlayerTurn playerTurn2);

    std::string getPlayerID() const;
    std::pair<int, int> getCurrentPosition() const;
    bool getHasWon() const;
    PlayerTurn getTurn() const;
    void setPlayerID(const std::string& id);
    void setCurrentPosition(const std::pair<int, int>& pos);
    void setHasWon(bool won);
    void setTurn(PlayerTurn playerTurn);
    void setNextTurn(PlayerTurn playerturn2);
    
};

#endif // PLAYER_H
