#pragma once
#include "framebuffer.h"

class Animation
{
public:
    Animation(int width, int height);
    void update(float deltaTime);
    Framebuffer framebuffer();

protected:
    virtual void onUpdate(float deltaTime) = 0;

private:
    bool looping_ = true;
    float elapsedTime_ = 0.0f;
    float playbackSpeed_ = 1.0f;
    Framebuffer framebuffer_;
};