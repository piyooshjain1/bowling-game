#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include <vector>
#include <memory>
#include "Player.h"
#include "../strategy/IScoringStrategy.h"

namespace Game {

class BowlingGame {
private:
    std::vector<std::shared_ptr<Player>> players;
    int currentPlayerIndex;
    std::shared_ptr<IScoringStrategy> scoringStrategy; // Scoring strategy

public:
    BowlingGame();
    void addPlayer(const std::string& name);
    void addRoll(int pins);
    void printPlayerNames() const;
    bool isGameComplete() const;
    void setScoringStrategy(std::shared_ptr<IScoringStrategy> strategy);
    void selectPlayerByIndex(int index);
    // New method
    void displayResult() ; // New method
};

} // namespace Game

#endif // BOWLINGGAME_H