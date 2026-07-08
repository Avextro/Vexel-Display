#include "application.h"
#include <iostream>
#include <SDL.h>
#include "vexel_renderer.h"

Application::Application()

{
}

bool Application::initialise()
{
    std::cout << "Vexel Display Emulator Starting..." << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window_ = SDL_CreateWindow("Vexel Display Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 768, 384, SDL_WINDOW_SHOWN);
    // each pixel gets 24x24 space. pixel will be 20x20, with a 2 border

    if (!window_)
    {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_)
    {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window_);
        SDL_Quit();
        return false;
    }

    std::cout << "SDL Initialized Successfully!" << std::endl;
    initialised_ = true;
    return true;
}

int Application::run()
{
    if (!initialised_)
    {
        std::cerr << "Application not initialized. Call initialise() before run()." << std::endl;
        return -1;
    }

    while (running_)
    {
        handleEvents();
        update();
        render();
    }

    return 0;
}

Application::~Application()
{
    if (renderer_)
    {
        SDL_DestroyRenderer(renderer_);
    }
    if (window_)
    {
        SDL_DestroyWindow(window_);
    }
    SDL_Quit();
}