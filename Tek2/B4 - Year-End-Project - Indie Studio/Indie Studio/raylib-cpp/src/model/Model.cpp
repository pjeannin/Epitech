#include "Model.hpp"
#include "../utils/Utils.hpp"

raylib::Model::Model(::Model const &model) noexcept
{
    *this = model;
}

raylib::Model::Model(std::string const &fileName) noexcept
{
    *this = ::LoadModel(windowsPath(fileName).c_str());
}

raylib::Model::Model(::Mesh const &mesh) noexcept
{
    *this = ::LoadModelFromMesh(mesh);
}

raylib::Model::~Model() noexcept
{
    unload();
}

raylib::Model &raylib::Model::operator=(::Model const &model) noexcept
{
    transform = model.transform;
    meshCount = model.meshCount;
    materialCount = model.materialCount;
    meshes = model.meshes;
    materials = model.materials;
    meshMaterial = model.meshMaterial;
    boneCount = model.boneCount;
    bones = model.bones;
    bindPose = model.bindPose;
    return *this;
}

void raylib::Model::unload() noexcept
{
        ::UnloadModel(*this);
        meshes = NULL;
        materials = NULL;
}

raylib::Model &raylib::Model::unloadKeepMeshes() noexcept
{
    ::UnloadModelKeepMeshes(*this);
    return *this;
}

raylib::Model &raylib::Model::setMeshMaterial(int const meshId, int const materialId) noexcept
{
    ::SetModelMeshMaterial(this, meshId, materialId);
    return *this;
}

// RayHitInfo raylib::Model::getCollision(::Ray const &ray) const noexcept
// {
//     return ::GetCollisionRayModel(ray, *this);
// }

raylib::Model &raylib::Model::updateAnimation(::ModelAnimation const &anim, int const frame) noexcept
{
    ::UpdateModelAnimation(*this, anim, frame);
    return *this;
}

bool raylib::Model::isModelAnimationValid(::ModelAnimation const &anim) const noexcept
{
    return ::IsModelAnimationValid(*this, anim);
}

raylib::Model &raylib::Model::draw(::Vector3 const &position, float const scale, ::Color const &tint) noexcept
{
    ::DrawModel(*this, position, scale, tint);
    return *this;
}

raylib::Model &raylib::Model::draw(
::Vector3 const &position, ::Vector3 const &rotationAxis, float const rotationAngle, ::Vector3 const &scale, ::Color const &tint) noexcept
{
    ::DrawModelEx(*this, position, rotationAxis, rotationAngle, scale, tint);
    return *this;
}

raylib::Model &raylib::Model::DrawWires(::Vector3 const &position, float const scale, ::Color const &tint) noexcept
{
    ::DrawModelWires(*this, position, scale, tint);
    return *this;
}

raylib::Model &raylib::Model::DrawWires(::Vector3 const &position, ::Vector3 const &rotationAxis, float const rotationAngle, ::Vector3 const &scale, ::Color const &tint) noexcept
{
    ::DrawModelWiresEx(*this, position, rotationAxis, rotationAngle, scale, tint);
    return *this;
}
