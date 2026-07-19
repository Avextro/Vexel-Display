# Shared Data Types

## Pixel

Represents a single display pixel by its RGBA value.

| Property | Type  | Constraints | Description                            |
| -------- | ----- | ----------- | -------------------------------------- |
| red      | uint8 | 0-255       | Red intensity                          |
| green    | uint8 | 0-255       | Green intensity                        |
| blue     | uint8 | 0-255       | Blue intensity                         |
| alpha    | uint8 | 0-255       | Opacity. No current effect on emulator |

---

## Framebuffer

Represents the complete state of the display.

| Property | Type    | Constraints             | Description                          |
| -------- | ------- | ----------------------- | ------------------------------------ |
| width    | uint16  | width > 0               | Display width in pixels              |
| height   | uint16  | height > 0              | Display height in pixels             |
| pixels   | Pixel[] | length = width × height | Pixel data stored in row-major order |

[More Details](data-types/framebuffer.md)
