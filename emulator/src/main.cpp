#include <iostream>
#include <SDL.h>
#include "framebuffer.h"

int SDL_main(int argc, char *argv[])
{
    std::cout << "Vexel Display Emulator Starting..." << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Vexel Display Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 768, 384, SDL_WINDOW_SHOWN);
    // each pixel gets 24x24 space. pixel will be 20x20, with a 2 border

    if (!window)
    {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    std::cout << "SDL Initialized Successfully!" << std::endl;

    bool running = true;

    // init a red frame buffer
    Framebuffer framebuffer(32, 16);
    Pixel red = {255, 0, 0};
    framebuffer.clear(red);

    while (running)
    {
        Uint32 frameStart = SDL_GetTicks();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // render pixels to the window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        for (int x = 0; x < framebuffer.width(); x++)
        {
            for (int y = 0; y < framebuffer.height(); y++)
            {
                Pixel pixel = framebuffer.getPixel(x, y);
                SDL_SetRenderDrawColor(renderer, pixel.red, pixel.green, pixel.blue, 255);
                SDL_Rect rect = {x * 24 + 2, y * 24 + 2, 20, 20};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
        SDL_RenderPresent(renderer);

        // cap the frame rate to 60 fps
        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 16)
        {
            SDL_Delay(16 - frameTime);
        }
    }

    SDL_Quit();

    return 0;
}