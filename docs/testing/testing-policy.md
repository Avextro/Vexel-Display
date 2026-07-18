# Testing Policy
This testing policy defines the testing standards for the Vexel Display project, including the React Native application and communication protocol.

Testing intends to:

- Detect defects
- Provide confidence when refactoring
- Verify critical user flows
- Reduce reliance on manual testing
---
# Testing Tools
The project uses the following tools:
| Tool | Purpose |
| --- | --- |
| ESLint | Static code analysis |
| TypeScript | Type checking |
| Jest | Unit and integration testing |
| React Native Testing Library | Component testing |
| GoogleTests | C++ emulator and protocol testing |
| Maestro | End-to-end testing |
---
# Testing Strategy
The project follows a layered testing approach:
| Level | Purpose | Priority |
| ----------------- | ----------------------------- | -------- | 
| Static Analysis | Catch issues before execution | Required | 
| Protocol Tests | Validate app/emulator communication | High |
| Unit Tests | Validate business logic | High | 
| Component Tests | Verify UI behaviour | High |  
| Integration Tests | Verify modules work together | Medium | 
| End-to-End Tests | Verify critical user journeys | Medium |


## Static Analysis
Static analysis is the first line of defence. 

### Requirements:
- ESLint checks
- TypeScript type checking

Developers should run the following before committing:
- 'npm run lint'
- 'npm run typecheck'

No pull request may be merged while static analysis reports errors

## Protocol Testing
Protocol tests verify communication between the React Native application and the C++ emulator.

The protocol layer must be tested independently to ensure reliable communication between systems.

Protocol tests should verify that both the application and emulator interpret messages consistently.

### Requirements
* Protocol tests should not depend on the UI or emulator runtime.
* Messages should be tested using known input/output fixtures.
* Invalid or malformed messages should be tested.
* Changes to the protocol format must include updated tests.


## Unit Testing
Unit tests verify individual functions, classes and algorithms in isolation.


Logic should be separated from UI wherever practical to maximise unit test coverage

### Requirements:
- Unit tests should be independent
- Unit tests should avoid external dependencies
- Functions should be deterministic


## Component Testing
Component tests verify user interaction with React Native components.

These tests should simulate user behaviour rather than inspect component implementation details.

Implementation details such as component state should not be tested directly unless necessary

### Requirements
Component test should focus on:
- Rendering
- User interaction
- Accessibility
- Visible behaviour


## Integration Testing 
Integration tests verify multiple modules work together.

Integration tests may mock external services where appropriate but should use real application modules whenever practical

### Requirements:
Integration tests should:
- Verify communcication between related modules
- Test realistic application workflows
- Avoid testing implementation details
- Mock only external dependencies that areunreliable or unavailable

## End-to-end Testing
End-to-end tests verify the application from the user's perspective. 

Due to execute time and maintanence cost, E2E tests should be limited to core user journeys. 

### Requirements:
The following workflows must pass E2E tests before a build is released:
- Application launch
- Creating a project
- Drawing pixels
- Saving projects
- Loading projects
- Application settings persistence
- Exporting projects

E2E test should:
- Represent real user behaviour
- Test only critical workflows
- Avoid excessive coverage of individual UI components
- Run against a production-like build configuration
- Remain stable and maintainable

--- 
# Test Organisation

## Test Structure

Tests should be colocted with the code they verify where practical. 

## Test Naming
Tests should describe expected behaviour.

Examples:
- should_create_new_project_when_save_pressed
- should_restore_previous_canvas_state_after_undo
- should_reject_invalid_protocol_message


## Test Coverage Expectations
The project aims for meaningful coverage rather than an arbitrary percentage

Priority should be given to:
- Core business logic
- Data transformations
- Rendering behaviour
- Critical user workflows

Code that contains complex logic should always include accompanying tests.

Simple UI wrappers or boilerplate code may not require dedicated tests.

---
# Development Workflow
## Continuous Integration
Every pull request must successfully complete:
- ESLint
- TypeScript type checking
- Unit tests
- Component tests
- Protocol tests

Every pull request to main must additionally successfully complete:
- Integration tests
- End-to-end tests
---

## Bug Fix Policy
Production bugs should include a regression test where practical.

A bug fix should include:
- A test reproducing the issue
- The implementation fix
- Verification that the test passes

## Definition of Done
A feature is considered complete when:
- The implementation meets acceptance criteria
- Static analysis passes with no errors
- All existing automated tests coninue to pass
- Appropriate automated tests have been added or updated and pass
- Documentation has been updated where required

A feature should not be considered complete if it relies soley on manual testing for verification



