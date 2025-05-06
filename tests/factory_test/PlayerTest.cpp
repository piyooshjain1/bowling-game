#include "gtest/gtest.h"
#include "../../src/factory/Player.h"
#include "../../src/strategy/StandardScoring.h"

using namespace Game;

// Test the Player constructor
TEST(PlayerTest, Constructor) {
    Player player("Alice");
    EXPECT_EQ(player.getName(), "Alice");
}

// Test rolling pins
TEST(PlayerTest, RollPins) {
    Player player("Alice");

    player.roll(5);
    player.roll(4);

    EXPECT_FALSE(player.isGameComplete());
}

// Test calculating score
TEST(PlayerTest, CalculateScore) {
    Player player("Bob");
    auto scoringStrategy = std::make_shared<StandardScoring>();

    player.roll(10); // Strike
    player.roll(6);
    player.roll(4);  // Spare
    player.roll(5);
    player.roll(3);  // Normal frame

    EXPECT_EQ(player.calculateScore(scoringStrategy), 43); // Expected score
}

// Test game completion
TEST(PlayerTest, IsGameComplete) {
    Player player("Charlie");

    for (int i = 0; i < 12; ++i) {
        player.roll(10); // Strike in every frame
    }

    EXPECT_TRUE(player.isGameComplete());
}