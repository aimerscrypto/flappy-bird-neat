#include "SpriteNumber.h"
#include "AssetLoader.h"
#include <vector>
#include <algorithm>

SpriteNumber::SpriteNumber()
{
    for (int i = 0; i < 10; ++i)
    {
        AssetLoader::loadTexture(textures[i], "Assets/Sprites/UI/Numbers/" + std::to_string(i) + ".png");
        sprites[i].setTexture(textures[i]);
    }
}

float SpriteNumber::getWidth(int number, float scale) const
{
    // Collect digits
    std::vector<int> digits;
    int n = (number == 0) ? 0 : std::abs(number);
    if (number == 0) {
        digits.push_back(0);
    } else {
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        std::reverse(digits.begin(), digits.end());
    }

    float total = 0.f;
    for (int d : digits)
        total += textures[d].getSize().x * scale + 2.f; // 2px gap
    return total > 0.f ? total - 2.f : 0.f;             // trim trailing gap
}

void SpriteNumber::draw(sf::RenderWindow& window, int number, float x, float y, float scale)
{
    // Collect digits
    std::vector<int> digits;
    int n = std::abs(number);
    if (n == 0) {
        digits.push_back(0);
    } else {
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        std::reverse(digits.begin(), digits.end());
    }

    float cursorX = x;
    for (int d : digits)
    {
        sf::Sprite& spr = sprites[d];
        spr.setScale(scale, scale);
        spr.setPosition(cursorX, y);
        window.draw(spr);
        cursorX += textures[d].getSize().x * scale + 2.f; // 2px gap between digits
    }
}
