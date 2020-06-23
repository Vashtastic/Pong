#include "PaddleEntity.hpp"

namespace Pong
{

PaddleEntity::PaddleEntity(int64_t locX, int32_t locY, int32_t height, int32_t width)
{
    LOG_INF("[OWO] X is %d", locX);
    paddle.x = locX;
    paddle.y = locY;
    paddle.h = height;
    paddle.w = width;
}

PaddleEntity::~PaddleEntity()
{

}

inline void PaddleEntity::SetLocationX(int32_t locX)
{
    paddle.x = locX;
}

inline void PaddleEntity::SetLocationY(int32_t locY)
{
    paddle.y = locY;
}

inline void PaddleEntity::SetHeight(int32_t height)
{
    paddle.h = height;
}

inline void PaddleEntity::SetWidth(int32_t width)
{
    paddle.w = width;
}

SDL_Rect& PaddleEntity::GetPaddle()
{
    return paddle;
}

void PaddleEntity::toString()
{
    LOG_INF("PaddleOne x: %d y: %d", paddle.y, paddle.x);
}

}

