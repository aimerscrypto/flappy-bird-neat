#pragma once
#include <memory>
#include "GameState.h"

class GameStateManager {
private:
    std::unique_ptr<GameState> currentState;

public:
    void changeState(std::unique_ptr<GameState> newState);

    void handleInput(sf::Event event);
    void update(float dt);
    void render(sf::RenderWindow& window);

};