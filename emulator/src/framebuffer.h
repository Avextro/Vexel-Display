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

    int width() const { return width_; }
    int height() const { return height_; }

private:
    int getPixelIndex(int x, int y) const;
    int width_;
    int height_;
    std::vector<Pixel> buffer_;
};