#pragma once
#include <SFML/Graphics.hpp>
#include <string>

// Renders integer numbers using individual digit sprite assets
// (Assets/Sprites/UI/Numbers/0.png through 9.png)
class SpriteNumber {
private:
    sf::Texture textures[10];
    sf::Sprite  sprites[10];

public:
    SpriteNumber();

    // Draw 'number' starting at (x, y) with uniform scale, left-to-right.
    void draw(sf::RenderWindow& window, int number, float x, float y, float scale = 1.0f);

    // Returns the total pixel width of 'number' rendered at the given scale
    float getWidth(int number, float scale = 1.0f) const;
};
