#include "Player.h"
#include <stdexcept>

namespace Game {

Player::Player(const std::string& name) : Person(name), currentFrameIndex(0) {
    for (int i = 0; i < 9; ++i) {
        frames.push_back(std::make_unique<Frame>());
    }
    frames.push_back(std::make_unique<Frame>(true)); // 10th frame
}

void Player::roll(int pins) {
    if (currentFrameIndex >= 10 || (currentFrameIndex == 9 && frames[currentFrameIndex]->isComplete())) {
        throw std::logic_error("Game is already complete for this player");
    }

    frames[currentFrameIndex]->roll(pins);

    // Move to the next frame if the current frame is complete
    if (frames[currentFrameIndex]->isComplete() && currentFrameIndex < 9) {
        ++currentFrameIndex;
    }
}

int Player::calculateScore(const std::shared_ptr<IScoringStrategy> scoringStrategy)  {
    return scoringStrategy->calculateScore(frames);
}

bool Player::isGameComplete() const {
    return currentFrameIndex >= 10 || (currentFrameIndex == 9 && frames[currentFrameIndex]->isComplete());
}

} // namespace Game
