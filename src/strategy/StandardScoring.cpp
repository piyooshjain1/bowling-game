#include "StandardScoring.h"
#include "../utils/Logger.h" // Include the Logger utility
#include <stdexcept>

namespace Game {

int StandardScoring::calculateScore(std::vector<std::unique_ptr<Frame>> const& frames) {
    int totalScore = 0;

    Logger::logInfo() << "Starting score calculation...";

    for (size_t i = 0; i < frames.size(); ++i) {
        const auto& frame = frames[i];
        Logger::logInfo() << "Processing frame " << i + 1;

        // Handle the 10th frame special case
        if (i == frames.size() - 1) {
            totalScore += frame->getFirstRoll() + frame->getSecondRoll() + frame->getThirdRoll();
            Logger::logInfo() << "10th frame score: " << totalScore;
            break; // No bonuses are applied to the 10th frame
        }

        // Normal frame scoring
        totalScore += frame->getFirstRoll() + frame->getSecondRoll();
        Logger::logInfo() << "Frame " << i + 1 << " base score: " << totalScore;

        // Handle strike
        if (frame->isStrike() && i < frames.size() - 1) {
            Logger::logInfo() << "Strike detected in frame " << i + 1;
            totalScore += frames[i + 1]->getFirstRoll();
            if (frames[i + 1]->isStrike() && i < frames.size() - 2) {
                totalScore += frames[i + 2]->getFirstRoll();
                Logger::logInfo() << "Bonus for consecutive strikes added.";
            } else {
                totalScore += frames[i + 1]->getSecondRoll();
            }
        }
        // Handle spare
        else if (frame->isSpare() && i < frames.size() - 1) {
            Logger::logInfo() << "Spare detected in frame " << i + 1;
            totalScore += frames[i + 1]->getFirstRoll();
        }

        Logger::logInfo() << "Total score after frame " << i + 1 << ": " << totalScore;
    }

    Logger::logInfo() << "Final total score: " << totalScore;
    return totalScore;
}

} // namespace Game