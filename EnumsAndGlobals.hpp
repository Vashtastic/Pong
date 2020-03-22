#pragma once
#include "SDL2/SDL.h"

using RawWindow = SDL_Window;
using RawRenderer = SDL_Renderer;
using RawSurface = SDL_Surface; // used for software rendering
using RawTexture = SDL_Texture; // used for hardware rendering

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
