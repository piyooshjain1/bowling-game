#ifndef ISCoringStrategy_H
#define ISCoringStrategy_H

#include <vector>
#include <memory>
#include "../game/Frame.h"

namespace Game {

class IScoringStrategy {
public:
    virtual ~IScoringStrategy() = default;

    // Calculate the score based on the rolls and the current frame index
    virtual int calculateScore( std::vector<std::unique_ptr<Frame>>const & frames)  = 0;

};

} // namespace Game

#endif // ISCoringStrategy_H