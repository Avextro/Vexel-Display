#include "gradient.h"

void gradient(Framebuffer &framebuffer, float elapsedTime, Pixel colour)
{

    for (int x = 0; x < framebuffer.width(); x++)
    {
        for (int y = 0; y < framebuffer.height(); y++)
        {
            uint8_t colourValue = static_cast<uint8_t>(x * 4 + y * 8 + elapsedTime / 10);

            Pixel pixel;
            pixel.red = static_cast<uint8_t>((colour.red * colourValue) / 255);
            pixel.green = static_cast<uint8_t>((colour.green * colourValue) / 255);
            pixel.blue = static_cast<uint8_t>((colour.blue * colourValue) / 255);

            framebuffer.setPixel(x, y, pixel);
        }
    }
}