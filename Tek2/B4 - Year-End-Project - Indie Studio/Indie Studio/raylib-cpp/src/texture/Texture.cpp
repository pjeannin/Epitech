#include "Texture.hpp"
#include "../utils/Utils.hpp"

raylib::Texture::Texture() noexcept : loaded(false)
{}

raylib::Texture::Texture(::Texture const &texture) noexcept : loaded(false)
{
    *this = texture;
}

raylib::Texture::Texture(::Image const &image) noexcept : loaded(false)
{
    LoadFromImage(image);
}

raylib::Texture::Texture(::Image const &image, int const layout) noexcept : loaded(false)
{
    LoadCubemap(image, layout);
}

raylib::Texture::Texture(std::string const &fileName) noexcept : loaded(false)
{
    Load(windowsPath(fileName));
}

raylib::Texture::~Texture() noexcept
{
    Unload();
}

raylib::Texture &raylib::Texture::operator=(::Texture const &texture) noexcept
{
    id = texture.id;
    width = texture.width;
    height = texture.height;
    mipmaps = texture.mipmaps;
    format = texture.format;
    loaded = true;
    return *this;
}

::Vector2 raylib::Texture::GetSize() noexcept
{
    return {static_cast<float>(width), static_cast<float>(height)};
}

void raylib::Texture::LoadFromImage(::Image const &image) noexcept
{
    Unload();
    *this =::LoadTextureFromImage(image);
    loaded = true;
}

void raylib::Texture::LoadCubemap(::Image const &image, int const layoutType) noexcept
{
    Unload();
    *this =::LoadTextureCubemap(image, layoutType);
    loaded = true;
}

void raylib::Texture::Load(std::string const &fileName) noexcept
{
    Unload();
    *this =::LoadTexture(windowsPath(fileName).c_str());
    loaded = true;
}

#include <iostream>

void raylib::Texture::Unload() noexcept
{
    if (loaded) {
        ::UnloadTexture(*this);
        loaded = false;
    }
}

raylib::Texture &raylib::Texture::Update(void const *pixels) noexcept
{
    ::UpdateTexture(*this, pixels);
    return *this;
}

raylib::Texture &raylib::Texture::UpdateRec(::Rectangle const &rec, const void *pixels) noexcept
{
    UpdateTextureRec(*this, rec, pixels);
    return *this;
}

::Image const raylib::Texture::GetData() const noexcept
{
    return ::GetTextureData(*this);
}

::Image const raylib::Texture::getData() const noexcept
{
    return GetData();
}

raylib::Texture &raylib::Texture::GenMipmaps() noexcept
{
    ::GenTextureMipmaps(this);
    return *this;
}

raylib::Texture &raylib::Texture::SetFilter(int filterMode) noexcept
{
    ::SetTextureFilter(*this, filterMode);
    return *this;
}

raylib::Texture &raylib::Texture::SetWrap(int const wrapMode) noexcept
{
    ::SetTextureWrap(*this, wrapMode);
    return *this;
}

raylib::Texture &raylib::Texture::Draw() noexcept
{
    return Draw(0, 0);
}

raylib::Texture &raylib::Texture::Draw(int const posX, int const posY, ::Color const &tint) noexcept
{
    ::DrawTexture(*this, posX, posY, tint);
    return *this;
}

raylib::Texture &raylib::Texture::Draw(::Vector2 const &position, ::Color const &tint) noexcept
{
    ::DrawTextureV(*this, position, tint);
    return *this;
}

raylib::Texture &raylib::Texture::Draw(::Vector2 const &position, float const rotation, float const scale, ::Color const &tint) noexcept
{
    ::DrawTextureEx(*this, position, rotation, scale, tint);
    return *this;
}

raylib::Texture &raylib::Texture::Draw(::Rectangle const &sourceRec, ::Vector2 const &position,
        ::Color const &tint) noexcept
{
    ::DrawTextureRec(*this, sourceRec, position, tint);
    return *this;
}

raylib::Texture &raylib::Texture::Draw(::Vector2 const &tiling, ::Vector2 const &offset, ::Rectangle const &quad,
        ::Color const &tint) noexcept
{
    ::DrawTextureQuad(*this, tiling, offset, quad, tint);
    return *this;
}

raylib::Texture &raylib::Texture::Draw(::Rectangle const &sourceRec, ::Rectangle const &destRec, ::Vector2 const &origin,
        float const rotation, ::Color const &tint) noexcept
{
    ::DrawTexturePro(*this, sourceRec, destRec, origin, rotation, tint);
    return *this;
}

raylib::Texture &raylib::Texture::Draw(::NPatchInfo nPatchInfo, ::Rectangle const &destRec, ::Vector2 const &origin,
        float const rotation, ::Color const &tint) noexcept
{
    ::DrawTextureNPatch(*this, nPatchInfo, destRec, origin, rotation, tint);
    return *this;
}

raylib::Texture &raylib::Texture::Draw(::Vector3 const &position, float const width, float const height, float const length,
        ::Color const &tint) noexcept
{
    ::DrawCubeTexture(*this, position, width, height, length, tint);
    return *this;
}

raylib::Texture &raylib::Texture::DrawTiled(::Rectangle const &sourceRec, ::Rectangle const &destRec, ::Vector2 const &origin,
                                    float const rotation, float const scale, Color const &tint) noexcept
{
    ::DrawTextureTiled(*this, sourceRec, destRec, origin, rotation, scale, tint);
    return *this;
}

raylib::Texture &raylib::Texture::DrawPoly(Vector2 const &center, Vector2 *points, Vector2 *texcoords, int const pointsCount, Color const &tint) noexcept
{
    ::DrawTexturePoly(*this, center, points, texcoords, pointsCount, tint);
    return *this;
}

raylib::Texture &raylib::Texture::SetMaterial(::Material *material, int const mapType) noexcept
{
    ::SetMaterialTexture(material, mapType, *this);
    return *this;
}

raylib::Texture &raylib::Texture::SetMaterial(::Material const & material, int const mapType) noexcept
{
    ::SetMaterialTexture((::Material*)(&material), mapType, *this);
    return *this;
}

void raylib::Texture::Load(::Texture const &texture) noexcept
{
    Unload();
    *this = texture;
    loaded = true;

}
