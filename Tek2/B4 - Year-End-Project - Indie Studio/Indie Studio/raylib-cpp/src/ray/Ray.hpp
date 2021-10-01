#ifndef __RAY__
#define __RAY__

#include <raylib.h>

namespace raylib {
    class Ray : public ::Ray {
    public:
        explicit Ray(::Ray const &ray) noexcept;
        explicit Ray(::Vector3 const &Position, ::Vector3 const &Direction) noexcept;
        explicit Ray(::Vector2 const &mousePosition, ::Camera const &camera) noexcept;
        Ray &operator=(::Ray const &ray) noexcept;
        Ray &draw(::Color const &color) noexcept;
        // bool checkCollisionSphere(::Vector3 const &center, float const radius) const noexcept;
        // bool checkCollisionSphere(::Vector3 const &center, float const radius, ::Vector3 *collisionPoint) const noexcept;
        // bool checkCollision(::BoundingBox const &box) const noexcept;
        // ::RayHitInfo getCollision(::Model const &model) const noexcept;
        // ::RayHitInfo getCollisionTriangle(::Vector3 const &p1, ::Vector3 const &p2, ::Vector3 const &p3) const noexcept;
        // ::RayHitInfo getCollisionGround(float const groundHeight) const noexcept;
    };
}

#endif  /* __RAY__ */
