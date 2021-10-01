#ifndef __TEXT__
#define __TEXT__

#include <string>
#include <raylib.h>

#include "../color/Color.hpp"
#include "../vector/Vector.hpp"
#include "../font/Font.hpp"

namespace raylib {
    namespace Text {
        static void Draw(std::string const &title, int const posX, int const posY, int const fontSize, ::Color const &color);
        static int Measure(std::string const &text, int const fontSize);
        static bool IsEqual(std::string const &text1, std::string const &text2);
        static unsigned int Length(std::string const &text);
        static void DrawEx(std::string const &text, raylib::Font font, raylib::Vector2 const &position, float const fontSize, float const spacing, raylib::Color const &tint = raylib::Color::White())
        {
            ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
        }
    }
}

#endif  /* __TEXT__ */
