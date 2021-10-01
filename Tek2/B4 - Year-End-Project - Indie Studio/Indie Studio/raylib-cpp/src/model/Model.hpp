#ifndef __MODEL__
#define __MODEL__

#include <string>
#include <raylib.h>

namespace raylib {
    class Model : public ::Model {
    public:
        explicit Model(::Model const &model) noexcept;
        explicit Model(std::string const &fileName) noexcept;
        explicit Model(::Mesh const &mesh) noexcept;
        ~Model() noexcept;
        Model &operator=(::Model const &model) noexcept;
        void unload() noexcept;
        Model &unloadKeepMeshes() noexcept;
        Model &setMeshMaterial(int const meshId, int const materialId) noexcept;
        // RayHitInfo getCollision(::Ray const &ray) const noexcept;
        Model &updateAnimation(::ModelAnimation const &anim, int const frame) noexcept;
        bool isModelAnimationValid(::ModelAnimation const &anim) const noexcept;
        Model &draw(::Vector3 const &position, float const scale = 1.0f, ::Color const &tint = {255, 255, 255, 255}) noexcept;
        Model &draw(
        ::Vector3 const &position, ::Vector3 const &rotationAxis, float const rotationAngle = 0.0f,
        ::Vector3 const &scale = {1.0f, 1.0f, 1.0f}, ::Color const &tint = {255, 255, 255, 255}) noexcept;
        Model &DrawWires(::Vector3 const &position, float const scale = 1.0f, ::Color const &tint = {255, 255, 255, 255}) noexcept;
        Model &DrawWires(::Vector3 const &position, ::Vector3 const &rotationAxis, float const rotationAngle = 0.0f,
        ::Vector3 const &scale = {1.0f, 1.0f, 1.0f}, ::Color const &tint = {255, 255, 255, 255}) noexcept;
    };
}

#endif  /* __MODEL__ */
