/*
** EPITECH PROJECT, 2021
** color
** File description:
** color
*/

#include "Color.hpp"

raylib::Color::Color(::Color const &color) noexcept
{
    *this = color;
}

raylib::Color::Color(unsigned char const red, unsigned char const green, unsigned char const blue, unsigned char const alpha) :
    ::Color{red, green, blue, alpha} {};

raylib::Color::Color() : ::Color{0, 0, 0, 255} {};

raylib::Color::Color(::Vector3 hsv) noexcept
{
    *this = ::ColorFromHSV(hsv.x, hsv.y, hsv.z);
}

::Color const raylib::Color::FromHSV(float const hue, float const saturation, float const value) noexcept
{
    return ::ColorFromHSV(hue, saturation, value);
}

raylib::Color::Color(int const hexValue) noexcept
{
    *this = ::GetColor(hexValue);
}

raylib::Color::Color(::Vector4 normalized) noexcept
{
    *this = ::ColorFromNormalized(normalized);
}

int raylib::Color::ToInt() const noexcept
{
    return ::ColorToInt(*this);
}

raylib::Color::operator int() const noexcept
{
    return ::ColorToInt(*this);
}

raylib::Color raylib::Color::Fade(float const alpha) const noexcept
{
    return static_cast<raylib::Color>(::Fade(*this, alpha));
}

Vector4 raylib::Color::Normalize() const noexcept
{
    return ::ColorNormalize(*this);
}

Vector3 raylib::Color::ToHSV() const noexcept
{
    return ::ColorToHSV(*this);
}

raylib::Color &raylib::Color::operator=(::Color const &color) noexcept
{
    r = color.r;
    g = color.g;
    b = color.b;
    a = color.a;
    return *this;
}

raylib::Color &raylib::Color::ClearBackground() noexcept
{
    ::ClearBackground(*this);
    return *this;
}

raylib::Color &raylib::Color::DrawPixel(int const x, int const y) noexcept
{
    ::DrawPixel(x, y, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawPixel(::Vector2 const &pos) noexcept
{
    ::DrawPixelV(pos, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawLine(int const startPosX, int const startPosY, int const endPosX, int const endPosY) noexcept
{
    ::DrawLine(startPosX, startPosY, endPosX, endPosY, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawLine(::Vector2 const &startPos, ::Vector2 const &endPos) noexcept
{
    ::DrawLineV(startPos, endPos, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawLine(::Vector2 const &startPos, ::Vector2 const &endPos, float const thick) noexcept
{
    ::DrawLineEx(startPos, endPos, thick, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawLineBezier(::Vector2 const &startPos, ::Vector2 const &endPos, float const thick) noexcept
{
    ::DrawLineBezier(startPos, endPos, thick, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawLineStrip(::Vector2 *points, int const numPoints) noexcept
{
    ::DrawLineStrip(points, numPoints, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawText(std::string const &text, int const posX, int const posY, int const fontSize) noexcept
{
    ::DrawText(text.c_str(), posX, posY, fontSize, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawText(::Font const &font, std::string const &text, ::Vector2 const &position,
                float const fontSize, float const spacing) noexcept
{
    ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawText(::Font const &font, std::string const &text, ::Rectangle const &rec,
                float const fontSize, float const spacing, bool const wordWrap) noexcept
{
    ::DrawTextRec(font, text.c_str(), rec, fontSize, spacing, wordWrap, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawRectangle(int const posX, int const posY, int const width, int const height) noexcept
{
    ::DrawRectangle(posX, posY, width, height, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawRectangle(::Vector2 const &position, ::Vector2 const &size) noexcept
{
    ::DrawRectangleV(position, size, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawRectangle(::Rectangle const &rec) noexcept
{
    ::DrawRectangleRec(rec, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawRectangle(::Rectangle const &rec, ::Vector2 const &origin, float const rotation) noexcept
{
    ::DrawRectanglePro(rec, origin, rotation, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawRectangleLines(int const posX, int const posY, int const width, int const height) noexcept
{
    ::DrawRectangleLines(posX, posY, width, height, *this);
    return *this;
}

raylib::Color &raylib::Color::DrawRectangleLines(::Rectangle const &rec, int const lineThick) noexcept
{
    ::DrawRectangleLinesEx(rec, lineThick, *this);
    return *this;
}

raylib::Color raylib::Color::Alpha(float const alpha) const noexcept
{
    return static_cast<raylib::Color>(::ColorAlpha(*this, alpha));
}

raylib::Color raylib::Color::AlphaBlend(::Color const &dst, ::Color const &tint) const noexcept
{
    return static_cast<raylib::Color>(::ColorAlphaBlend(dst, *this, tint));
}

raylib::Color raylib::Color::LightGray() { return LIGHTGRAY; }
raylib::Color raylib::Color::Gray() { return GRAY; }
raylib::Color raylib::Color::DarkGray() { return DARKGRAY; }
raylib::Color raylib::Color::Yellow() { return YELLOW; }
raylib::Color raylib::Color::Gold() { return GOLD; }
raylib::Color raylib::Color::Orange() { return ORANGE; }
raylib::Color raylib::Color::Pink() { return PINK; }
raylib::Color raylib::Color::Red() { return RED; }
raylib::Color raylib::Color::Maroon() { return MAROON; }
raylib::Color raylib::Color::Green() { return GREEN; }
raylib::Color raylib::Color::Lime() { return LIME; }
raylib::Color raylib::Color::DarkGreen() { return DARKGREEN; }
raylib::Color raylib::Color::SkyBlue() { return SKYBLUE; }
raylib::Color raylib::Color::Blue() { return BLUE; }
raylib::Color raylib::Color::DarkBlue() { return DARKBLUE; }
raylib::Color raylib::Color::Purple() { return PURPLE; }
raylib::Color raylib::Color::Violet() { return VIOLET; }
raylib::Color raylib::Color::DarkPurple() { return DARKPURPLE; }
raylib::Color raylib::Color::Beige() { return BEIGE; }
raylib::Color raylib::Color::Brown() { return BROWN; }
raylib::Color raylib::Color::DarkBrown() { return DARKBROWN; }
raylib::Color raylib::Color::White() { return WHITE; }
raylib::Color raylib::Color::Black() { return BLACK; }
raylib::Color raylib::Color::Blank() { return BLANK; }
raylib::Color raylib::Color::Magenta() { return MAGENTA; }
raylib::Color raylib::Color::RayWhite() { return RAYWHITE; }
