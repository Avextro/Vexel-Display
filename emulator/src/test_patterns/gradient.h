#pragma once
#include "framebuffer.h"
class Gradient
{
public:
    Gradient();
    Framebuffer getGradientFramebuffer(int offset);
};