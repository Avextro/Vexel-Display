#pragma once
#include <SDL.h>

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

    ~Application();

private:
    SDL_Window *window_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
    bool initialised_ = false;
    bool running_ = false;

    void handleEvents();
    void update();
    void render();
};
