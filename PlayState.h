#pragma once
#include"GameState.h"
#include"Bird.h"
#include"PipePair.h"
#include"Background.h"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class GameStateManager;

class PlayState : public GameState {
    private:
        Background bg;
        Bird bird;
        std::vector<std::unique_ptr<PipePair>> pipes;
        GameStateManager* gsm=nullptr; // Pointer to the GameStateManager

        int score = 0;

        float pipeSpawnTimer = 0.0f;
        float pipeSpawnInterval = 1.5f; // Time interval between pipe spawns in seconds

        sf::Font font;
        sf::Text scoreText;

        // Heart icon for lives
        sf::Texture heartTexture;
        sf::Sprite heartSprite;

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