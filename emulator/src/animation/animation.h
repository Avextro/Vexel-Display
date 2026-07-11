#pragma once
#include "framebuffer.h"

class Animation
{
public:
    enum class Type
    {
        Procedural,
        Frame
    };

    Animation(int width, int height);
    Animation(int width, int height, Pixel colour);

    const Framebuffer &framebuffer() const { return framebuffer_; };

    void update(float deltaTime, Pixel colour);

    void setPlaybackSpeed(float speed) { playbackSpeed_ = speed; };

    void setColour(Pixel colour) { colour_ = colour; };

    virtual Type type() const = 0;

protected:
    Framebuffer framebuffer_;
    bool looping_ = true;
    Pixel colour_ = {255, 0, 0};

    virtual void onUpdate(float elapsedTime, float deltaTime) = 0;

    float elapsedTime() const { return elapsedTime_; }

private:
    float elapsedTime_ = 0.0f;
    float playbackSpeed_ = 1.0f;
};