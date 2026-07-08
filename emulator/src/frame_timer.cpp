#include "frame_timer.h"

FrameTimer::FrameTimer(float framesPerSecond)
    : frameTimeTargetMs_(1000.0f / framesPerSecond)
{
    previousFrame_ = SDL_GetTicks();
}

void FrameTimer::startFrame()
{
    frameStart_ = SDL_GetTicks();
    deltaTime_ = frameStart_ - previousFrame_;
    previousFrame_ = frameStart_;
}

void FrameTimer::endFrame()
{
    Uint32 frameTime = SDL_GetTicks() - frameStart_;
    if (frameTime < frameTimeTargetMs_)
    {
        SDL_Delay(frameTimeTargetMs_ - frameTime);
    }
    frameCount_++;
}
