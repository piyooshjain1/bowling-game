#include <gtest/gtest.h>
#include "ScoringStrategy.h"
#include "StandardScoring.h"

class ScoringStrategyTest : public ::testing::Test {
protected:
    ScoringStrategy* scoringStrategy;

    void SetUp() override {
        scoringStrategy = new StandardScoring();
    }

    void TearDown() override {
        delete scoringStrategy;
    }
};

TEST_F(ScoringStrategyTest, CalculateScore_StandardScoring) {
    // Test case for a standard scoring scenario
    int score = scoringStrategy->calculateScore(5, 3); // Example: 5 pins in first roll, 3 in second
    EXPECT_EQ(score, 8);
}

TEST_F(ScoringStrategyTest, CalculateScore_Spare) {
    // Test case for a spare scenario
    int score = scoringStrategy->calculateScore(5, 5); // Example: 5 pins in first roll, spare
    EXPECT_EQ(score, 10); // Assuming next roll is 0
}

TEST_F(ScoringStrategyTest, CalculateScore_Strike) {
    // Test case for a strike scenario
    int score = scoringStrategy->calculateScore(10, 0); // Example: strike
    EXPECT_EQ(score, 10); // Assuming next two rolls are 0
}