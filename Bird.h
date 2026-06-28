#pragma once
#include "Entity.h"
#include"Animation.h"

class Bird : public Entity
{
private:
    int lives=3;
    float velocityY=0.f;
    float gravity = 900.f;
    float jumpStrength = 350.0f;
    Animation anim;

    float angle = 0.f;

public:
    Bird(float x, float y, int width, int height);

    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
    void jump();
    void respawn();

    int& getLives() { return lives; }
};