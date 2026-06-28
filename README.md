# Flappy Bird + NEAT

A Flappy Bird clone built in C++ using SFML 2.x — with NEAT (NeuroEvolution of Augmenting Topologies) AI coming soon.

## Features

- Smooth scrolling parallax backgrounds
- Animated bird with rotation
- Randomized pipe generation
- Lives system (3 lives)
- Score + high score tracking
- Sound effects and background music
- Game over / restart screen

## Dependencies

- [SFML 2.x](https://www.sfml-dev.org/download/sfml/2.6.2/) — Graphics, Audio, Window
- C++17 or later
- Visual Studio 2022 (or any C++ compiler)

## Building

### Visual Studio

1. Clone the repo:
   ```
   git clone https://github.com/aimerscrypto/flappy-bird-neat.git
   ```
2. Download SFML 2.x from https://www.sfml-dev.org and extract it somewhere (e.g. `C:/SFML/`)
3. Create a new **Empty C++ Project** in Visual Studio
4. Add all `.cpp` and `.h` files to the project
5. Configure project properties:
   - **C/C++ → Additional Include Directories** → `C:/SFML/include`
   - **Linker → Additional Library Directories** → `C:/SFML/lib`
   - **Linker → Additional Dependencies** → add:
     ```
     sfml-graphics.lib
     sfml-window.lib
     sfml-system.lib
     sfml-audio.lib
     ```
   - For Debug builds, use `-d` variants (e.g. `sfml-graphics-d.lib`)
6. Copy SFML `.dll` files into your project output folder (same folder as the `.exe`)
7. Make sure the `Assets/` folder is in your working directory
8. Build and run

### CMake (coming soon)

A `CMakeLists.txt` will be added in a future update.

## Assets

All game assets (sprites, audio, fonts) are in the `Assets/` folder and are included in the repo.

## Roadmap

- [x] Core gameplay
- [x] Lives system
- [x] High score
- [x] Sound effects
- [ ] Main menu / start screen
- [ ] Pause state
- [ ] Difficulty scaling
- [ ] Ground sprite
- [ ] NEAT AI agent

## License

MIT
