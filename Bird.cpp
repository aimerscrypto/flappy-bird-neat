#include"Bird.h"

const std::string bird1Path = "Assets/Sprites/Player/StyleBird1/Bird1-1.png";

Bird::Bird(float x, float y, int width, int height)
: Entity(x, y, width, height), anim(sprite, bird1Path)
{
    sprite.setOrigin(width / 2.f, height / 2.f);
    sprite.setScale(scale, scale);
}

void Bird::respawn() 
{
    x = 100.0f; 
    y = 300.0f; 
    velocityY = 0.0f; 
}


void Bird::update(float dt)
 {
    velocityY += gravity * dt;
    y += velocityY * dt;

    angle=velocityY*0.15f;
    if(angle<-25.f)
        angle=-25.f;
    if(angle>90.f)
        angle=90.f;

    anim.update(dt);
}

void Bird::render(sf::RenderWindow& window) {
    sprite.setRotation(angle);
    sprite.setPosition(x, y);
    window.draw(sprite);
}

void Bird::jump() {
	velocityY = -jumpStrength;
}
