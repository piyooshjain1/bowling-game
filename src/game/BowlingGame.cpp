#include "BowlingGame.h"
#include "../utils/Logger.h"
#include <iostream>
#include <stdexcept>
#include "StandardScoring.h"

namespace Game {

BowlingGame::BowlingGame() : currentPlayerIndex(0), scoringStrategy(nullptr) {
    Logger::logInfo() << "BowlingGame initialized.";
}

void BowlingGame::addPlayer(const std::string& name) {
    players.push_back(std::make_shared<Player>(name));
    Logger::logInfo() << "Player added: " << name;
}

void BowlingGame::addRoll(int pins) {
    if (players.empty()) {
        Logger::logError() << "Attempted to add roll with no players in the game.";
        throw std::logic_error("No players in the game");
    }

    auto& currentPlayer = players[currentPlayerIndex];
    currentPlayer->roll(pins);
    Logger::logInfo() << "Roll added: " << pins << " pins for player " << currentPlayer->getName();

    if (currentPlayer->isGameComplete()) {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        Logger::logInfo() << "Switching to next player.";
    }
}

void BowlingGame::printPlayerNames() const {
    if (players.empty()) {
        std::cout << "No players in the game." << std::endl;
        Logger::logWarning() << "No players in the game to print.";
        return;
    }

    std::cout << "Players in the game:" << std::endl;
    int index = 1;
    for (const auto& player : players) {
        std::cout << index++ << ". " << player->getName() << std::endl;
    }
    Logger::logInfo() << "Player names printed.";
}

void BowlingGame::selectPlayerByIndex(int index) {
    if (index < 0 || index >= static_cast<int>(players.size())) {
        Logger::logError() << "Invalid player index selected: " << index;
        throw std::out_of_range("Invalid player index");
    }
    currentPlayerIndex = index;
    Logger::logInfo() << "Player selected by index: " << index;
}

void BowlingGame::displayResult() {
    if (players.empty()) {
        std::cout << "No players in the game." << std::endl;
        Logger::logWarning() << "Attempted to display results with no players in the game.";
        return;
    }

    if (!scoringStrategy) {
        scoringStrategy = std::make_shared<StandardScoring>();
        Logger::logInfo() << "Default scoring strategy (StandardScoring) set.";
    }

    const Player* winner = nullptr;
    int highestScore = 0;

    std::cout << "Individual Scores:" << std::endl;
    for (const auto& player : players) {
        int score = player->calculateScore(scoringStrategy);
        std::cout << player->getName() << ": " << score << std::endl;

        if (!winner || score > highestScore) {
            winner = player.get();
            highestScore = score;
        }
    }

    if (winner) {
        std::cout << "\nWinner: " << winner->getName() << " with a score of " << highestScore << std::endl;
        Logger::logInfo() << "Winner: " << winner->getName() << " with a score of " << highestScore;
    }
}

bool BowlingGame::isGameComplete() const {
    for (const auto& player : players) {
        if (!player->isGameComplete()) {
            return false;
        }
    }
    Logger::logInfo() << "Game is complete.";
    return true;
}

void BowlingGame::setScoringStrategy(std::shared_ptr<IScoringStrategy> strategy) {
    if (!strategy) {
        Logger::logError() << "Attempted to set a null scoring strategy.";
        throw std::invalid_argument("Scoring strategy cannot be null");
    }
    scoringStrategy = strategy;
    Logger::logInfo() << "Scoring strategy set.";
}

} // namespace Game