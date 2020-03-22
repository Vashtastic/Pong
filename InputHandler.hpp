#pragma once

#include "IInputHandler.hpp"
#include "PaddleEntity.hpp"
#include "EnumsAndGlobals.hpp"

namespace Pong
{

class InputHandler : public IInputHandler
{
public:
    InputHandler(PaddleEntity& paddleOne);
    ~InputHandler();
    bool HandleInputForPlayerOne(const SDL_Event& sdlEvent);
private:
    PaddleEntity& paddleOne;
};

}