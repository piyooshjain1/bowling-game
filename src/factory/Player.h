#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"
#include <IScoringStrategy.h>

namespace Game {

class Player :public Person{
private:
    std::vector<std::unique_ptr<Frame>> frames;
    int currentFrameIndex;
public:
    explicit Player(const std::string& name);
    int calculateScore(const std::shared_ptr<IScoringStrategy> scoringStrategy) ;
    void roll(int pins);
    bool isGameComplete() const;
};

} // namespace Game

#endif // PLAYER_H