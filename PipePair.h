#pragma once
#include"Pipe.h"
class PipePair {
private:
    Pipe topPipe;
    Pipe bottomPipe;

    bool hasScored = false;
    static int nextFrame;

public:
    PipePair(float x, float gapCenterY, float gapSize);

    void update(float dt);
    void render(sf::RenderWindow& window);

    bool checkCollision(const Bird& bird) const;
    bool checkScore(const Bird& bird);

    bool isOffScreen() const;
};