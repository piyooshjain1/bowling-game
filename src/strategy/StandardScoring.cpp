#include "StandardScoring.h"

int StandardScoring::calculateScore(const std::vector<int>& frames) {
    int totalScore = 0;
    for (size_t i = 0; i < frames.size(); ++i) {
        totalScore += frames[i];
    }
    return totalScore;
}