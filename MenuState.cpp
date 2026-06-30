#include "MenuState.h"
#include "Game.h"
#include "AssetLoader.h"
#include "GameStateManager.h"
#include "PlayState.h"
#include <fstream>
#include <cmath>

MenuState::MenuState()
    : bird(100, 300, 16, 16), bg(SCREEN_WIDTH, SCREEN_HEIGHT)
{
    // Load high score
    std::ifstream file("highscore.txt");
    if (file.is_open())
    {
        file >> highScore;
        file.close();
    }

    // Load message.png (title + get ready + tap instruction)
    AssetLoader::loadTexture(messageTexture, "Assets/Sprites/UI/message.png");
    messageSprite.setTexture(messageTexture);

    // Scale sprite to fit nicely — cap at 60% of screen width
    float texW = static_cast<float>(messageTexture.getSize().x);
    float texH = static_cast<float>(messageTexture.getSize().y);
    float targetW = SCREEN_WIDTH * 0.60f;
    float scl = targetW / texW;
    messageSprite.setScale(scl, scl);

    // Center origin so the hover bob and position are clean
    messageSprite.setOrigin(texW / 2.f, texH / 2.f);
    messageSprite.setPosition(SCREEN_WIDTH / 2.f, 220.f);

    // Best score text — bottom-left, small and unobtrusive
    AssetLoader::loadFont(font, "Assets/Fonts/arial.ttf");
    bestText.setFont(font);
    bestText.setString("Best: " + std::to_string(highScore));
    bestText.setCharacterSize(22);
    bestText.setFillColor(sf::Color::White);
    bestText.setOutlineColor(sf::Color::Black);
    bestText.setOutlineThickness(1.5f);
    bestText.setStyle(sf::Text::Bold);
    bestText.setPosition(16.f, SCREEN_HEIGHT - 44.f);
}

void MenuState::handleInput(sf::Event event)
{
    if (!gsm)
        return;

    bool shouldStart = false;

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        shouldStart = true;

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        shouldStart = true;

    if (event.type == sf::Event::TouchBegan && event.touch.finger == 0)
        shouldStart = true;

    if (shouldStart)
        gsm->changeState(std::make_unique<PlayState>());
}

void MenuState::update(float dt)
{
    timer += dt;
    bg.update(dt);

    // Hover bird: reset gravity each frame, then override Y with sin wave
    bird.respawn();
    bird.update(dt);
    bird.setY(300.f + std::sin(timer * 5.f) * 15.f);

    // Gentle vertical bob for the message sprite
    messageSprite.setPosition(SCREEN_WIDTH / 2.f, 220.f + std::sin(timer * 2.5f) * 6.f);
}

void MenuState::render(sf::RenderWindow& window)
{
    bg.render(window);
    bird.render(window);

    window.draw(messageSprite);
    window.draw(bestText);
}
