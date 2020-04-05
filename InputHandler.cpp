#include "SDL2/SDL.h"
#include "InputHandler.hpp"
#include "Logger.hpp"

namespace Pong
{

InputHandler::InputHandler(PaddleEntity& padOne)
:paddleOne(padOne)
{

}

InputHandler::~InputHandler()
{

}

bool InputHandler::HandleInputForPlayerOne(const SDL_Event& sdlEvent)
{
    auto& paddleY = paddleOne.GetPaddle().y;
    auto& paddleX = paddleOne.GetPaddle().x;

    switch (sdlEvent.key.keysym.sym)
    {
        case SDLK_UP:
            --paddleY;
            LOG_INF("[OWO] X: %d \n", paddleX);
            paddleOne.toString();
            break;
        case SDLK_DOWN:
            ++paddleY;
            paddleOne.toString();
            break;
        case SDLK_LEFT:
            --paddleX;
            paddleOne.toString();
            break;
        case SDLK_RIGHT :
            ++paddleX;
            paddleOne.toString();
            break;
        case SDLK_ESCAPE:
            LOG_INF("ESC pressed!");
            return true;
            break;
        default:
            break;
    }
    return false;
}

}