#pragma once
#include <SDL.h>
#include "framebuffer.h"

class VexelRenderer
{
public:
    VexelRenderer(SDL_Renderer *renderer);

    bool isValid() const
    {
        return renderer_ != nullptr;
    }

    /** @brief Clears the renderer with a specific color.
     * @param colour The color to clear the renderer with.
     */
    void clear(const Pixel &colour);

    /** @brief Draws the contents of the framebuffer onto the renderer.
     * @param framebuffer The framebuffer to draw.
     */
    void drawStatic(const Framebuffer &framebuffer);

private:
    SDL_Renderer *renderer_ = nullptr;
};