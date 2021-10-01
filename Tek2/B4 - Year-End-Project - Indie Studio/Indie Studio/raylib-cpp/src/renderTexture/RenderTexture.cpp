#include "RenderTexture.hpp"

raylib::RenderTexture::RenderTexture(::RenderTexture const &renderTexture) noexcept 
{
    *this = renderTexture;
}

raylib::RenderTexture::RenderTexture(unsigned int const Id) noexcept 
{
    id = Id;
}

raylib::RenderTexture::RenderTexture(int const width, int const height) noexcept 
{
    *this = LoadRenderTexture(width, height);
}

raylib::RenderTexture& raylib::RenderTexture::operator=(::RenderTexture const &texture_) noexcept 
{
    id = texture_.id;
    texture = texture_.texture;
    depth = texture_.depth;
    return *this;
}

raylib::RenderTexture::~RenderTexture() noexcept 
{
    Unload();
}

void raylib::RenderTexture::Unload() noexcept 
{
    UnloadRenderTexture(*this);
}

raylib::RenderTexture& raylib::RenderTexture::BeginMode() noexcept 
{
    ::BeginTextureMode(*this);
    return *this;
}

raylib::RenderTexture& raylib::RenderTexture::EndMode() noexcept 
{
    ::EndTextureMode();
    return *this;
}
