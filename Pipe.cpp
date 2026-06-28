#include "Pipe.h"
#include "Bird.h"

const std::string pipePath = "Assets/Sprites/Tiles/Style 1/PipeStyle1.png";

Pipe::Pipe(float x, float y, int width, int height,int frameIndex) : Entity(x, y, width, height)
{
    texture.loadFromFile(pipePath);
    texture.setRepeated(true);
    sprite.setTexture(texture);
    
    sprite.setTextureRect(sf::IntRect(frameIndex * width, 0, width, height));
    sprite.setScale(scale, scale);
}

void Pipe::update(float dt)
{
    x -= speed * dt;
}

void Pipe::render(sf::RenderWindow &window)
{
    if (flipped)
    {
        sprite.setOrigin(0, height);
        sprite.setScale(scale, -scale);
    }
    else
    {
        sprite.setOrigin(0, 0);
        sprite.setScale(scale, scale);
    }

    sprite.setPosition(x, y);
    window.draw(sprite);
}

void Pipe::setFlipped(bool flip)
{
    flipped = flip;
}

bool Pipe::isFlipped() const
{
    return flipped;
}

bool Pipe::collidesWith(const Bird &bird) const
{
    float pw = width * scale;
    float ph = height * scale;
    float bw = bird.getWidth() * bird.getScale();
    float bh = bird.getHeight() * bird.getScale();

    float bLeft = bird.getX()-bw / 2.f;
    float bTop = bird.getY()-bh / 2.f;

    return bLeft < x + pw &&
           bLeft +bw > x &&
           bTop < y + ph &&
           bTop +bh > y;
}