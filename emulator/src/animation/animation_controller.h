#pragma once
#include "animation.h"
#include <memory>
#include "display_config.h"

class AnimationController
{
public:
    AnimationController(DisplayConfig displayConfig);

    void update(float deltaTime);
    const Framebuffer &framebuffer() const;
    void play() { playing_ = true; };
    void pause() { playing_ = false; };
    void togglePlayState() { playing_ = !playing_; };
    void increaseSpeed();
    void decreaseSpeed();
    void cycleColour();
    void cycleAnimation();

private:
    std::vector<std::unique_ptr<Animation>>
        animations_;
    std::vector<Pixel> colours_ = {{255, 0, 0}, {255, 255, 0}, {0, 255, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255}};
    float speed_ = 1;
    bool playing_ = true;
    int currentAnimationIndex_ = 0;
    int currentColourIndex_ = 0;
    Animation *currentAnimation_;
    DisplayConfig displayConfig_;
};