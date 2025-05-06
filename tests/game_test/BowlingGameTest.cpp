#include "gtest/gtest.h"
#include "../../src/game/BowlingGame.h"
#include "../../src/strategy/StandardScoring.h"

using namespace Game;

// Test adding players to the game
TEST(BowlingGameTest, AddPlayers) {
    BowlingGame game;
    game.addPlayer("Alice");
    game.addPlayer("Bob");

    testing::internal::CaptureStdout();
    game.printPlayerNames();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("1. Alice"), std::string::npos);
    EXPECT_NE(output.find("2. Bob"), std::string::npos);
}


// Test selecting a player by index
TEST(BowlingGameTest, SelectPlayerByIndex) {
    BowlingGame game;
    game.addPlayer("Alice");
    game.addPlayer("Bob");

    EXPECT_NO_THROW(game.selectPlayerByIndex(0)); // Valid index
    EXPECT_THROW(game.selectPlayerByIndex(2), std::out_of_range); // Invalid index
}

// Test displaying results with no players
TEST(BowlingGameTest, DisplayResultNoPlayers) {
    BowlingGame game;

    testing::internal::CaptureStdout();
    game.displayResult();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("No players in the game."), std::string::npos);
}