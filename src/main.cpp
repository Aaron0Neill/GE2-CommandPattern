#include "game.h"
#include <cstdio>

int main( int argc, char* argv[] )
{

    Game* game = new Game();
    game->init("DGPP Skelatol", 150,250,1366,768, SDL_WINDOW_INPUT_FOCUS);

    while (game->isRunning())
    {
        game->handleInputs();
        game->update();
        game->render();
    }
    
    game->cleanup();
    return 0;
}