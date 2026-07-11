#pragma once
#include <functional>
#include "animation.h"

class ProceduralAnimation
    : public Animation
{
public:
    using Generator =
        std::function<void(Framebuffer &, float)>;

    ProceduralAnimation(
        int width,
        int height,
        Generator generator);

private:
    Generator generator_;
    void onUpdate(float elapsedTime, float deltaTime) override;
};
