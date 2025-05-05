#include <iostream>
#include "game/BowlingGame.h"
#include "factory/PlayerFactory.h"

int main() {
    PlayerFactory playerFactory;
    BowlingGame game;

    // Create players
    auto player1 = playerFactory.createPlayer("Alice");
    auto player2 = playerFactory.createPlayer("Bob");

    game.addPlayer(player1);
    game.addPlayer(player2);

    // Start the game
    game.startGame();

    // Display final scores
    game.displayScores();

    return 0;
}