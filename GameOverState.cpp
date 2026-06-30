#include "GameOverState.h"
#include "Game.h"
#include "GameStateManager.h"
#include "PlayState.h"
#include "MenuState.h"
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
    gameOverSprite.setPosition(SCREEN_WIDTH / 2.f, 150.f);

    // Load font and set up score/best labels
    AssetLoader::loadFont(font, "Assets/Fonts/arial.ttf");

    scoreLabel.setFont(font);
    scoreLabel.setString("SCORE");
    scoreLabel.setCharacterSize(20);
    scoreLabel.setFillColor(sf::Color(220, 220, 220));
    scoreLabel.setOutlineColor(sf::Color::Black);
    scoreLabel.setOutlineThickness(1.5f);
    scoreLabel.setStyle(sf::Text::Bold);
    // Center origin horizontally/vertically for precise positioning
    sf::FloatRect scoreBounds = scoreLabel.getLocalBounds();
    scoreLabel.setOrigin(scoreBounds.left + scoreBounds.width / 2.f, scoreBounds.top + scoreBounds.height / 2.f);
    scoreLabel.setPosition(SCREEN_WIDTH / 2.f, 230.f);

    highScoreLabel.setFont(font);
    highScoreLabel.setString("BEST");
    highScoreLabel.setCharacterSize(20);
    highScoreLabel.setFillColor(sf::Color(220, 220, 220));
    highScoreLabel.setOutlineColor(sf::Color::Black);
    highScoreLabel.setOutlineThickness(1.5f);
    highScoreLabel.setStyle(sf::Text::Bold);
    // Center origin horizontally/vertically for precise positioning
    sf::FloatRect bestBounds = highScoreLabel.getLocalBounds();
    highScoreLabel.setOrigin(bestBounds.left + bestBounds.width / 2.f, bestBounds.top + bestBounds.height / 2.f);
    highScoreLabel.setPosition(SCREEN_WIDTH / 2.f, 385.f);

    // Set up restart instruction label
    restartLabel.setFont(font);
    restartLabel.setString("Press 'R', 'Space' or Click to Continue");
    restartLabel.setCharacterSize(18);
    restartLabel.setFillColor(sf::Color(180, 180, 180));
    restartLabel.setOutlineColor(sf::Color::Black);
    restartLabel.setOutlineThickness(1.2f);
    sf::FloatRect restartBounds = restartLabel.getLocalBounds();
    restartLabel.setOrigin(restartBounds.left + restartBounds.width / 2.f, restartBounds.top + restartBounds.height / 2.f);
    restartLabel.setPosition(SCREEN_WIDTH / 2.f, 530.f);
}

void GameOverState::handleInput(sf::Event event)
{
    if (!gsm || inputCooldownTimer > 0.0f)
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
        gsm->changeState(std::make_unique<MenuState>());
}

void GameOverState::update(float dt)
{
    if (inputCooldownTimer > 0.0f)
    {
        inputCooldownTimer -= dt;
    }
}

void GameOverState::render(sf::RenderWindow& window)
{
    // Draw game over banner
    window.draw(gameOverSprite);

    // Draw SCORE label and current score using digit sprites
    window.draw(scoreLabel);
    constexpr float DIGIT_SCALE = 2.5f;
    float scoreW = spriteNum.getWidth(finalScore, DIGIT_SCALE);
    float scoreX = (SCREEN_WIDTH - scoreW) / 2.f;
    float scoreY = 260.f;
    spriteNum.draw(window, finalScore, scoreX, scoreY, DIGIT_SCALE);

    // Draw BEST label and high score using digit sprites
    window.draw(highScoreLabel);
    float bestW = spriteNum.getWidth(highScore, DIGIT_SCALE);
    float bestX = (SCREEN_WIDTH - bestW) / 2.f;
    float bestY = 415.f;
    spriteNum.draw(window, highScore, bestX, bestY, DIGIT_SCALE);

    // Draw restart instruction text (only once cooldown is active/finished)
    if (inputCooldownTimer <= 0.0f)
    {
        window.draw(restartLabel);
    }
}