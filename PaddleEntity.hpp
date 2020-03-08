#pragma once
#include <stdint.h>
#include "WindowLocation.hpp"

class PaddleEntity
{
public:
    PaddleEntity(int32_t locX, int32_t locY);
    ~PaddleEntity();
    inline void SetLocationX(int32_t locationX);
    inline void SetLocationY(int32_t locatinonY);
    const WindowLocation& GetPaddleLocation() const;
private:
    WindowLocation location;
};