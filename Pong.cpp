#include <cstdio>
#include <vector>
#include <memory>

#include "SDL2/SDL.h"
#include "InputHandler.hpp"

using RawWindow = SDL_Window;
using RawRenderer = SDL_Renderer;
using RawSurface = SDL_Surface; // used for software rendering
using RawTexture = SDL_Texture; // used for hardware rendering

#define __GET_FIRST_ARG(FirstArg, ...) FirstArg
#define GET_HEAD(...) __GET_FIRST_ARG(__VA_ARGS__)
#define LOG_INF(...) printf(GET_HEAD(__VA_ARGS__), __VA_ARGS__)

RawWindow* gRawWindow {};
RawRenderer* gRawRenderer {};

namespace
{
constexpr uint32_t DELAY_OFFSET = 5000;
constexpr uint32_t WIDTH = 680;
constexpr uint32_t HEIGHT = 480;
constexpr uint32_t RENDERER_RESOLUTION = 400;
}

enum : uint8_t
{
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_TOTAL
};

void InitializeWindows()
{
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MOUSE_FOCUS,
        &(gRawWindow), &(gRawRenderer)); //[OwO] pass in window and renderer pointer here
    SDL_RenderSetLogicalSize(gRawRenderer, RENDERER_RESOLUTION, RENDERER_RESOLUTION);
}

void Draw()
{
    SDL_RenderClear(gRawRenderer); //[OwO] Use this function to clear the current rendering target with the drawing color.
    // SDL_RenderCopy() //[OwO] Renders texture to a screen
    SDL_RenderPresent(gRawRenderer); //[OwO] update screen with any rendering performed
}

void showMenu()
{

}

bool HasEventForProcessing(SDL_Event& event)
{
    return SDL_PollEvent(&event);
}

int8_t InitSDL()
{
    return SDL_Init(SDL_INIT_VIDEO);
}


int main(int argc, char** argv)
{
    // SDL_Window window =
    if (InitSDL() < 0)
    {
        LOG_INF("SDL Subsystems failed to initialize");
    }

    SDL_Event event{};
    while (true)
    {
        bool frameHasPassed = HasEventForProcessing(event);
        if (frameHasPassed)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_UP:
                {

                }
                case SDLK_DOWN:
                {

                }
                case SDLK_ESCAPE:
                {
                    LOG_INF("Quitting Game OwO");
                    break;
                }
                default:
                {

                }
            }
        }
    }

    SDL_Delay(DELAY_OFFSET);
}