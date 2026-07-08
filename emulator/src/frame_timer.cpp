#include "frame_timer.h"

FrameTimer::FrameTimer(float framesPerSecond)
    : frameTimeTargetMs_(1000 / framesPerSecond)
{
}

void FrameTimer::endFrame()
{
    Uint32 frameTime = SDL_GetTicks() - frameStart_;
    if (frameTime < frameTimeTargetMs_)
    {
        SDL_Delay(frameTimeTargetMs_ - frameTime);
    }
}