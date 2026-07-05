#include <iostream>
#include <SDL.h>

int SDL_main(int argc, char *argv[])
{
    std::cout << "Vexel Display Emulator Starting..." << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "SDL Initialized Successfully!" << std::endl;

    SDL_Quit();

    return 0;
}