#include "animation.h"
#include "framebuffer.h"

Animation::Animation(int width, int height)
    : framebuffer_(Framebuffer(width, height)) {

      };

void Animation::update(float deltaTime)
{
    elapsedTime_ += deltaTime * playbackSpeed_;
    onUpdate(deltaTime);
};