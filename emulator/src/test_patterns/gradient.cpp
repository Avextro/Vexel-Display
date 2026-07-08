#include "framebuffer.h"
#include "gradient.h"

Gradient::Gradient()
{
}
Framebuffer Gradient::getGradientFramebuffer(int offset, int width, int height)
{
    Framebuffer framebuffer(width, height);
    for (int x = 0; x < framebuffer.width(); x++)
    {
        for (int y = 0; y < framebuffer.height(); y++)
        {
            Pixel colour = {0, static_cast<uint8_t>(x * 4 + y * 8 + offset), static_cast<uint8_t>(x * 4 + y * 8 + offset)};
            framebuffer.setPixel(x, y, colour);
        }
    }
    return framebuffer;
};