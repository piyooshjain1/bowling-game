#ifndef SCOREOBSERVER_H
#define SCOREOBSERVER_H

#include <string>

class ScoreObserver {
public:
    virtual void updateScore(const std::string& playerName, int newScore) = 0;
    virtual ~ScoreObserver() {}
};

#endif // SCOREOBSERVER_H