#include "SDL2/SDL.h"
#include "InputHandler.hpp"
#include "Logger.hpp"

InputHandler::InputHandler(PaddleEntity& padOne)
:paddleOne(padOne)
{

}

InputHandler::~InputHandler()
{

}

bool InputHandler::HandleInputForPlayerOne(const SDL_Event& sdlEvent)
{
    switch (sdlEvent.key.keysym.sym)
    {
        case SDLK_UP:
            LOG_INF("UP pressed!");
            break;
        case SDLK_DOWN:
            LOG_INF("DOWN pressed!");
            break;
        case SDLK_LEFT:
            LOG_INF("LEFT pressed!");
            break;
        case SDLK_RIGHT :
            LOG_INF("RIGHT pressed!");
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