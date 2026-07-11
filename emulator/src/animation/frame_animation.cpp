#include "frame_animation.h"
#include <stdexcept>
// will require logic to verify framebuffers match dimensions in future
FrameAnimation::FrameAnimation(int width, int height, float framesPerSecond, std::vector<Framebuffer> frames)
    : Animation(width, height), frameTimeTargetMs_(1000.0f / framesPerSecond), frames_(std::move(frames)), length_(frames_.size())
{
}

void FrameAnimation::onUpdate(float elapsedTime, float deltaTime)
{
    frameTimeMs_ += deltaTime;
    if (frameTimeMs_ > frameTimeTargetMs_)
    {
        currentFrame_++;
        if (currentFrame_ == length_)
        {
            if (!looping_)
            {
                return;
            }
            else
            {
                currentFrame_ = 0;
            }
        }
        framebuffer_ = frames_[currentFrame_];
    }
}