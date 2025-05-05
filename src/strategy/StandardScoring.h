#ifndef STANDARD_SCORING_H
#define STANDARD_SCORING_H

#include "ScoringStrategy.h"

class StandardScoring : public ScoringStrategy {
public:
    int calculateScore(const std::vector<int>& frames) override;
};

#endif // STANDARD_SCORING_H