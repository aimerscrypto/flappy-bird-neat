#pragma once
#include<SFML/Graphics.hpp>

class Background
{
private:
    static const int BG_COUNT=9;

    sf::Texture textures[BG_COUNT];
    sf::Sprite spriteA;
    sf::Sprite spriteB;

    int currentIndex=0;
    
    float scrollX=0.0f;
    float speed=100.0f;
    float screenWidth=800.0f;
    float screenHeight=600.0f;

public:
    Background(float width, float height);

    void update(float dt);
    void render(sf::RenderWindow& window);
private:
    void applyTexture(sf::Sprite & sprite,int index);
};