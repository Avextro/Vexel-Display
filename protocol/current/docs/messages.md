# Message Types

Messages are grouped by communication direction and purpose.

## Message Categories

### Commands

Commands are sent from the App to the Emulator and request a change in state.

Examples:

- IncreasePlaybackSpeed
- SetFramebuffer
- CycleAnimation

### Queries

Queries are sent from the App to the Emulator and request the current state.

Examples:

- GetCurrentDisplay
- GetCurrentPlaybackSpeed
- GetCurrentColour

Query responses are sent from the Emulator to the App using the corresponding state update message.

### State Updates

State updates are sent from the Emulator to the App and contain the current emulator state.

---

# App -> Emulator

## Commands

### IncreasePlaybackSpeed

Description: Doubles the emulators playback speed
Payload:

```json
{}
```

### DecreasePlaybackSpeed

Description: Halves the emulators playback speed

Payload:

```json
{}
```

### CycleAnimation

Description: Cycles emulators displayed animation to the next inbuilt animation

Payload:

```json
{}
```

### CycleColour

Description: Cycles emulators animation colour to the next inbuilt colour

Payload:

```json
{}
```

### SetFramebuffer

Description: Sets the display to the provided framebuffer

Payload:

```json
{
  "framebuffer": {}
}
```

Where `framebuffer` uses the [`Framebuffer`](data-types.md#framebuffer) data type.

## Queries

## GetPlaybackSpeed

Description: Requests emulator to return current playback speed

Response: CurrentPlaybackSpeed

Payload:

```json
{}
```

## GetColour

Description: Requests emulator to return current colour

Response: CurrentColour

Payload:

```json
{}
```

## GetFramebuffer

Description: Requests the emulator to return current [`Framebuffer`](data-types.md#framebuffer)

Response: CurrentFramebuffer

Payload:

```json
{}
```

---

# Emulator -> App

## State Updates

### CurrentPlaybackSpeed

```json
Payload:
{
"playbackSpeed": 1.0
}
```

Notes: Represents the current playback speed of the emulator.

| Property      | Type  | Constraints       | Description                                                                         |
| ------------- | ----- | ----------------- | ----------------------------------------------------------------------------------- |
| playbackspeed | float | playbackspeed > 0 | Playback speed multiplier. 1.0 = normal speed, 0.5 = half speed, 2.0 = double speed |

### CurrentColour

```json
Payload:
{
"colour": {}
}
```

Where `colour` uses the [`Pixel`](data-types.md) data type.

Notes: Current colour only applies to procedural animation types, if emulator is playing a frame animation type the colour will not match

### CurrentFramebuffer

Payload:

```json
{
  "framebuffer": {}
}
```

Where `framebuffer` uses the [`Framebuffer`](data-types.md#framebuffer) data type.
