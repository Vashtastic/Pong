#include "SDL2/SDL.h"
#include "InputHandler.hpp"

InputHandler::InputHandler(PaddleEntity& padOne)
:paddleOne(padOne)
{

}

InputHandler::~InputHandler()
{

}

void InputHandler::HandleInput(const SDL_Event& sdlEvent)
{
    switch (sdlEvent.key.keysym.sym)
    {
        case SDLK_UP:
            break;
        case SDLK_DOWN:
            break;
        case SDLK_LEFT:
            break;
        case SDLK_RIGHT :
            break;
        case SDLK_ESCAPE:
            break;
        default:
            break;
    }
}