#include "Frame.h"

Frame::Frame() : pinsKnockedDown(0) {}

void Frame::setPinsKnockedDown(int pins) {
    pinsKnockedDown = pins;
}

int Frame::getPinsKnockedDown() const {
    return pinsKnockedDown;
}

int Frame::calculateScore() const {
    return pinsKnockedDown; // Simplified scoring for a single frame
}