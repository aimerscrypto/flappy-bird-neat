#include"Animation.h"
#include "AssetLoader.h"

Animation::Animation(sf::Sprite& sprite, const std::string &path ,int frames, int frameWidth, int frameHeight, float speed)
    : sprite(sprite), frames(frames), frameWidth(frameWidth), frameHeight(frameHeight), speed(speed)
{
    AssetLoader::loadTexture(texture, path);
    texture.setRepeated(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
}

void Animation::update(float dt)
{
    timer += dt;

    if(timer>=speed)
    {
        timer = 0.f;
        current++;

        if(current>=frames)
            current = 0;

        sprite.setTextureRect(sf::IntRect(current*frameWidth, 0, frameWidth, frameHeight));
    }
}