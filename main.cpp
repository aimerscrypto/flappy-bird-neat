#include"Game.h"
int main()
{
    srand(time(nullptr)); // Seed for random pipe positions
    Game game;
    game.run();
    return 0;
}