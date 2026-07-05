#include "framebuffer.h"

class Square
{
public:
    Framebuffer getSquareFramebuffer(uint8_t size, uint8_t x_offset, uint8_t y_offset, Pixel colour)
    {
        Framebuffer framebuffer(32, 16);
        for (int x = x_offset; x < x_offset + size; x++)
        {
            for (int y = y_offset; y < y_offset + size; y++)
            {
                if (x == x_offset || x == x_offset + size - 1 || y == y_offset || y == y_offset + size - 1)
                {
                    framebuffer.setPixel(x, y, colour);
                }
            }
        }
        return framebuffer;
    };
};