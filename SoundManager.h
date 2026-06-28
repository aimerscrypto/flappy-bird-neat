#pragma once
#include <SFML/Audio.hpp>

class SoundManager {
private:
    sf::SoundBuffer bufferWing;
    sf::SoundBuffer bufferPoint;
    sf::SoundBuffer bufferHit;
    sf::SoundBuffer bufferDie;

    sf::Sound soundWing;
    sf::Sound soundPoint;
    sf::Sound soundHit;
    sf::Sound soundDie;
    
    sf::Music bgMusic;

    SoundManager();

public:
    static SoundManager& getInstance();

    void playWing();
    void playPoint();
    void playHit();
    void playDie();

    void playMusic();
    void stopMusic();
};