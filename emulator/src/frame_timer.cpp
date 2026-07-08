#include "frame_timer.h"

FrameTimer::FrameTimer(float framesPerSecond)
    : frameTimeTargetMs_(1000.0f / framesPerSecond)
{
}

void FrameTimer::endFrame()
{
    Uint32 frameTime = getFrameTime();
    if (frameTime < frameTimeTargetMs_)
    {
        SDL_Delay(frameTimeTargetMs_ - frameTime);
    }
}
