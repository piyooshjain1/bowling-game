#ifndef FRAME_H
#define FRAME_H

class Frame {
private:
    int pinsKnockedDown[3]; // Array to hold the number of pins knocked down (up to 3 rolls for the 10th frame)
    int rollCount;
    bool isTenthFrame;

public:
    Frame(bool isTenthFrame = false);
    void roll(int pins);
    bool isComplete() const;
    bool isStrike() const;
    bool isSpare() const;
    int getFirstRoll() const;
    int getSecondRoll() const;
    int getThirdRoll() const; // For the 10th frame
};

#endif // FRAME_H