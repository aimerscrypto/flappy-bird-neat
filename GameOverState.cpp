#include "GameOverState.h"
#include "Game.h"
#include "GameStateManager.h"
#include "PlayState.h"
#include "SoundManager.h"
#include "AssetLoader.h"

GameOverState::GameOverState(int score, int highScore)
    : finalScore(score), highScore(highScore)
{
    SoundManager::getInstance().stopMusic();

    // Load and center the gameover.png sprite
    AssetLoader::loadTexture(gameOverTexture, "Assets/Sprites/UI/gameover.png");
    gameOverSprite.setTexture(gameOverTexture);

    float texW = static_cast<float>(gameOverTexture.getSize().x);
    float texH = static_cast<float>(gameOverTexture.getSize().y);

    // Scale so it fits nicely — cap at 55% of screen width
    float scl = (SCREEN_WIDTH * 0.55f) / texW;
    gameOverSprite.setScale(scl, scl);

    // Center horizontally, place in upper-middle area
    gameOverSprite.setOrigin(texW / 2.f, texH / 2.f);
    gameOverSprite.setPosition(SCREEN_WIDTH / 2.f, 200.f);
}

void GameOverState::handleInput(sf::Event event)
{
    if (!gsm)
        return;

    bool shouldRestart = false;

    if (event.type == sf::Event::KeyPressed &&
        (event.key.code == sf::Keyboard::R || event.key.code == sf::Keyboard::Space))
        shouldRestart = true;

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        shouldRestart = true;

    if (event.type == sf::Event::TouchBegan && event.touch.finger == 0)
        shouldRestart = true;

    if (shouldRestart)
        gsm->changeState(std::make_unique<PlayState>());
}

void GameOverState::update(float dt) {}

void GameOverState::render(sf::RenderWindow& window)
{
    // Draw game over banner
    window.draw(gameOverSprite);

    // Draw score centered below banner using digit sprites
    // Scale digits at 3x for visibility
    constexpr float DIGIT_SCALE = 3.f;
    float scoreW = spriteNum.getWidth(finalScore, DIGIT_SCALE);
    float scoreX = (SCREEN_WIDTH - scoreW) / 2.f;
    float scoreY = 340.f;
    spriteNum.draw(window, finalScore, scoreX, scoreY, DIGIT_SCALE);
}