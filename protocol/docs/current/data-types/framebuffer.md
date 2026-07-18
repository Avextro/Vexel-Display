# Framebuffer Specifications

## Coordinate System

- Origin is top-left
- X increases left-to-right
- Y increases top-to-bottom

## Pixel Format

Pixels use RGBA8888.

Each channel is an unsigned 8-bit integer.

## Pixel Ordering

Pixels are stored in row-major order.

Index calculation:

index = x + (y \* width)

## Frame Validation

The number of pixels must equal:

width \* height

## Display Mapping

The protocol framebuffer represents logical display coordinates.
Physical LED wiring translation is handled by the display driver.
