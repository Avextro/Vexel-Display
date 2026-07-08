#pragma once
#include <SDL.h>

class FrameTimer
{
public:
    /** @brief Initialises frame timer with a target fps, defaulting to 60 */
    FrameTimer(float framesPerSecond = 60.0f);

    /** @brief Starts the frame timer */
    void startFrame() { frameStart_ = SDL_GetTicks(); };

    /** @brief Delays program until target frame time has elapsed */
    void endFrame();

    /** @brief Returns milliseconds ellapsed during current frame */
    Uint32 getFrameTime()
    {
        return SDL_GetTicks() - frameStart_;
    }

private:
    Uint32 frameStart_;
    Uint32 frameTimeTargetMs_;
};