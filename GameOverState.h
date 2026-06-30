#pragma once
#include "GameState.h"
#include "SpriteNumber.h"
#include <SFML/Graphics.hpp>

class GameStateManager;

class GameOverState : public GameState {
private:
    sf::Texture     gameOverTexture;
    sf::Sprite      gameOverSprite;
    SpriteNumber    spriteNum;

    int finalScore;
    int highScore;

    GameStateManager* gsm = nullptr;

public:
    GameOverState(int score, int highScore);

    void handleInput(sf::Event event) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

    void setStateManager(GameStateManager* manager) override {
        gsm = manager;
    }
};