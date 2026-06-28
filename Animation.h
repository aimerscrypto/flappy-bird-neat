#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
    sf::Texture texture;
    sf::Sprite& sprite;

    int frames;
    int frameWidth;
    int frameHeight;

    float timer = 0.f;
    float speed;

    int current = 0;

public:
    Animation(sf::Sprite& sprite,const std::string &path, int frames=4, int frameWidth=64/4, int frameHeight=16, float speed=0.1f);

    void update(float dt);

};