#ifndef __TEXTURE__
#define __TEXTURE__

#include <string>
#include <raylib.h>

#include "../color/Color.hpp"

namespace raylib {
    class Texture : public ::Texture {
        public:
            Texture(::Texture const &texture) noexcept;            
            explicit Texture(::Image const &image) noexcept;
            explicit Texture(::Image const &image, int const layout) noexcept;
            explicit Texture(const std::string& fileName) noexcept;
            explicit Texture() noexcept;
            ~Texture() noexcept;
            Texture &operator=(::Texture const &texture) noexcept;
            ::Vector2 GetSize() noexcept;
            void LoadFromImage(::Image const &image) noexcept;
            void LoadCubemap(::Image const &image, int const layoutType) noexcept;
            void Load(const std::string& fileName) noexcept;
            void Load(::Texture const &texture) noexcept;
            void Unload() noexcept;
            Texture &Update(void const *pixels) noexcept;
            Texture &UpdateRec(::Rectangle const &rec, const void *pixels) noexcept;
            ::Image const GetData() const noexcept;
            ::Image const getData() const noexcept;
            Texture &GenMipmaps() noexcept;
            Texture &SetFilter(int const filterMode) noexcept;
            Texture &SetWrap(int const wrapMode) noexcept;
            Texture &Draw() noexcept;
            Texture &Draw(int const posX, int const posY, ::Color const &tint = {255, 255, 255, 255}) noexcept;
            Texture &Draw(::Vector2 const &position, ::Color const &tint = {255, 255, 255, 255}) noexcept;
            Texture &Draw(::Vector2 const &position, float const rotation, float const scale = 1.0f,
                    ::Color const &tint = {255, 255, 255, 255}) noexcept;
            Texture &Draw(::Rectangle const &sourceRec, ::Vector2 const &position = {0, 0},
                    ::Color const &tint = {255, 255, 255, 255}) noexcept;
            Texture &Draw(::Vector2 const &tiling, ::Vector2 const &offset, ::Rectangle const &quad,
                    ::Color const &tint = {255, 255, 255, 255}) noexcept;
            Texture &Draw(::Rectangle const &sourceRec, ::Rectangle const &destRec, ::Vector2 const &origin = {0, 0},
                    float const rotation = 0, ::Color const &tint = {255, 255, 255, 255}) noexcept;
            Texture &Draw(::NPatchInfo nPatchInfo, ::Rectangle const &destRec, ::Vector2 const &origin = {0, 0},
                    float const rotation = 0, ::Color const &tint = {255, 255, 255, 255}) noexcept;
            Texture &Draw(::Vector3 const &position, float const width, float const height, float const length,
                    ::Color const &tint = {255, 255, 255, 255}) noexcept;
            Texture &DrawTiled(::Rectangle const &sourceRec, ::Rectangle const &destRec, ::Vector2 const &origin = {0, 0},
                    float const rotation = 0, float const scale = 1, Color const &tint = raylib::Color::White()) noexcept;
            Texture &DrawPoly(Vector2 const &center, Vector2 *points, Vector2 *texcoords, int const pointsCount,
                    Color const &tint = raylib::Color::White()) noexcept;
            Texture &SetMaterial(::Material *material, int mapType = MATERIAL_MAP_NORMAL) noexcept;
            Texture &SetMaterial(::Material const & material, int mapType = MATERIAL_MAP_NORMAL) noexcept;
            
            bool loaded;
    };
}

#endif  // __TEXTURE__
