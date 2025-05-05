#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include <vector>
#include "Frame.h"
#include "ScoringStrategy.h"
#include "ScoreObserver.h"

class BowlingGame : public Subject {
public:
    BowlingGame(ScoringStrategy* strategy);
    void startGame();
    void addFrame(Frame* frame);
    int calculateScore();
    void attach(ScoreObserver* observer) override;
    void detach(ScoreObserver* observer) override;
    void notify() override;

private:
    std::vector<Frame*> frames;
    ScoringStrategy* scoringStrategy;
    int totalScore;
    std::vector<ScoreObserver*> observers;
};

#endif // BOWLINGGAME_H