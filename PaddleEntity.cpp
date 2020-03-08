#include "PaddleEntity.hpp"

PaddleEntity::PaddleEntity(int32_t locX, int32_t locY)
{
    location.XAxis = locX;
    location.YAxis = locY;
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

const WindowLocation& PaddleEntity::GetPaddleLocation() const
{
    return location;
}

