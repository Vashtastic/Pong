#pragma once
#include <stdint.h>
#include "WindowLocation.hpp"
#include "SDL2/SDL.h"
#include "EnumsAndGlobals.hpp"

namespace Pong
{

class PaddleEntity
{
public:
    PaddleEntity(int32_t locX, int32_t locY, int32_t height, int32_t width);
    ~PaddleEntity();
    inline void SetLocationX(int32_t locationX);
    inline void SetLocationY(int32_t locatinonY);
    inline void SetHeight(int32_t height);
    inline void SetWidth(int32_t width);
    const WindowLocation& GetPaddleLocation() const;
private:
    WindowLocation location;
    int32_t height;
    int32_t width;
};

}