#pragma once
#include "SDL2/SDL.h"
#include <string>

using RawWindow = SDL_Window;
using RawRenderer = SDL_Renderer;
using RawSurface = SDL_Surface; // used for software rendering
using RawTexture = SDL_Texture; // used for hardware rendering

constexpr uint32_t DELAY_OFFSET = 5000;
constexpr uint32_t SCREEN_WIDTH = 680;
constexpr uint32_t SCREEN_HEIGHT = 480;
constexpr uint32_t RENDERER_RESOLUTION = 400;
constexpr uint32_t PONG_ONE_X_START = 0;
constexpr uint32_t PONG_ONE_Y_START = 0;
constexpr uint32_t PONG_HEIGHT = 10;
constexpr uint32_t PONG_WIDTH = 5;
const     std::string WINDOW_NAME = "SUPER PONG";
const     std::string ICON_NAME = "unnamed.jpg";

enum : uint8_t
{
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_TOTAL
};

static RawWindow* gRawWindow;
static RawRenderer* gRawRenderer;
