#include "Frame.h"
#include "../utils/Logger.h" // Include the Logger utility
#include <stdexcept>

Frame::Frame(bool isTenthFrame) : rollCount(0), isTenthFrame(isTenthFrame) {
    Logger::logInfo() << "Initializing Frame. Is Tenth Frame: " << isTenthFrame;
    pinsKnockedDown[0] = 0;
    pinsKnockedDown[1] = 0;
    pinsKnockedDown[2] = 0; // For the 10th frame
}

void Frame::roll(int pins) {
    Logger::logInfo() << "Rolling " << pins << " pins.";
    if (pins < 0 || pins > 10) {
        Logger::logError() << "Error: Pins must be between 0 and 10.";
        throw std::invalid_argument("Pins must be between 0 and 10");
    }
    if (rollCount >= (isTenthFrame ? 3 : 2) || isComplete()) {
        Logger::logError() << "Error: Cannot roll more than allowed in a frame.";
        throw std::logic_error("Cannot roll more than allowed in a frame");
    }
    if (!isTenthFrame && rollCount == 1 && pinsKnockedDown[0] + pins > 10) {
        Logger::logError() << "Error: Total pins in a frame cannot exceed 10.";
        throw std::invalid_argument("Total pins in a frame cannot exceed 10");
    }
    pinsKnockedDown[rollCount++] = pins;
    Logger::logInfo() << "Roll " << rollCount << ": " << pins << " pins knocked down.";
}

bool Frame::isComplete() const {
    bool complete = false;
    if (isTenthFrame) {
        complete = rollCount == 3 || (rollCount == 2 && pinsKnockedDown[0] + pinsKnockedDown[1] < 10);
    } else {
        complete = rollCount == 2 || isStrike();
    }
    Logger::logInfo() << "Checking if frame is complete: " << complete;
    return complete;
}

bool Frame::isStrike() const {
    bool strike = pinsKnockedDown[0] == 10;
    Logger::logInfo() << "Checking if frame is a strike: " << strike;
    return strike;
}

bool Frame::isSpare() const {
    bool spare = !isStrike() && (pinsKnockedDown[0] + pinsKnockedDown[1] == 10);
    Logger::logInfo() << "Checking if frame is a spare: " << spare;
    return spare;
}

int Frame::getFirstRoll() const {
    Logger::logInfo() << "Getting first roll: " << pinsKnockedDown[0];
    return pinsKnockedDown[0];
}

int Frame::getSecondRoll() const {
    Logger::logInfo() << "Getting second roll: " << pinsKnockedDown[1];
    return pinsKnockedDown[1];
}

int Frame::getThirdRoll() const {
    Logger::logInfo() << "Getting third roll: " << pinsKnockedDown[2];
    return pinsKnockedDown[2];
}