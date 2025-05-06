#include <iostream>
#include "game/BowlingGame.h"
#include "strategy/StandardScoring.h"
#include "utils/Logger.h"

int main() {
    using namespace Game;

    // Set log level to INFO
    Logger::setLogLevel(Logger::WARNING);

    // Create a BowlingGame instance
    BowlingGame game;

    // Set the scoring strategy
    game.setScoringStrategy(std::make_shared<StandardScoring>());

    // Add players to the game
    game.addPlayer("Alice");
    game.addPlayer("Bob");

    // Example rolls for the game
    std::vector<int> inputRolls = {1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6};
    game.printPlayerNames();
    game.selectPlayerByIndex(0); // Select the first player (Alice)
    // Simulate the game by adding rolls
    for (int pins : inputRolls) {
        try {
            game.addRoll(pins);
        } catch (const std::logic_error& e) {
            Logger::logError() << "Error: " << e.what();
            break;
        }
    }
    game.selectPlayerByIndex(1);
    std::vector<int> inputRolls2 = {1, 4, 4, 5, 6, 4, 5, 5, 5, 0, 1, 7, 3, 6, 4, 5, 2, 8, 6};

    // Simulate the game by adding rolls
    for (int pins : inputRolls2) {
        try {
            game.addRoll(pins);
        } catch (const std::logic_error& e) {
            Logger::logError() << "Error: " << e.what();
            break;
        }
    }
    // Display final scores for all players
    game.displayResult();

    return 0;
}