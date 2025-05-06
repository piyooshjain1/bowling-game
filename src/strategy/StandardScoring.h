#ifndef STANDARD_SCORING_H
#define STANDARD_SCORING_H

#include "IScoringStrategy.h"
#include "../game/Frame.h"
#include <vector>

namespace Game {

class StandardScoring : public IScoringStrategy {
public:
    int calculateScore( std::vector<std::unique_ptr<Frame>>const & frames)  override;
};

} // namespace Game

#endif // STANDARD_SCORING_H