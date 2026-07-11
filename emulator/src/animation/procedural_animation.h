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

    Type type() const override { return Type::Procedural; };

private:
    Generator generator_;
    void onUpdate(float elapsedTime, float deltaTime) override;
};
