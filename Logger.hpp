#pragma once
#include <cstdio>

#define __GET_FIRST_ARG(FirstArg, ...) FirstArg
#define GET_HEAD(...) __GET_FIRST_ARG(__VA_ARGS__)
#define LOG_INF(...) printf(GET_HEAD(__VA_ARGS__), __VA_ARGS__); printf("\n") //[OwO] somehow much faster than yung pag pinasa natin yung \n
#define TRACE_FUNCTION() printf("%s\n", __PRETTY_FUNCTION__);

using RawWindow = SDL_Window;
using RawRenderer = SDL_Renderer;
using RawSurface = SDL_Surface; // used for software rendering
using RawTexture = SDL_Texture; // used for hardware rendering