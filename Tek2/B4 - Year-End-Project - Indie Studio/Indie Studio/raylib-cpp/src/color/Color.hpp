/*
** EPITECH PROJECT, 2021
** color
** File description:
** color
*/

#ifndef __COLOR__
#define __COLOR__

#include <raylib.h>
#include <string>

namespace raylib {
    class Color : public ::Color {
    public:
        explicit Color(::Color const &color) noexcept;
        explicit Color(unsigned char const red, unsigned char const green, unsigned char const blue, unsigned char const alpha = 255);
        explicit Color();
        explicit Color(::Vector3 hsv) noexcept;
        static ::Color const FromHSV(float const hue, float const saturation, float const value) noexcept;
        Color(int const hexValue) noexcept;
        Color(::Vector4 normalized) noexcept;
        int ToInt() const noexcept;
        operator int() const noexcept;
        Color Fade(float const alpha) const noexcept;
        Vector4 Normalize() const noexcept;
        Vector3 ToHSV() const noexcept;
        Color &operator=(::Color const &color) noexcept;
        Color &ClearBackground() noexcept;
        Color &DrawPixel(int const x, int const y) noexcept;
        Color &DrawPixel(::Vector2 const &pos) noexcept;
        Color &DrawLine(int const startPosX, int const startPosY, int const endPosX, int const endPosY) noexcept;
        Color &DrawLine(::Vector2 const &startPos, ::Vector2 const &endPos) noexcept;
        Color &DrawLine(::Vector2 const &startPos, ::Vector2 const &endPos, float const thick) noexcept;
        Color &DrawLineBezier(::Vector2 const &startPos, ::Vector2 const &endPos, float const thick) noexcept;
        Color &DrawLineStrip(::Vector2 *points, int const numPoints) noexcept;
        Color &DrawText(std::string const &text, int const posX, int const posY, int const fontSize) noexcept;
        Color &DrawText(::Font const &font, std::string const &text, ::Vector2 const &position,
                               float const fontSize, float const spacing) noexcept;
        Color &DrawText(::Font const &font, std::string const &text, ::Rectangle const &rec,
                        float const fontSize, float const spacing, bool const wordWrap = false) noexcept;
        Color &DrawRectangle(int const posX, int const posY, int const width, int const height) noexcept;
        Color &DrawRectangle(::Vector2 const &position, ::Vector2 const &size) noexcept;
        Color &DrawRectangle(::Rectangle const &rec) noexcept;
        Color &DrawRectangle(::Rectangle const &rec, ::Vector2 const &origin, float const rotation) noexcept;
        Color &DrawRectangleLines(int const posX, int const posY, int const width, int const height) noexcept;
        Color &DrawRectangleLines(::Rectangle const &rec, int const lineThick) noexcept;
        Color Alpha(float const alpha) const noexcept;
        Color AlphaBlend(::Color const &dst, ::Color const &tint) const noexcept;
        static Color LightGray();
        static Color Gray();
        static Color DarkGray();
        static Color Yellow();
        static Color Gold();
        static Color Orange();
        static Color Pink();
        static Color Red();
        static Color Maroon();
        static Color Green();
        static Color Lime();
        static Color DarkGreen();
        static Color SkyBlue();
        static Color Blue();
        static Color DarkBlue();
        static Color Purple();
        static Color Violet();
        static Color DarkPurple();
        static Color Beige();
        static Color Brown();
        static Color DarkBrown();
        static Color White();
        static Color Black();
        static Color Blank();
        static Color Magenta();
        static Color RayWhite();
    };

}

#endif /* __COLOR__ */
