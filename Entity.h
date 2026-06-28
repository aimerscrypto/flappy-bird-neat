#pragma once

#include<SFML/Graphics.hpp>

class Entity{
    protected:
        float x, y;
        int width, height;
        sf::Sprite sprite;
        float scale=2.0f;

    public:
        Entity(float x, float y, int width, int height) : x(x), y(y), width(width), height(height) {};
        virtual ~Entity(){}

        virtual void update(float dt) = 0;
        virtual void render(sf::RenderWindow& window) = 0;

        float getX() const { return x; }
        float getY() const { return y; }
        int getWidth() const { return width; }
        int getHeight() const { return height; }
        float getScale() const { return scale; }

        void setX(float newX) { x = newX; }
        void setY(float newY) { y = newY; }
};