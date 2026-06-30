#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>

namespace AssetLoader
{
    inline void loadTexture(sf::Texture& tex, const std::string& path)
    {
        if (!tex.loadFromFile(path))
        {
            std::cerr << "[FATAL] Failed to load texture: " << path << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    inline void loadFont(sf::Font& font, const std::string& path)
    {
        if (!font.loadFromFile(path))
        {
            std::cerr << "[FATAL] Failed to load font: " << path << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    inline void loadSoundBuffer(sf::SoundBuffer& buf, const std::string& path)
    {
        if (!buf.loadFromFile(path))
        {
            std::cerr << "[FATAL] Failed to load sound: " << path << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    inline void openMusic(sf::Music& music, const std::string& path)
    {
        if (!music.openFromFile(path))
        {
            std::cerr << "[FATAL] Failed to open music: " << path << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}
