#include "SoundManager.h"
#include "AssetLoader.h"

SoundManager::SoundManager()
{
    AssetLoader::loadSoundBuffer(bufferWing, "Assets/audio/wing.wav");
    AssetLoader::loadSoundBuffer(bufferPoint, "Assets/audio/point.wav");
    AssetLoader::loadSoundBuffer(bufferHit, "Assets/audio/hit.wav");
    AssetLoader::loadSoundBuffer(bufferDie, "Assets/audio/die.wav");
    AssetLoader::openMusic(bgMusic, "Assets/audio/music.mp3");
    
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