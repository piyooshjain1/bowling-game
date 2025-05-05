#include "gtest/gtest.h"
#include "../src/game/BowlingGame.h"
#include "../src/factory/PlayerFactory.h"

class BowlingGameTest : public ::testing::Test {
protected:
    BowlingGame* game;
    PlayerFactory* playerFactory;

    void SetUp() override {
        game = new BowlingGame();
        playerFactory = new PlayerFactory();
    }

    void TearDown() override {
        delete game;
        delete playerFactory;
    }
};

TEST_F(BowlingGameTest, TestStartGame) {
    game->startGame();
    EXPECT_EQ(game->getCurrentFrame(), 1);
}

TEST_F(BowlingGameTest, TestAddFrame) {
    game->startGame();
    Frame frame(5, 4);
    game->addFrame(frame);
    EXPECT_EQ(game->getTotalScore(), 9);
}

TEST_F(BowlingGameTest, TestCalculateScore) {
    game->startGame();
    Frame frame1(5, 4);
    Frame frame2(3, 6);
    game->addFrame(frame1);
    game->addFrame(frame2);
    EXPECT_EQ(game->calculateScore(), 23);
}