#pragma once
#include <SDL.h>
#include "vexel_renderer.h"
#include "test_patterns/gradient.h"
#include "display_config.h"

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
    SDL_Window *window_ = nullptr;
    SDL_Renderer *sdlRenderer_ = nullptr;
    Framebuffer framebuffer_;
    VexelRenderer renderer_;
    bool initialised_ = false;
    bool running_ = false;

    DisplayConfig displayConfig_;

    void handleEvents();
    void update(Gradient gradient, int offset);
    void render(Pixel clearColour);
};
