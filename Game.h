#pragma once
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Game {
private:
    sf::RenderWindow window;
    GameStateManager gsm;

public:
    Game();
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();
};