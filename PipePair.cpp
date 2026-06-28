#include "PipePair.h"

int PipePair::nextFrame = 0;

PipePair::PipePair(float x, float gapCenterY, float gapSize) : topPipe(x, 0, 32, 300,nextFrame), bottomPipe(x, 0, 32, 300,nextFrame)
{
    nextFrame = (nextFrame + 1) % 8; // Cycle through frames for variety

    
    float halfGap = gapSize / 2.0f;
    //top pipe
    topPipe.setY(gapCenterY - halfGap - topPipe.getHeight() * topPipe.getScale());
    topPipe.setFlipped(true);

    //bottom pipe
    bottomPipe.setY(gapCenterY + halfGap);
}

void PipePair::update(float dt)
{
    topPipe.update(dt);
    bottomPipe.update(dt);
}

void PipePair::render(sf::RenderWindow& window)
{
    topPipe.render(window);
    bottomPipe.render(window);
}

bool PipePair::checkCollision(const Bird& bird) const
{
    return topPipe.collidesWith(bird) || bottomPipe.collidesWith(bird);
}

bool PipePair::checkScore(const Bird& bird)
{
    if (!hasScored && bird.getX() > topPipe.getX() + topPipe.getWidth()*topPipe.getScale())
    {
        hasScored = true;
        return true;
    }
    return false;
}

bool PipePair::isOffScreen() const
{
    return topPipe.getX() + topPipe.getWidth() * topPipe.getScale() < 0;
}