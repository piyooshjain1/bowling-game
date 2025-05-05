#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "ScoreObserver.h"

class Subject {
public:
    virtual ~Subject() {}

    void attach(ScoreObserver* observer) {
        observers.push_back(observer);
    }

    void detach(ScoreObserver* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() {
        for (ScoreObserver* observer : observers) {
            observer->update();
        }
    }

private:
    std::vector<ScoreObserver*> observers;
};

#endif // SUBJECT_H