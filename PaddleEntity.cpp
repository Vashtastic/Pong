#include "PaddleEntity.hpp"

namespace Pong
{

PaddleEntity::PaddleEntity(int32_t locX, int32_t locY, int32_t height, int32_t width)
{
    location.XAxis = locX;
    location.YAxis = locY;
    this->height = height;
    this->width = width;
    SDL_SetRenderDrawColor(gRawRenderer, 0, 0, 0, 0);
}

PaddleEntity::~PaddleEntity()
{

}

inline void PaddleEntity::SetLocationX(int32_t locX)
{
    location.XAxis = locX;
}

inline void PaddleEntity::SetLocationY(int32_t locY)
{
    location.YAxis = locY;
}

inline void PaddleEntity::SetHeight(int32_t height)
{
    this->height = height;
}

inline void PaddleEntity::SetWidth(int32_t width)
{
    this->width = width;
}

const WindowLocation& PaddleEntity::GetPaddleLocation() const
{
    return location;
}

}

