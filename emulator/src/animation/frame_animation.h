#pragma once
#include "animation.h"

class FrameAnimation : public Animation
{
public:
    FrameAnimation(std::vector<Framebuffer> frames);

private:
    void onUpdate(float deltaTime);
};