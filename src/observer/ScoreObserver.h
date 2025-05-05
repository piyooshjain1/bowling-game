#ifndef SCOREOBSERVER_H
#define SCOREOBSERVER_H

#include <iostream>
#include "Subject.h"

class ScoreObserver {
public:
    virtual void update(int score) = 0;
    virtual ~ScoreObserver() {}
};

#endif // SCOREOBSERVER_H