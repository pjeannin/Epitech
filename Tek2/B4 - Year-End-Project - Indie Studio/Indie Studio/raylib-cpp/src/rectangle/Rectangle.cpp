#include "Rectangle.hpp"

raylib::Rectangle::Rectangle(::Rectangle const &vec) noexcept 
{
    *this = vec;
}

raylib::Rectangle::Rectangle(float const x, float const y, float const width, float const height) : ::Rectangle{x, y, width, height} {}
raylib::Rectangle::Rectangle(float const x, float const y, float const width) : ::Rectangle{x, y, width, 0} {}
raylib::Rectangle::Rectangle(float const x, float const y) : ::Rectangle{x, y, 0, 0} {}
raylib::Rectangle::Rectangle(float const x) : ::Rectangle{x, 0, 0, 0} {}
raylib::Rectangle::Rectangle() : ::Rectangle{0, 0, 0, 0} {}

raylib::Rectangle::Rectangle(::Vector2 position, ::Vector2 size) : ::Rectangle{position.x, position.y, size.x, size.y} {}
raylib::Rectangle::Rectangle(::Vector2 size) : ::Rectangle{0, 0, size.x, size.y} {}

raylib::Rectangle &raylib::Rectangle::operator=(::Rectangle const &rect) noexcept 
{
    x = rect.x;
    y = rect.y;
    width = rect.width;
    height = rect.height;
    return *this;
}

::Vector4 raylib::Rectangle::ToVector4() noexcept 
{
    return {x, y, width, height};
}

raylib::Rectangle::operator ::Vector4() const noexcept 
{
    return {x, y, width, height};
}

raylib::Rectangle &raylib::Rectangle::Draw(::Color const &color) noexcept 
{
    ::DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
        static_cast<int>(height), color);
    return *this;
}

raylib::Rectangle &raylib::Rectangle::Draw(::Vector2 const &origin, float const rotation, ::Color const &color) noexcept 
{
    ::DrawRectanglePro(*this, origin, rotation, color);
    return *this;
}

raylib::Rectangle &raylib::Rectangle::DrawGradientV(::Color const &color1, ::Color const &color2) noexcept 
{
    ::DrawRectangleGradientV(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
        static_cast<int>(height), color1, color2);
    return *this;
}

raylib::Rectangle &raylib::Rectangle::DrawGradientH(::Color const &color1, ::Color const &color2) noexcept 
{
    ::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
        static_cast<int>(height), color1, color2);
    return *this;
}

raylib::Rectangle &raylib::Rectangle::DrawGradient(::Color const &col1, ::Color const &col2, ::Color const &col3, ::Color const &col4) noexcept 
{
    ::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
    return *this;
}

raylib::Rectangle &raylib::Rectangle::DrawLines(::Color const &color) noexcept 
{
    ::DrawRectangleLines(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
        static_cast<int>(height), color);
    return *this;
}

raylib::Rectangle &raylib::Rectangle::DrawLines(::Color const &color, int const lineThick) noexcept 
{
    ::DrawRectangleLinesEx(*this, lineThick, color);
    return *this;
}

raylib::Rectangle &raylib::Rectangle::DrawRounded(float const roundness, int const segments, ::Color const &color) noexcept 
{
    ::DrawRectangleRounded(*this, roundness, segments, color);
    return *this;
}

raylib::Rectangle &raylib::Rectangle::DrawRoundedLines(float const roundness, int const segments, int const lineThick,
        ::Color const &color) noexcept 
{
    ::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
    return *this;
}

bool raylib::Rectangle::CheckCollision(::Rectangle const &rec2) const noexcept 
{
    return ::CheckCollisionRecs(*this, rec2);
}

::Rectangle raylib::Rectangle::GetCollision(::Rectangle const &rec2) const noexcept 
{
    return ::GetCollisionRec(*this, rec2);
}

bool raylib::Rectangle::CheckCollision(::Vector2 const &point) const noexcept 
{
    return ::CheckCollisionPointRec(point, *this);
}

bool raylib::Rectangle::CheckCollision(::Vector2 const &center, float const radius) noexcept 
{
    return ::CheckCollisionCircleRec(center, radius, *this);
}

::Vector2 raylib::Rectangle::GetSize() noexcept 
{
    return {width, height};
}

raylib::Rectangle &raylib::Rectangle::SetSize(float const newWidth, float const newHeight) noexcept 
{
    width = newWidth;
    height = newHeight;
    return *this;
}

raylib::Rectangle &raylib::Rectangle::SetSize(::Vector2 const &size) noexcept 
{
    return SetSize(size.x, size.y);
}

::Vector2 raylib::Rectangle::getPosition() noexcept 
{
    return {x, y};
}

raylib::Rectangle &raylib::Rectangle::setPosition(float const newX, float const newY) noexcept 
{
    x = newX;
    y = newY;
    return *this;
}

raylib::Rectangle &raylib::Rectangle::setPosition(::Vector2 const &position) noexcept 
{
    return setPosition(position.x, position.y);
}
