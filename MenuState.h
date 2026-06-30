#pragma once
#include "GameState.h"
#include "Bird.h"
#include "Background.h"
#include <SFML/Graphics.hpp>

class GameStateManager;

class MenuState : public GameState {
private:
    Background bg;
    Bird bird;
    GameStateManager* gsm = nullptr;

    // message.png — contains FlappyBird title + Get Ready + tap instruction
    sf::Texture messageTexture;
    sf::Sprite  messageSprite;

    // Best score (kept as plain text, bottom-left)
    sf::Font font;
    sf::Text bestText;

    float timer    = 0.0f;
    int   highScore = 0;

public:
    MenuState();

    void handleInput(sf::Event event) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

    void setStateManager(GameStateManager* manager) override {
        gsm = manager;
    }
};
