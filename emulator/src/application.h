#pragma once
#include <SDL.h>
#include "vexel_renderer.h"
#include "animation/animation.h"
#include "display_config.h"
#include "frame_timer.h"
#include "animation/animation_controller.h"

class Application
{
public:
    Application();

    /** @brief Initializes the application, setting up necessary resources.
     * @return True if initialization was successful, false otherwise.
     */
    bool initialise();
    /** @brief Runs the application loop.
     * @return True if the application ran successfully, false otherwise.
     */
    int run();
    /** @brief Shuts down the application, releasing resources.
     * @return True if shutdown was successful, false otherwise.
     */

    bool isInitialised() const
    {
        return initialised_;
    }

    ~Application();

private:
    DisplayConfig displayConfig_;
    SDL_Window *window_ = nullptr;
    SDL_Renderer *sdlRenderer_ = nullptr;
    std::unique_ptr<VexelRenderer> renderer_;
    FrameTimer frameTimer_;
    AnimationController animationController_;

    bool initialised_ = false;
    bool running_ = false;

    void handleEvents();
    void update(AnimationController &controller, float deltaTime);
    void render(AnimationController &animation, Pixel clearColour);
};
