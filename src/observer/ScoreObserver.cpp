#include "ScoreObserver.h"
#include "Subject.h"
#include <iostream>

void ScoreObserver::update(int score) {
    std::cout << "Score updated to: " << score << std::endl;
}

void ScoreObserver::subscribe(Subject* subject) {
    subject->attach(this);
}

void ScoreObserver::unsubscribe(Subject* subject) {
    subject->detach(this);
}