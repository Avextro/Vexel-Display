#pragma once
#include <SDL.h>
#include "animation/animation_controller.h"

class InputController
{
public:
    InputController();

    void handleInput(const SDL_Event &event, AnimationController &animationController);
};