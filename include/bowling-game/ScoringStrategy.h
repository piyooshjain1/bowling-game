#ifndef SCORINGSTRATEGY_H
#define SCORINGSTRATEGY_H

class ScoringStrategy {
public:
    virtual ~ScoringStrategy() {}
    virtual int calculateScore(int pinsKnockedDown) = 0;
};

#endif // SCORINGSTRATEGY_H