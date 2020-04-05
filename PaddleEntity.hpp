#pragma once
#include <stdint.h>
#include "SDL2/SDL.h"
#include "EnumsAndGlobals.hpp"
#include "Logger.hpp"

namespace Pong
{

class PaddleEntity
{
public:
    PaddleEntity(int64_t locX, int32_t locY, int32_t height, int32_t width);
    ~PaddleEntity();
    inline void SetLocationX(int32_t locationX);
    inline void SetLocationY(int32_t locatinonY);
    inline void SetHeight(int32_t height);
    inline void SetWidth(int32_t width);
    SDL_Rect& GetPaddle();
    void toString();
private:
    int64_t height{};
    int32_t width{};
    SDL_Rect paddle{};
};

}