# Version 0.1.0

## Purpose

Establish initial communication between Vexel Display app and emulator using existing emulator display controls (cycle animation/colour, increase/decrease playback speed), requiring as little non-communication logic to be added to emulator and app as possible. Additionally, ability for the app to send a hardcoded framebuffer and ability for emulator to send current framebuffer, colour and playback speed will be included.

---

## Encoding Format

Protocol will use JSON encoding.

JSON has been chosen for ease of initial development and debugging, later versions will be upgraded to binary.

## Transport Method

Protocol will use Websockets for transport.

Websockets have been chosen for ease of initial development and debugging, later versions will be upgraded to bluetooth.
