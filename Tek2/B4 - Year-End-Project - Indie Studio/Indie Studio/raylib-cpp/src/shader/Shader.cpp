#include "Shader.hpp"
#include "../utils/Utils.hpp"

raylib::Shader::Shader(::Shader const &shader) noexcept 
{
    *this = shader;
}

raylib::Shader::Shader(unsigned int const id_, int *locs_) noexcept 
{
    id = id_;
    locs = locs_;
}

raylib::Shader::Shader(std::string const &vsFileName, std::string const &fsFileName) noexcept 
{
    *this = ::LoadShader(windowsPath(vsFileName).c_str(), windowsPath(fsFileName).c_str());
}

::Shader raylib::Shader::Load(std::string const &vsFileName, std::string const &fsFileName) noexcept 
{
    return ::LoadShader(windowsPath(vsFileName).c_str(), windowsPath(fsFileName).c_str());
}

::Shader raylib::Shader::LoadFromMemory(std::string const &vsCode, std::string const &fsCode) noexcept 
{
    return ::LoadShaderFromMemory(windowsPath(vsCode).c_str(), windowsPath(fsCode).c_str());
}

raylib::Shader &raylib::Shader::operator=(::Shader const &shader) noexcept 
{
    *this = shader;
    return *this;
}

raylib::Shader::~Shader() noexcept 
{
    Unload();
}

void raylib::Shader::Unload() noexcept 
{
    if (locs)
        ::UnloadShader(*this);
}

raylib::Shader &raylib::Shader::BeginMode() noexcept 
{
    ::BeginShaderMode(*this);
    return *this;
}

raylib::Shader &raylib::Shader::EndMode() noexcept 
{
    ::EndShaderMode();
    return *this;
}

int raylib::Shader::GetLocation(std::string const &uniformName) const noexcept 
{
    return ::GetShaderLocation(*this, uniformName.c_str());
}

int raylib::Shader::GetLocationAttrib(std::string const &attribName) const noexcept 
{
    return ::GetShaderLocationAttrib(*this, attribName.c_str());
}

raylib::Shader &raylib::Shader::SetValue(int const uniformLoc, std::string const &value, int const uniformType) noexcept 
{
    ::SetShaderValue(*this, uniformLoc, value.c_str(), uniformType);
    return *this;
}

raylib::Shader &raylib::Shader::SetValue(int const uniformLoc, std::string const &value, int const uniformType, int const count) noexcept 
{
    ::SetShaderValueV(*this, uniformLoc, value.c_str(), uniformType, count);
    return *this;
}

raylib::Shader &raylib::Shader::SetValue(int const uniformLoc, ::Matrix const &mat) noexcept 
{
    ::SetShaderValueMatrix(*this, uniformLoc, mat);
    return *this;
}

raylib::Shader &raylib::Shader::SetValue(int const uniformLoc, const ::Texture2D& texture) noexcept 
{
    ::SetShaderValueTexture(*this, uniformLoc, texture);
    return *this;
}
