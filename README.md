# Vexel-Display

A cross-platform LED pixel art editor, emulator, and embedded control system, consisting of:

- A React Native based pixel art app
- A C++ LED matrix emulator simulating an LED panel
- A shared protocolfor frame-based communication

## System Overview

React Native App -> WebSocket -> Emulator -> LED Framebuffer Renderer

## Design Priciples

- Frame-based communication
- Real-time rendering loop
- Shared data format across platforms

# Documentation

- [Commit Standards](docs/commit-standards.md)
- [Issue Standards](docs/issue-standards.md)
- [Classifications](docs/classification.md)
- [Architecture](docs/architecture.md)
