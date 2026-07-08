#pragma once
#include <SDL.h>

class FrameTimer
{
public:
    /** @brief Initialises frame timer with a target fps, defaulting to 60 */
    FrameTimer(float framesPerSecond = 60.0f);

    /** @brief Starts the frame timer */
    void startFrame();

    /** @brief Delays program until target frame time has elapsed */
    void endFrame();

    float getDeltaTime() const { return deltaTime_; };
    int getFrameCount() const { return frameCount_; };

private:
    Uint32 frameStart_;
    Uint32 previousFrame_;

    float deltaTime_ = 0.0f;
    float frameTimeTargetMs_;

    int frameCount_ = 0;
};