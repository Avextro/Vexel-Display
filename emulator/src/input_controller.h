#pragma once
#include <SDL.h>
#include "animation/animation_controller.h"

class InputController
{
public:
    InputController();

    void handleInput(SDL_Event event, AnimationController animationController);
};