#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& name);
    
    void setScore(int score);
    int getScore() const;
    std::string getName() const;

private:
    std::string name;
    int score;
};

#endif // PLAYER_H