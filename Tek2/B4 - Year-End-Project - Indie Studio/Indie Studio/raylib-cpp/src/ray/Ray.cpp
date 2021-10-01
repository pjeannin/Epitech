#include "Ray.hpp"

raylib::Ray::Ray(::Ray const &ray) noexcept 
{
    position = ray.position;
    direction = ray.direction;
}

raylib::Ray::Ray(::Vector3 const &Position, ::Vector3 const &Direction) noexcept 
{
    position = Position;
    direction = Direction;
}

raylib::Ray::Ray(::Vector2 const &mousePosition, ::Camera const &camera) noexcept 
{
    *this = ::GetMouseRay(mousePosition, camera);
}

raylib::Ray &raylib::Ray::operator=(::Ray const &ray) noexcept 
{
    *this = ray;
    return *this;
}

raylib::Ray &raylib::Ray::draw(::Color const &color) noexcept 
{
    DrawRay(*this, color);
    return *this;
}

// bool raylib::Ray::checkCollisionSphere(::Vector3 const &center, float const radius) const noexcept 
// {
//     return ::GetRayCollisionSphere(*this, center, radius);
// }

// bool raylib::Ray::checkCollisionSphere(::Vector3 const &center, float const radius, ::Vector3 *collisionPoint) const noexcept 
// {
//     return ::CheckCollisionRaySphereEx(*this, center, radius, collisionPoint);
// }

// bool raylib::Ray::checkCollision(::BoundingBox const &box) const noexcept 
// {
//     return ::CheckCollisionRayBox(*this, box);
// }

// ::RayHitInfo raylib::Ray::getCollision(::Model const &model) const noexcept 
// {
//     return ::GetCollisionRayModel(*this, model);
// }

// ::RayHitInfo raylib::Ray::getCollisionTriangle(::Vector3 const &p1, ::Vector3 const &p2, ::Vector3 const &p3) const noexcept 
// {
//     return ::GetCollisionRayTriangle(*this, p1, p2, p3);
// }

// ::RayHitInfo raylib::Ray::getCollisionGround(float const groundHeight) const noexcept 
// {
//     return ::GetCollisionRayGround(*this, groundHeight);
// }bool
