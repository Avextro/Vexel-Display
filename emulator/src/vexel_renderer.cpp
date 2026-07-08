#include "vexel_renderer.h"
#include "display_config.h"

VexelRenderer::VexelRenderer(SDL_Renderer *renderer, const DisplayConfig &displayConfig)
    : renderer_(renderer), displayConfig_(displayConfig)
{
    texture_ = SDL_CreateTexture(
        renderer_,
        SDL_PIXELFORMAT_ABGR8888,
        SDL_TEXTUREACCESS_STREAMING,
        displayConfig_.textureWidth(),
        displayConfig_.textureHeight());

    output_.resize(displayConfig_.textureWidth() * displayConfig_.textureHeight());
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
            SDL_Rect rect = {x * displayConfig_.ledPitch() + displayConfig_.ledPadding, displayConfig_.textureHeight() - displayConfig_.ledPitch() - (y * displayConfig_.ledPitch() + displayConfig_.ledPadding), displayConfig_.ledSize, displayConfig_.ledSize};
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
            drawLED(x * displayConfig_.ledPitch(), (framebuffer.height() - 1 - y) * displayConfig_.ledPitch(), pixel);
        }
    }
    SDL_UpdateTexture(
        texture_,
        nullptr,
        output_.data(),
        displayConfig_.textureWidth() * sizeof(Pixel));

    SDL_RenderCopy(
        renderer_,
        texture_,
        nullptr,
        nullptr);

    SDL_RenderPresent(renderer_);
}

void VexelRenderer::drawLED(int x, int y, Pixel colour)
{
    for (int px = displayConfig_.ledPadding; px < displayConfig_.ledPitch() - displayConfig_.ledPadding; px++)
    {
        for (int py = displayConfig_.ledPadding; py < displayConfig_.ledPitch() - displayConfig_.ledPadding; py++)
        {
            output_[(y + py) * displayConfig_.textureWidth() + (x + px)] = colour;
        }
    }
}