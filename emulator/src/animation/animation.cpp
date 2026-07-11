#include "animation.h"
#include "framebuffer.h"

Animation::Animation(int width, int height)
    : framebuffer_(Framebuffer(width, height)) {

      };

Animation::Animation(int width, int height, Pixel colour)
    : framebuffer_(Framebuffer(width, height)), colour_(colour) {

      };

void Animation::update(float deltaTime, Pixel colour)
{
    colour_ = colour;
    elapsedTime_ += deltaTime * playbackSpeed_;
    onUpdate(elapsedTime_, deltaTime * playbackSpeed_);
};