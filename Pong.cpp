#include <vector>
#include <memory>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "EnumsAndGlobals.hpp"
#include "InputHandler.hpp"
#include "Logger.hpp"

namespace
{
constexpr uint32_t DELAY_OFFSET = 5000;
constexpr uint32_t SCREEN_WIDTH = 680;
constexpr uint32_t SCREEN_HEIGHT = 480;
constexpr uint32_t RENDERER_RESOLUTION = 400;
constexpr uint32_t PONG_ONE_X_START = 0;
constexpr uint32_t PONG_ONE_Y_START = 0;
constexpr uint32_t PONG_HEIGHT = 0;
constexpr uint32_t PONG_WIDTH = 0;
const     std::string WINDOW_NAME = "SUPER PONG";
const     std::string ICON_NAME = "unnamed.jpg";
}

using namespace Pong;

void Draw()
{
    SDL_RenderClear(gRawRenderer);      //[OwO] Use this function to clear the current rendering target with the drawing color.
    SDL_RenderPresent(gRawRenderer);    //[OwO] update screen with any rendering performed
}

void InitializeWindows()
{
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_MOUSE_FOCUS,
        &(gRawWindow), &(gRawRenderer));
    SDL_RenderSetLogicalSize(gRawRenderer, RENDERER_RESOLUTION, RENDERER_RESOLUTION);
    SDL_SetRenderDrawColor(gRawRenderer, 0, 0, 0, 0);
    Draw();

    IMG_Init(IMG_INIT_JPG);
    RawSurface* windowWithBmp = IMG_Load(ICON_NAME.c_str());
    SDL_SetWindowIcon(gRawWindow, windowWithBmp);
}

void showMenu()
{
    //TO DO
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

    InitializeWindows();
    SDL_SetWindowTitle(gRawWindow, WINDOW_NAME.c_str());
    SDL_Event event{};
    bool isQuitEvent = false;

    PaddleEntity paddleEntityOne(PONG_ONE_X_START, PONG_ONE_Y_START, PONG_HEIGHT, PONG_WIDTH);
    InputHandler inputHandler(paddleEntityOne);

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
