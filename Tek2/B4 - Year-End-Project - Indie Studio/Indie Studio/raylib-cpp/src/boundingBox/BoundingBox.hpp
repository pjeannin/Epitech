#ifndef RAYLIB_CPP_INCLUDE_BOUNDINGBOX_HPP_
#define RAYLIB_CPP_INCLUDE_BOUNDINGBOX_HPP_

#include <raylib.h>

namespace raylib {
    class BoundingBox : public ::BoundingBox {
    public:
        BoundingBox(::BoundingBox const &box) noexcept;

        /**
         * Compute mesh bounding box limits
         */
        BoundingBox(::Mesh const &mesh) noexcept;
        BoundingBox(::Vector3 const &minMax) noexcept;
        BoundingBox(::Vector3 const &Min, ::Vector3 const &Max) noexcept;
        BoundingBox& operator=(::BoundingBox const &box) noexcept;

        /**
         * Draw a bounding box with wires
         */
        BoundingBox& Draw(::Color const &color = {255, 255, 255, 255}) noexcept;

        /**
         * Detect collision between two boxes
         */
        bool CheckCollision(::BoundingBox const &box2) const noexcept;

        /**
         * Detect collision between box and sphere
         */
        bool CheckCollision(::Vector3 const &center, float const radius) const noexcept;

        /**
         * Detect collision between ray and bounding box
         */
        //::RayCollision CheckCollision(::Ray const &ray) const noexcept;
    };
}

#endif  /* __BOUNDING_BOX__ */
