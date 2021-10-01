#ifndef __RECTANGLE__
#define __RECTANGLE__

#include <raylib.h>

namespace raylib {
    class Rectangle : public ::Rectangle {
    public:
        explicit Rectangle(::Rectangle const &vec) noexcept;
        explicit Rectangle(float const x, float const y, float const width, float const height);
        explicit Rectangle(float const x, float const y, float const width);
        explicit Rectangle(float const x, float const y);
        explicit Rectangle(float const x);
        explicit Rectangle();

        explicit Rectangle(::Vector2 position, ::Vector2 size);
        explicit Rectangle(::Vector2 size);

        Rectangle &operator=(::Rectangle const &rect) noexcept;
        ::Vector4 ToVector4() noexcept;
        operator ::Vector4() const noexcept;
        Rectangle &Draw(::Color const &color) noexcept;
        Rectangle &Draw(::Vector2 const &origin, float const rotation, ::Color const &color) noexcept;
        Rectangle &DrawGradientV(::Color const &color1, ::Color const &color2) noexcept;
        Rectangle &DrawGradientH(::Color const &color1, ::Color const &color2) noexcept;
        Rectangle &DrawGradient(::Color const &col1, ::Color const &col2, ::Color const &col3, ::Color const &col4) noexcept;
        Rectangle &DrawLines(::Color const &color) noexcept;
        Rectangle &DrawLines(::Color const &color, int const lineThick) noexcept;
        Rectangle &DrawRounded(float const roundness, int const segments, ::Color const &color) noexcept;
        Rectangle &DrawRoundedLines(float const roundness, int const segments, int const lineThick, ::Color const &color) noexcept;
        bool CheckCollision(::Rectangle const &rec2) const noexcept;
        ::Rectangle GetCollision(::Rectangle const &rec2) const noexcept;
        bool CheckCollision(::Vector2 const &point) const noexcept;
        bool CheckCollision(::Vector2 const &center, float const radius) noexcept;
        ::Vector2 GetSize() noexcept;
        Rectangle &SetSize(float const newWidth, float const newHeight) noexcept;
        Rectangle &SetSize(::Vector2 const &size) noexcept;
        ::Vector2 getPosition() noexcept;
        Rectangle &setPosition(float const newX, float const newY) noexcept;
        Rectangle &setPosition(::Vector2 const &position) noexcept;
    };
}

#endif  /* __RECTANGLE__ */
