#include "framebuffer.h"
#include <algorithm>

Framebuffer::Framebuffer(int width, int height)
    : width_(width), height_(height), buffer_(width * height)
{
}

void Framebuffer::setPixel(int x, int y, Pixel colour)
{
    if (!isInBounds(x, y))
    {
        return;
    }

    buffer_[getPixelIndex(x, y)] = colour;
}

Pixel Framebuffer::getPixel(int x, int y) const
{
    if (!isInBounds(x, y))
    {
        return {0, 0, 0}; // Return black pixel for out-of-bounds access
    }

    return buffer_[getPixelIndex(x, y)];
}

void Framebuffer::clear(Pixel colour)
{
    std::fill(buffer_.begin(), buffer_.end(), colour);
}
