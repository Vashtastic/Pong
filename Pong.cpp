#include <vector>
#include <memory>

#include "SDL2/SDL.h"
#include "InputHandler.hpp"
#include "Logger.hpp"

namespace
{
constexpr uint32_t DELAY_OFFSET = 5000;
constexpr uint32_t SCREEN_WIDTH = 680;
constexpr uint32_t SCREEN_HEIGHT = 480;
constexpr uint32_t RENDERER_RESOLUTION = 400;
constexpr uint32_t PONG_ONE_X_START = 0; //to change
constexpr uint32_t PONG_ONE_Y_START = 0; //to change
const     std::string WINDOW_NAME = "SUPER PONG";
}
using RawWindow = RawWindow;

enum : uint8_t
{
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_TOTAL
};

RawWindow* gRawWindow {};
RawRenderer* gRawRenderer {};

void InitializeWindows()
{
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_MOUSE_FOCUS,
        &(gRawWindow), &(gRawRenderer)); //[OwO] pass in window and renderer pointer here
    SDL_RenderSetLogicalSize(gRawRenderer, RENDERER_RESOLUTION, RENDERER_RESOLUTION);
}

void Draw()
{
    SDL_RenderClear(gRawRenderer);      //[OwO] Use this function to clear the current rendering target with the drawing color.
    // SDL_RenderCopy()                 //[OwO] Renders texture to a screen
    SDL_RenderPresent(gRawRenderer);    //[OwO] update screen with any rendering performed
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
    if (InitSDL() < 0)
    {
        LOG_INF("SDL Subsystems failed to initialize");
    }

    PaddleEntity paddleEntityOne(PONG_ONE_X_START, PONG_ONE_Y_START);
    InputHandler inputHandler(paddleEntityOne);
    InitializeWindows();
    SDL_SetWindowTitle(gRawWindow, WINDOW_NAME.c_str());
    SDL_Event event{};
    bool isQuitEvent = false;
    while (!isQuitEvent)
    {
        bool frameHasPassed = HasEventForProcessing(event);
        if (frameHasPassed)
        {
            isQuitEvent = inputHandler.HandleInputForPlayerOne(event);
        }

    }
    SDL_Delay(DELAY_OFFSET);
    SDL_DestroyRenderer(gRawRenderer);
    SDL_DestroyWindow(gRawWindow);
}