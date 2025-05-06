#include "gtest/gtest.h"
#include "../../src/game/Frame.h"

// Test the Frame constructor
TEST(FrameTest, Constructor) {
    Frame frame;
    EXPECT_FALSE(frame.isComplete());
    EXPECT_FALSE(frame.isStrike());
    EXPECT_FALSE(frame.isSpare());
}

// Test rolling pins in a normal frame
TEST(FrameTest, RollPinsNormalFrame) {
    Frame frame;

    frame.roll(5);
    frame.roll(4);

    EXPECT_TRUE(frame.isComplete());
    EXPECT_FALSE(frame.isStrike());
    EXPECT_FALSE(frame.isSpare());
}

// Test rolling a strike
TEST(FrameTest, RollStrike) {
    Frame frame;

    frame.roll(10);

    EXPECT_TRUE(frame.isComplete());
    EXPECT_TRUE(frame.isStrike());
    EXPECT_FALSE(frame.isSpare());
}

// Test rolling a spare
TEST(FrameTest, RollSpare) {
    Frame frame;

    frame.roll(6);
    frame.roll(4);

    EXPECT_TRUE(frame.isComplete());
    EXPECT_FALSE(frame.isStrike());
    EXPECT_TRUE(frame.isSpare());
}

// Test rolling in the 10th frame
TEST(FrameTest, TenthFrame) {
    Frame frame(true);

    frame.roll(10); // Strike
    frame.roll(10); // Strike
    frame.roll(10); // Strike

    EXPECT_TRUE(frame.isComplete());
    EXPECT_TRUE(frame.isStrike());
    EXPECT_FALSE(frame.isSpare());
}

// Test rolling invalid pin counts
TEST(FrameTest, RollInvalidPins) {
    Frame frame;
    EXPECT_THROW(frame.roll(-1), std::invalid_argument); // Negative pins
    EXPECT_THROW(frame.roll(11), std::invalid_argument); // Pins greater than 10
}

// Test rolling more than two times in a normal frame
TEST(FrameTest, RollMoreThanTwoTimes) {
    Frame frame;
    frame.roll(5);
    frame.roll(4);
    EXPECT_THROW(frame.roll(3), std::logic_error); // Rolling more than twice should throw an exception
}

// Test rolling pins that exceed the maximum for a frame
TEST(FrameTest, RollExceedingFrameLimit) {
    Frame frame;
    frame.roll(5);
    EXPECT_THROW(frame.roll(6), std::invalid_argument); // Total pins in a frame cannot exceed 10
}

// Test the 10th frame with three rolls
TEST(FrameTest, TenthFrameThreeRolls) {
    Frame frame(true); // 10th frame
    frame.roll(10);    // Strike
    EXPECT_FALSE(frame.isComplete()); // Frame should not be complete after one roll

    frame.roll(10);    // Second strike
    EXPECT_FALSE(frame.isComplete()); // Frame should not be complete after two rolls

    frame.roll(10);    // Third strike
    EXPECT_TRUE(frame.isComplete());  // Frame should be complete after three rolls
    EXPECT_EQ(frame.getFirstRoll(), 10);
    EXPECT_EQ(frame.getSecondRoll(), 10);
    EXPECT_EQ(frame.getThirdRoll(), 10);
}

// Test the 10th frame without a strike or spare
TEST(FrameTest, TenthFrameWithoutStrikeOrSpare) {
    Frame frame(true); // 10th frame
    frame.roll(5);
    frame.roll(4); // No strike or spare
    EXPECT_TRUE(frame.isComplete());  // Frame should be complete after two rolls
    EXPECT_EQ(frame.getFirstRoll(), 5);
    EXPECT_EQ(frame.getSecondRoll(), 4);
    EXPECT_EQ(frame.getThirdRoll(), 0); // Third roll should be 0
}