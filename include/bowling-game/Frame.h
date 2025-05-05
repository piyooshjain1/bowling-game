#ifndef FRAME_H
#define FRAME_H

class Frame {
public:
    Frame();
    void setPinsKnockedDown(int pins);
    int getPinsKnockedDown() const;
    int calculateScore() const;

private:
    int pinsKnockedDown;
};

#endif // FRAME_H