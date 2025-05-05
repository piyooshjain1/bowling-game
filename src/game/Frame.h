#ifndef FRAME_H
#define FRAME_H

class Frame {
private:
    int pinsKnockedDown[2]; // Array to hold the number of pins knocked down in two rolls
    int rollCount; // Count of rolls in the frame

public:
    Frame(); // Constructor to initialize the frame
    void roll(int pins); // Method to record a roll
    int score() const; // Method to calculate the score of the frame
    bool isComplete() const; // Method to check if the frame is complete
};

#endif // FRAME_H