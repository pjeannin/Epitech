#ifndef __MESH__
#define __MESH__

#include <string>
#include <vector>
#include <raylib.h>

#include "../boundingBox/BoundingBox.hpp"
#include "../model/Model.hpp"

namespace raylib {
    class Mesh : public ::Mesh {
    public:
        explicit Mesh(::Mesh const &mesh) noexcept;
        explicit Mesh(int const VertexCount, int const TriangleCount) noexcept;
        static ::Mesh poly(int const sides, float const radius) noexcept;
        static ::Mesh plane(float const width, float const length, int const resX, int const resZ) noexcept;
        static ::Mesh cube(float const width, float const height, float const length) noexcept;
        static ::Mesh sphere(float const radius, int const rings, int const slices) noexcept;
        static ::Mesh hemiSphere(float const radius, int const rings, int const slices) noexcept;
        static ::Mesh cylinder(float const radius, float const height, int const slices) noexcept;
        static ::Mesh torus(float const radius, float const size, int const radSeg, int const sides) noexcept;
        static ::Mesh knot(float const radius, float const size, int const radSeg, int const sides) noexcept;
        static ::Mesh heightmap(::Image const &heightmap, ::Vector3 const &size) noexcept;
        static ::Mesh cubicmap(::Image const &cubicmap, ::Vector3 const &cubeSize) noexcept;
        Mesh &operator=(::Mesh const &mesh) noexcept;
        ~Mesh() noexcept;
        void upload(bool const dynamic = false) noexcept;
        void updateBuffer(int const index, void *data, int const dataSize, int const offset = 0) noexcept;
        void draw(::Material const &material, ::Matrix const &transform) noexcept;
        void drawInstanced(::Material const &material, ::Matrix *transforms, int const instances) noexcept;
        bool Export(std::string const &fileName) noexcept;
        void unload() noexcept;
        raylib::BoundingBox boundingBox() const noexcept;
        Mesh &Tangents() noexcept;
        Mesh &binormals() noexcept;
        raylib::Model loadModelFrom() const noexcept;
    };
}

#endif  /* __MESH__ */
