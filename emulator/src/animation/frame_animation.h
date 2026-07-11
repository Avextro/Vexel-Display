#pragma once
#include "animation.h"
#include "frame_timer.h"

class FrameAnimation : public Animation
{
public:
    FrameAnimation(int width, int height, float framesPerSecond, std::vector<Framebuffer> frames);

private:
    void onUpdate(float elapsedTime, float deltaTime);

    std::vector<Framebuffer> frames_;
    float frameTimeTargetMs_;
    float frameTimeMs_ = 0;
    int currentFrame_ = 0;
    int length_;
};