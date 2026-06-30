#pragma once
#include "GameState.h"
#include "Bird.h"
#include "PipePair.h"
#include "Background.h"
#include "SpriteNumber.h"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class GameStateManager;

class PlayState : public GameState {
    private:
        Background bg;
        Bird bird;
        std::vector<std::unique_ptr<PipePair>> pipes;
        GameStateManager* gsm = nullptr;

        int score = 0;

        float pipeSpawnTimer    = 0.0f;
        float pipeSpawnInterval = 1.5f;

        SpriteNumber spriteNum;

        // Heart icon for lives
        sf::Texture heartTexture;
        sf::Sprite  heartSprite;

        int highScore = 0;

    public:
        PlayState();

        void handleInput(sf::Event event) override;
        void update(float dt) override;
        void render(sf::RenderWindow& window) override;

        void setStateManager(GameStateManager* manager) override {
            gsm = manager;
        }

        void spawnPipes();

        void loadHighScore();
        void saveHighScore();
};