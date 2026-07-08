#pragma once
struct DisplayConfig
{
    short framebufferWidth = 32;
    short framebufferHeight = 16;

    short ledSize = 50;
    short ledPadding = 5;

    short ledPitch() const
    {
        return ledSize + ledPadding * 2;
    }

    short textureWidth() const
    {
        return framebufferWidth * ledPitch();
    }
    short textureHeight() const
    {
        return framebufferHeight * ledPitch();
    }
};