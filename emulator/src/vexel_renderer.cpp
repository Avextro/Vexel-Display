#include "vexel_renderer.h"

VexelRenderer::VexelRenderer(SDL_Renderer *renderer)
    : renderer_(renderer)
{
    texture_ = SDL_CreateTexture(
        renderer_,
        SDL_PIXELFORMAT_ABGR8888,
        SDL_TEXTUREACCESS_STREAMING,
        768,
        384);

    output_.resize(768 * 384);
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

void VexelRenderer::drawFramebuffer(const Framebuffer &framebuffer)
{
    std::fill(
        output_.begin(),
        output_.end(),
        Pixel{0, 0, 0, 255});

    for (int x = 0; x < framebuffer.width(); x++)
    {
        for (int y = 0; y < framebuffer.height(); y++)
        {
            Pixel pixel = framebuffer.getPixel(x, y);
            drawLED(x * 24, (framebuffer.height() - 1 - y) * 24, pixel);
        }
    }
    SDL_UpdateTexture(
        texture_,
        nullptr,
        output_.data(),
        768 * sizeof(Pixel));

    SDL_RenderCopy(
        renderer_,
        texture_,
        nullptr,
        nullptr);

    SDL_RenderPresent(renderer_);
}

void VexelRenderer::drawLED(int x, int y, Pixel colour)
{
    for (int px = 2; px < 22; px++)
    {
        for (int py = 2; py < 22; py++)
        {
            output_[(y + py) * 768 + (x + px)] = colour;
        }
    }
}