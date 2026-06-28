#include "SoundManager.h"

SoundManager::SoundManager()
{
    bufferWing.loadFromFile("Assets/audio/wing.wav");
    bufferPoint.loadFromFile("Assets/audio/point.wav");
    bufferHit.loadFromFile("Assets/audio/hit.wav");
    bufferDie.loadFromFile("Assets/audio/die.wav");
    bgMusic.openFromFile("Assets/audio/music.mp3");
    
    bgMusic.setVolume(100);
    bgMusic.setLoop(true);

    soundWing.setBuffer(bufferWing);
    soundPoint.setBuffer(bufferPoint);
    soundHit.setBuffer(bufferHit);
    soundDie.setBuffer(bufferDie);
}

SoundManager& SoundManager::getInstance()
{
    static SoundManager instance;
    return instance;
}

void SoundManager::playWing()  { soundWing.play(); }
void SoundManager::playPoint() { soundPoint.play(); }
void SoundManager::playHit()   { soundHit.play(); }
void SoundManager::playDie()   { soundDie.play(); }

void SoundManager::playMusic() 
{

    bgMusic.play();
}
void SoundManager::stopMusic() { bgMusic.stop(); }