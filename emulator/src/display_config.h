struct DisplayConfig
{
    short framebufferWidth;
    short framebufferHeight;

    short ledSize;
    short ledPadding;

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