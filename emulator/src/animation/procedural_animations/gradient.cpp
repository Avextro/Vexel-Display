#include "gradient.h"

void gradient(Framebuffer &framebuffer, float elapsedTime)
{

    for (int x = 0; x < framebuffer.width(); x++)
    {
        for (int y = 0; y < framebuffer.height(); y++)
        {
            Pixel colour = {0, static_cast<uint8_t>(x * 4 + y * 8 + elapsedTime), static_cast<uint8_t>(x * 4 + y * 8 + elapsedTime)};
            framebuffer.setPixel(x, y, colour);
        }
    }
}