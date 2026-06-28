#include "GameOverState.h"
#include "Game.h"
#include "GameStateManager.h"
#include "PlayState.h"
#include "SoundManager.h"

GameOverState::GameOverState(int score, int highScore)
{
    SoundManager::getInstance().stopMusic();
    finalScore = score;
    this->highScore = highScore;

    font.loadFromFile("Assets/Fonts/arial.ttf");

    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(200, 250);
}

void GameOverState::handleInput(sf::Event event)
{
    if (!gsm)
        return;

    bool shouldRestart = false;

    if (event.type == sf::Event::KeyPressed &&
        (event.key.code == sf::Keyboard::R || event.key.code == sf::Keyboard::Space))
    {
        shouldRestart = true;
    }

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        shouldRestart = true;
    }

    if(event.type == sf::Event::TouchBegan && event.touch.finger == 0)
    {
        shouldRestart = true;
    }

    if(shouldRestart)
    {
        gsm->changeState(std::make_unique<PlayState>());
    }
}

void GameOverState::update(float dt) {}

void GameOverState::render(sf::RenderWindow &window)
{
    text.setString("Game Over\nScore: " + std::to_string(finalScore) +
                   "\nBest: " + std::to_string(highScore) +
                   "\nTap or Space to Restart");
    window.draw(text);
}