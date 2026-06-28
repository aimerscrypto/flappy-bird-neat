#pragma once
#include"Entity.h"
#include"Bird.h"

class Pipe:public Entity{
private:
    bool flipped=false;
    float speed=200.0f;
    sf::Texture texture;
    
public:
    Pipe(float x, float y, int width, int height, int frameIndex);
    
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

    void setFlipped(bool flipped);
    bool isFlipped() const;

    bool collidesWith(const Bird& bird) const;
};