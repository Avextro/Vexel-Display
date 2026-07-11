#include "application.h"
#include <iostream>
#include <SDL.h>
#include "vexel_renderer.h"

Application::Application()
    : displayConfig_{}, animationController_{displayConfig_}
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

    window_ = SDL_CreateWindow("Vexel Display Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayConfig_.textureWidth(), displayConfig_.textureHeight(), SDL_WINDOW_SHOWN);
    // each pixel gets 24x24 space. pixel will be 20x20, with a 2 border

    if (!window_)
    {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    sdlRenderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!sdlRenderer_)
    {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window_);
        SDL_Quit();
        return false;
    }

    renderer_ = std::make_unique<VexelRenderer>(
        sdlRenderer_,
        displayConfig_);
    if (!renderer_->isValid())
    {
        std::cerr << "Failed to create Vexel renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window_);
        SDL_DestroyRenderer(sdlRenderer_);
        SDL_Quit();
        return false;
    }

    std::cout << "SDL & Emulator Initialised Successfully!" << std::endl;
    initialised_ = true;
    return true;
}

int Application::run()
{
    if (!initialised_)
    {
        std::cerr << "Application not initialised. Call initialise() before run()." << std::endl;
        return -1;
    }
    running_ = true;
    Pixel clearColour = {0, 0, 0};

    while (running_)
    {

        frameTimer_.startFrame();
        handleEvents();
        update(animationController_, frameTimer_.getDeltaTime());
        render(animationController_, clearColour);
        frameTimer_.endFrame();
    }

    return 0;
}

void Application::update(AnimationController &controller, float deltaTime)
{
    controller.update(deltaTime);
}

void Application::render(AnimationController &controller, Pixel clearColour)
{
    renderer_->clear(clearColour);
    renderer_->drawFramebuffer(controller.framebuffer());
}

void Application::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running_ = false;
        }
        else
        {
            inputContoller_.handleInput(event, animationController_);
        }
    }
}

Application::~Application()
{
    if (sdlRenderer_)
    {
        SDL_DestroyRenderer(sdlRenderer_);
    }
    if (window_)
    {
        SDL_DestroyWindow(window_);
    }
    SDL_Quit();
}