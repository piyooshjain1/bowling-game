#ifndef SCORINGSTRATEGY_H
#define SCORINGSTRATEGY_H

class ScoringStrategy {
public:
    virtual ~ScoringStrategy() {}
    virtual int calculateScore() = 0;
};

#endif // SCORINGSTRATEGY_H