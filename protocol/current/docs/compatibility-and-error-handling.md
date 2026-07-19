# Compatibility & Error Handling

## Unknown Message Types

If a receiver encounters an unknown message type, it must reject the message.

The receiver must:

- Not crash
- Preserve its current state

## Invalid Messages

If a received message is malformed or contains invalid data, the receiver must reject the message.

Examples:

- Invalid JSON
- Invalid message structure
- Invalid data types
- Missing required fields
- Values outside allowed constraints

The receiver must:

- Not crash
- Preserve its current state

## Unknown Payload Fields

Receivers should ignore payload fields they do not recognise.

If the remaining message is valid, it should be processed normally.

This allows future protocol versions to add optional fields while maintaining backwards compatibility.

## Version Compatibility

Receivers must support messages using compatible protocol versions.

Rules:

- Major version changes indicate breaking changes.
- Minor versions may add backwards-compatible features.
- Patch versions contain non-functional changes.

A receiver must reject unsupported major versions.
