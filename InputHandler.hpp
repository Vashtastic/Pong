#pragma once

#include "IInputHandler.hpp"
#include "PaddleEntity.hpp"

class InputHandler : public IInputHandler
{
public:
    InputHandler(PaddleEntity& paddleOne);
    ~InputHandler();
    void HandleInput(const SDL_Event& sdlEvent);
private:
    PaddleEntity& paddleOne;
};