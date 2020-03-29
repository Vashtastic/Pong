#include <vector>
#include <memory>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "EnumsAndGlobals.hpp"
#include "InputHandler.hpp"
#include "Logger.hpp"

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

void SetNet()
{
    constexpr int16_t NET_X = (SCREEN_WIDTH / 2) / 2;
    SDL_Rect net{};
    net.x = NET_X + 10;
    net.y = -5;
    net.w = 5;
    net.h = SCREEN_HEIGHT;
    SDL_SetRenderDrawColor(gRawRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(gRawRenderer, &net);
    SDL_RenderDrawRect(gRawRenderer, &net);
    SDL_SetRenderDrawColor(gRawRenderer, 0, 0, 0, 255);
    SDL_RenderPresent(gRawRenderer);
}

void DrawPaddle(PaddleEntity& paddleEntity)
{
    SDL_Rect& paddle = paddleEntity.GetPaddle() ;
    SDL_SetRenderDrawColor(gRawRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(gRawRenderer, &paddle);
    SDL_RenderDrawRect(gRawRenderer, &paddle);
    SDL_SetRenderDrawColor(gRawRenderer, 0, 0, 0, 255);
    SDL_RenderPresent(gRawRenderer);
}

bool HasEventForProcessing(SDL_Event& event)
{
    return SDL_PollEvent(&event);
}

int8_t InitSDL()
{
    return SDL_Init(SDL_INIT_EVERYTHING);
}

int main(int argc, char** argv)
{
    if (InitSDL() < 0)
    {
        LOG_INF("SDL Subsystems failed to initialize");
    }

    InitializeWindows();
    SetNet();

    SDL_SetWindowTitle(gRawWindow, WINDOW_NAME.c_str());
    SDL_Event event{};
    bool isQuitEvent = false;

    PaddleEntity paddleEntityOne(200, 200, PONG_HEIGHT, PONG_WIDTH);
    DrawPaddle(paddleEntityOne); //TODO Find out why PaddleEntity cant draw. Create rectangle processor
    InputHandler inputHandler(paddleEntityOne);


    while (!isQuitEvent)
    {
        bool frameHasPassed = HasEventForProcessing(event);
        if (frameHasPassed)
        {
            isQuitEvent = inputHandler.HandleInputForPlayerOne(event);
        }
    }
    // SDL_Delay(DELAY_OFFSET);
    SDL_DestroyRenderer(gRawRenderer);
    SDL_DestroyWindow(gRawWindow);
}
