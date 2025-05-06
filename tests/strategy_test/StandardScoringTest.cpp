#include "gtest/gtest.h"
#include "../../src/strategy/StandardScoring.h"
#include "../../src/game/Frame.h"
#include <vector>
#include <memory>

// Helper function to create a frame
std::unique_ptr<Frame> createFrame(int firstRoll, int secondRoll = 0, int thirdRoll = 0, bool isTenthFrame = false) {
    auto frame = std::make_unique<Frame>(isTenthFrame);
    frame->roll(firstRoll);
    if (secondRoll > 0 || isTenthFrame) frame->roll(secondRoll);
    if (thirdRoll > 0 && isTenthFrame) frame->roll(thirdRoll);
    return frame;
}

// Test StandardScoring with valid frames
TEST(StandardScoringTest, CalculateScoreValidFrames) {
   Game::StandardScoring scoring;
    std::vector<std::unique_ptr<Frame>> frames;

    frames.push_back(createFrame(4, 5)); // Normal frame: 4 + 5 = 9
    frames.push_back(createFrame(6, 3)); // Normal frame: 6 + 3 = 9

    int score = scoring.calculateScore(frames);
    EXPECT_EQ(score, 18); // Total score should be 18
}

// Test StandardScoring with a strike
TEST(StandardScoringTest, CalculateScoreWithStrike) {
   Game::StandardScoring scoring;
    std::vector<std::unique_ptr<Frame>> frames;

    frames.push_back(createFrame(10));  // Strike
    frames.push_back(createFrame(5, 4)); // Normal frame: 5 + 4 = 9

    int score = scoring.calculateScore(frames);
    EXPECT_EQ(score, 28); // Strike bonus: 10 + (5 + 4) + 9 = 28
}

// Test StandardScoring with a spare
TEST(StandardScoringTest, CalculateScoreWithSpare) {
   Game::StandardScoring scoring;
    std::vector<std::unique_ptr<Frame>> frames;

    frames.push_back(createFrame(6, 4)); // Spare
    frames.push_back(createFrame(5, 3)); // Normal frame: 5 + 3 = 8

    int score = scoring.calculateScore(frames);
    EXPECT_EQ(score, 23); // Spare bonus: 10 + 5 + 8 = 23
}

// Test StandardScoring with the 10th frame
TEST(StandardScoringTest, CalculateScoreWithTenthFrame) {
    Game::StandardScoring scoring;;
    std::vector<std::unique_ptr<Frame>> frames;

    for (int i = 0; i < 9; ++i) {
        frames.push_back(createFrame(4, 5)); // Normal frames: 4 + 5 = 9 each
    }
    frames.push_back(createFrame(10, 10, 10, true)); // 10th frame: Strike + Strike + Strike

    int score = scoring.calculateScore(frames);
    EXPECT_EQ(score, 81 + 30); // Total score: (9 * 9) + (10 + 10 + 10) = 111
}