#include"Game.h"
#include "MenuState.h"
Game::Game(): window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird")
{
    gsm.changeState(std::make_unique<MenuState>());
}

void Game::run() 
{
    sf::Clock clock;
    while (window.isOpen()) 
    {
        float dt = clock.restart().asSeconds();
        if(dt > 0.1f) 
        {
            dt = 0.1f; // Cap delta time to avoid large jumps
        }
        
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() 
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window.close();
        }

        gsm.handleInput(event);
    }
}

void Game::update(float dt) 
{
    gsm.update(dt);
}

void Game::render() 
{
    window.clear();
    gsm.render(window);
    window.display();
}