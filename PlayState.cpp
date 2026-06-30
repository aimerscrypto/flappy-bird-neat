#include "PlayState.h"
#include "Game.h"
#include "GameOverState.h"
#include "SoundManager.h"
#include "AssetLoader.h"
#include <fstream>

PlayState::PlayState()
    : bird(100, 300, 16, 16), score(0), bg(SCREEN_WIDTH, SCREEN_HEIGHT)
{
    loadHighScore();
    spawnPipes();

    SoundManager::getInstance().playMusic();
    AssetLoader::loadTexture(heartTexture, "Assets/Sprites/Player/heart.png");
    heartSprite.setTexture(heartTexture);
    heartSprite.setScale(0.2f, 0.2f);
}

void PlayState::handleInput(sf::Event event)
{
    bool shouldJump = false;

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        shouldJump = true;

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        shouldJump = true;

    if (event.type == sf::Event::TouchBegan && event.touch.finger == 0)
        shouldJump = true;

    if (shouldJump)
    {
        bird.jump();
        SoundManager::getInstance().playWing();
    }
}

void PlayState::spawnPipes()
{
    float gapSize = 150.0f;
    float centerY = rand() % 300 + 150; // random middle position

    pipes.push_back(std::make_unique<PipePair>(SCREEN_WIDTH, centerY, gapSize));
}

void PlayState::update(float dt)
{

    bg.update(dt);
    bird.update(dt);

    pipeSpawnTimer += dt;
    if (pipeSpawnTimer >= pipeSpawnInterval)
    {
        spawnPipes();
        pipeSpawnTimer = 0.0f;
    }

    for (auto &pipe : pipes)
    {
        pipe->update(dt);
    }

    // erase off-screen pipes
    if (!pipes.empty() && pipes.front()->isOffScreen())
    {
        pipes.erase(pipes.begin());
    }

    bool hitSomething = false;

    // ground or ceiling
    if (bird.getY() + bird.getHeight() * bird.getScale() > SCREEN_HEIGHT || bird.getY() < 0)
    {
        SoundManager::getInstance().playHit();
        hitSomething = true;
    }

    else // only check pipes if not hit
    {
        for (auto &pipe : pipes)
        {
            if (pipe->checkCollision(bird))
            {
                SoundManager::getInstance().playHit();
                hitSomething = true;
                break;
            }
            else if (pipe->checkScore(bird))
            {
                score++;
                SoundManager::getInstance().playPoint();
            }
        }
    }

    if (hitSomething)
    {
        bird.getLives()--;
        if (bird.getLives() <= 0)
        {
            SoundManager::getInstance().playDie();
            saveHighScore();
            gsm->changeState(std::make_unique<GameOverState>(score, highScore));
            return;
        }

        bird.respawn();
        pipes.clear();        // remove all pipes
        pipeSpawnTimer = 0.f; // reset spawn timer
        spawnPipes();         // spawn fresh pipe
    }
}

void PlayState::render(sf::RenderWindow &window)
{
    bg.render(window);
    bird.render(window);

    for (auto &pipe : pipes)
    {
        pipe->render(window);
    }

    // lives display
    for (int i = 0; i < bird.getLives(); ++i)
    {
        heartSprite.setPosition(SCREEN_WIDTH - (bird.getLives() - i) * (heartSprite.getGlobalBounds().width + 5), 10);
        window.draw(heartSprite);
    }

    // Draw score centered at top using digit sprites
    constexpr float DIGIT_SCALE = 2.5f;
    float scoreW = spriteNum.getWidth(score, DIGIT_SCALE);
    float scoreX = (SCREEN_WIDTH - scoreW) / 2.f;
    spriteNum.draw(window, score, scoreX, 10.f, DIGIT_SCALE);
}


void PlayState::loadHighScore()
{
    std::ifstream file("highscore.txt");
    if (file.is_open())
    {
        file >> highScore;
        file.close();
    }
}

void PlayState::saveHighScore()
{
    if (score > highScore)
    {
        std::ofstream file("highscore.txt");
        if (file.is_open())
        {
            file << score;
            file.close();
        }
    }
}