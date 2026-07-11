#include "moving_pixel.h"

std::vector<Framebuffer> createMovingPixelFrames(int width, int height)
{
    std::vector<Framebuffer> frames;

    for (int x = 0; x < width; x++)
    {
        Framebuffer frame(width, height);

        frame.clear({0, 0, 0});
        frame.setPixel(x, height / 2, {255, 255, 255});

        frames.push_back(std::move(frame));
    }

    return frames;
}