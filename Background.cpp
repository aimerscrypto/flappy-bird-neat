#include "Background.h"
#include "AssetLoader.h"

Background::Background(float width, float height):screenWidth(width), screenHeight(height)
{
    // Load textures
    for (int i = 0; i < BG_COUNT; ++i)
    {
        std::string filePath = "Assets/Sprites/Background/Background" + std::to_string(i+1) + ".png";
        AssetLoader::loadTexture(textures[i], filePath);
    }

    // Initialize sprites
    applyTexture(spriteA, currentIndex);
    applyTexture(spriteB, (currentIndex + 1) % BG_COUNT);

    spriteA.setPosition(0.0f, 0.0f);
    spriteB.setPosition(screenWidth, 0.0f);
}

void Background::applyTexture(sf::Sprite & sprite, int index)
{
    if (index >= 0 && index < BG_COUNT)
    {
        sprite.setTexture(textures[index]);
        sprite.setScale(screenWidth / textures[index].getSize().x, screenHeight / textures[index].getSize().y);
    }
}

void Background::update(float dt)
{
    scrollX -= speed * dt;

    if (scrollX <= -screenWidth)
    {
        scrollX += screenWidth;
        currentIndex = (currentIndex + 1) % BG_COUNT;

        applyTexture(spriteA, currentIndex);
        applyTexture(spriteB, (currentIndex + 1) % BG_COUNT);
    }

    spriteA.setPosition(scrollX, 0.0f);
    spriteB.setPosition(scrollX + screenWidth, 0.0f);
}

void Background::render(sf::RenderWindow& window)
{
    window.draw(spriteA);
    window.draw(spriteB);
}