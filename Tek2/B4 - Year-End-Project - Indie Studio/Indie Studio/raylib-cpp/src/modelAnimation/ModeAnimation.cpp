#include "ModelAnimation.hpp"
#include "../utils/Utils.hpp"

raylib::ModelAnimation::ModelAnimation(::ModelAnimation const &model) noexcept
{
    *this = model;
}

raylib::ModelAnimation::~ModelAnimation() noexcept 
{
    unload();
}

std::vector<raylib::ModelAnimation> raylib::ModelAnimation::load(std::string const &fileName) noexcept 
{
    int count = 0;
    ::ModelAnimation *modelAnimations = ::LoadModelAnimations(windowsPath(fileName).c_str(), &count);
    
    return std::vector<raylib::ModelAnimation>(modelAnimations, modelAnimations + count);
}

raylib::ModelAnimation& raylib::ModelAnimation::operator=(::ModelAnimation const &model) noexcept 
{
    boneCount = model.boneCount;
    bones = model.bones;
    frameCount = model.frameCount;
    framePoses = model.framePoses;
    return *this;
}

void raylib::ModelAnimation::unload() noexcept 
{
    ::UnloadModelAnimation(*this);
}

raylib::ModelAnimation& raylib::ModelAnimation::update(::Model const &model, int const frame) noexcept 
{
    ::UpdateModelAnimation(model, *this, frame);
    return *this;
}

bool raylib::ModelAnimation::isValid(::Model const &model) const noexcept 
{
    return ::IsModelAnimationValid(model, *this);
}
