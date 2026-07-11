#include "animation_controller.h"
#include "procedural_animation.h"
#include "animation/procedural_animation.h"
#include "animation/procedural_animations/gradient.h"
#include "animation/frame_animation.h"
#include "animation/frame_animations/moving_pixel.h"

AnimationController::AnimationController(DisplayConfig displayConfig)
    : displayConfig_(displayConfig)
{
    animations_.push_back(
        std::make_unique<ProceduralAnimation>(
            displayConfig_.framebufferWidth,
            displayConfig_.framebufferHeight,
            gradient));

    animations_.push_back(
        std::make_unique<FrameAnimation>(
            displayConfig_.framebufferWidth,
            displayConfig_.framebufferHeight,
            60.0f,
            createMovingPixelFrames(
                displayConfig_.framebufferWidth,
                displayConfig_.framebufferHeight)));

    currentAnimation_ = animations_[0].get();
}

void AnimationController::update(float deltaTime)
{
    if (playing_)
    {
        currentAnimation_->update(deltaTime, colours_[currentColourIndex_]);
    }
}

const Framebuffer &AnimationController::framebuffer() const
{
    return currentAnimation_->framebuffer();
}

void AnimationController::increaseSpeed()
{
    speed_ *= 2;
    currentAnimation_->setPlaybackSpeed(speed_);
}

void AnimationController::decreaseSpeed()
{
    speed_ /= 2;
    currentAnimation_->setPlaybackSpeed(speed_);
}

void AnimationController::cycleAnimation()
{
    if (currentAnimationIndex_ < animations_.size() - 1)
    {
        currentAnimationIndex_++;
    }
    else
    {
        currentAnimationIndex_ = 0;
    }
    currentAnimation_ = animations_[currentAnimationIndex_].get();
    currentAnimation_->setPlaybackSpeed(speed_);
}

void AnimationController::cycleColour()
{
    if (currentColourIndex_ < colours_.size() - 1)
    {
        currentColourIndex_++;
    }
    else
    {
        currentColourIndex_ = 0;
    }
}
