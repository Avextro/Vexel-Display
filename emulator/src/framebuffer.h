#pragma once
#include <cstdint>
#include <vector>

/** @brief Represents a single pixel with RGB color values.
 * @param red The red component of the pixel (0-255).
 * @param green The green component of the pixel (0-255).
 * @param blue The blue component of the pixel (0-255).
 * @param alpha The alpha component of the pixel (0-255).
 */
struct Pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha = 255;
};

/**
 * @brief Represents a framebuffer for a display, allowing pixel manipulation.
 *
 * Pixels are stored in a bottom-up manner, with the bottom-left corner being (0,0).
 *
 * @param width The width of the framebuffer in pixels.
 * @param height The height of the framebuffer in pixels.
 */
class Framebuffer
{
public:
    Framebuffer(int width, int height);
    Framebuffer(int width, int height, Pixel colour);

    /** @brief Sets the color of a specific pixel in the framebuffer.
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @param colour The color to set the pixel to.
     */
    void setPixel(int x, int y, Pixel colour);

    /** @brief Clears the framebuffer with a specific color.
     * @param colour The color to clear the framebuffer with.
     */
    void clear(Pixel colour);

    /** @brief Gets the color of a specific pixel in the framebuffer.
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return The color of the specified pixel.
     */
    Pixel getPixel(int x, int y) const;

    /** @brief Gets the entire pixel buffer of the framebuffer.
     * @return A vector containing all pixels in the framebuffer.
     */
    std::vector<Pixel> getBuffer() const { return buffer_; }

    /** @brief Checks if a point is within the bounds of the framebuffer.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @return True if the point is within the bounds, false otherwise.
     */
    bool isInBounds(int x, int y) const { return x >= 0 && x < width_ && y >= 0 && y < height_; }

    /** @brief Gets the width of the framebuffer.
     * @return The width of the framebuffer in pixels.
     */
    int width() const { return width_; }

    /** @brief Gets the height of the framebuffer.
     * @return The height of the framebuffer in pixels.
     */
    int height() const { return height_; }

    const Pixel *data() const { return buffer_.data(); }

private:
    int width_;
    int height_;
    std::vector<Pixel> buffer_;
    /** @brief Calculates the index of a pixel in the buffer based on its coordinates.
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return The index of the pixel in the buffer.
     */
    int getPixelIndex(int x, int y) const { return x + (height_ - 1 - y) * width_; }
};