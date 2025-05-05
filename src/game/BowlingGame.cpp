#include "BowlingGame.h"
#include "Frame.h"
#include "ScoringStrategy.h"
#include <vector>
#include <memory>

BowlingGame::BowlingGame(std::unique_ptr<ScoringStrategy> strategy) 
    : scoringStrategy(std::move(strategy)) {}

void BowlingGame::startGame() {
    // Initialize game state
    frames.clear();
}

void BowlingGame::addFrame(const Frame& frame) {
    frames.push_back(frame);
}

int BowlingGame::calculateScore() const {
    int totalScore = 0;
    for (const auto& frame : frames) {
        totalScore += scoringStrategy->calculateScore(frame);
    }
    return totalScore;
}