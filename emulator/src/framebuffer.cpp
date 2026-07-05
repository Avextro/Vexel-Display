#include "framebuffer.h"
#include <algorithm>

Framebuffer::Framebuffer(int width, int height)
    : width_(width), height_(height), buffer_(width * height)
{
}

void Framebuffer::setPixel(int x, int y, Pixel colour)
{
    if (x < 0 || x >= width_ || y < 0 || y >= height_)
    {
        return;
    }

    buffer_[getPixelIndex(x, y)] = colour;
}

void Framebuffer::clear(Pixel colour)
{
    std::fill(buffer_.begin(), buffer_.end(), colour);
}

int Framebuffer::getPixelIndex(int x, int y) const
{
    // index = x + (height - 1 - y) * width - bottom up, bottom left corner is (0, 0)
    return x + (height_ - 1 - y) * width_;
}
