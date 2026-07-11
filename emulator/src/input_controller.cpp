#include "input_controller.h"

InputController::InputController()
{
}

void InputController::handleInput(SDL_Event event, AnimationController animationController)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_SPACE:
            // play/pause alt
            break;
        case SDLK_UP:
            animationController.increaseSpeed();
            break;
        case SDLK_DOWN:
            animationController.decreaseSpeed();
            break;
        case SDLK_LEFT:
            animationController.cycleColour();
            break;
        case SDLK_RIGHT:
            animationController.cycleAnimation();
            break;
        }
        break;
    }
}
