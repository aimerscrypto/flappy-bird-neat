#include"GameStateManager.h"

void GameStateManager::changeState(std::unique_ptr<GameState> newState)
{
    newState->setStateManager(this); // Set the state manager for the new state
    currentState = std::move(newState);
}

void GameStateManager::handleInput(sf::Event event)
{
    if (currentState) {
        currentState->handleInput(event);
    }
}

void GameStateManager::update(float dt)
{
    if (currentState) {
        currentState->update(dt);
    }
}

void GameStateManager::render(sf::RenderWindow& window)
{
    if (currentState) {
        currentState->render(window);
    }
}

