#include "animation.h"
#include "procedural_animation.h"

ProceduralAnimation::ProceduralAnimation(int width, int height, Generator generator)
    : Animation(width, height), generator_(std::move(generator))
{
}

void ProceduralAnimation::onUpdate(float elapsedTime, float deltaTime)
{
    generator_(framebuffer_, elapsedTime, colour_);
}
