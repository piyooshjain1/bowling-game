#include "ScoringStrategy.h"

class ScoringStrategy {
public:
    virtual int calculateScore(const std::vector<int>& frames) = 0;
};