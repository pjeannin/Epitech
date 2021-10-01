#ifndef __RAY_COLLISION__
#define __RAY_COLLISION__

#include <raylib.h>

namespace raylib {
    /**
     * Raycast hit information
     */
    class RayCollision : public ::RayHitInfo {
    public:
        RayCollision(::RayHitInfo const &ray);
        explicit RayCollision(bool const Hit, float const Distance, ::Vector3 const Point, ::Vector3 const Normal);
        explicit RayCollision(::Ray const &ray, ::Mesh const &mesh, const ::Matrix& transform);

        /**
         * Get collision info between ray and model
         */
        explicit RayCollision(::Ray const &ray, ::Model const &model);

        /**
         * Get collision info between ray and triangle
         */
        explicit RayCollision(::Ray const &ray, ::Vector3 const &p1, ::Vector3 const &p2, ::Vector3 const &p3);

        RayCollision &operator=(::RayHitInfo const &ray);
    };
}

#endif  // __RAY_COLLISION__
