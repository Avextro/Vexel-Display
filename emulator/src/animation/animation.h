#pragma once
#include "framebuffer.h"

class Animation
{
public:
    Animation(int width, int height);

    Framebuffer framebuffer() const { return framebuffer_; };

    void update(float deltaTime);

protected:
    Framebuffer framebuffer_;
    bool looping_ = true;

    virtual void onUpdate(float elapsedTime, float deltaTime) = 0;

    float elapsedTime() const { return elapsedTime_; }

private:
    float elapsedTime_ = 0.0f;
    float playbackSpeed_ = 1.0f;
};