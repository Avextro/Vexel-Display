#include "vexel_renderer.h"

VexelRenderer::VexelRenderer(SDL_Renderer *renderer)
    : renderer_(renderer)
{
}

void VexelRenderer::clear(const Pixel &colour)
{
    SDL_SetRenderDrawColor(renderer_, colour.red, colour.green, colour.blue, 255);
    SDL_RenderClear(renderer_);
}

void VexelRenderer::drawStatic(const Framebuffer &framebuffer)
{
    for (int x = 0; x < framebuffer.width(); x++)
    {
        for (int y = 0; y < framebuffer.height(); y++)
        {
            Pixel pixel = framebuffer.getPixel(x, y);
            SDL_SetRenderDrawColor(renderer_, pixel.red, pixel.green, pixel.blue, 255);
            SDL_Rect rect = {x * 24 + 2, 364 - (y * 24 + 2), 20, 20};
            SDL_RenderFillRect(renderer_, &rect);
        }
    }
    SDL_RenderPresent(renderer_);
}