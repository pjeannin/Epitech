#include "BoundingBox.hpp"

raylib::BoundingBox::BoundingBox(::BoundingBox const &box) noexcept
{
    *this = box;
}

raylib::BoundingBox::BoundingBox(::Mesh const &mesh) noexcept
{
    *this = ::MeshBoundingBox(mesh);
}

raylib::BoundingBox::BoundingBox(::Vector3 const &minMax) noexcept
{
    min = minMax;
    max = minMax;
}

raylib::BoundingBox::BoundingBox(::Vector3 const &Min, ::Vector3 const &Max) noexcept
{
    min = Min;
    max = Max;
}

raylib::BoundingBox& raylib::BoundingBox::operator=(::BoundingBox const &box) noexcept
{
    min = box.min;
    max = box.max;
    return *this;
}

raylib::BoundingBox& raylib::BoundingBox::Draw(::Color const &color) noexcept
{
    DrawBoundingBox(*this, color);
    return *this;
}

bool raylib::BoundingBox::CheckCollision(::BoundingBox const &box2) const noexcept
{
    return ::CheckCollisionBoxes(*this, box2);
}

bool raylib::BoundingBox::CheckCollision(::Vector3 const &center, float const radius) const noexcept
{
    return ::CheckCollisionBoxSphere(*this, center, radius);
}

//::RayCollision raylib::BoundingBox::CheckCollision(::Ray const &ray) const noexcept
//{
//    return ::GetRayCollisionBox(ray, *this);
//}