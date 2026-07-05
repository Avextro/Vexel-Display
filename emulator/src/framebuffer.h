#pragma once
#include <cstdint>
#include <vector>

struct Pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class Framebuffer
{
public:
    Framebuffer(int width, int height);

    void setPixel(int x, int y, Pixel colour);
    void clear(Pixel colour);

    Pixel getPixel(int x, int y) const;
    std::vector<Pixel> getBuffer() const { return buffer_; }

    int width() const { return width_; }
    int height() const { return height_; }

private:
    int width_;
    int height_;
    std::vector<Pixel> buffer_;
    int getPixelIndex(int x, int y) const { return x + (height_ - 1 - y) * width_; } // bottom up, bottom left corner is (0, 0);
};