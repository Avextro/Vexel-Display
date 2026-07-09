#pragma once
#include <functional>
#include "animation.h"

class ProceduralAnimation
    : public Animation
{
public:
    ProceduralAnimation(std::function<void(Framebuffer &)> generator);

private:
    void onUpdate(float deltaTime);
};