#include "Text.hpp"

#include "../font/Font.hpp"

void raylib::Text::Draw(std::string const &title, int const posX, int const posY, int const fontSize, ::Color const &color) {
    ::DrawText(title.c_str(), posX, posY, fontSize, color);
}

int raylib::Text::Measure(std::string const &text, int const fontSize) {
    return ::MeasureText(text.c_str(), fontSize);
}

bool raylib::Text::IsEqual(std::string const &text1, std::string const &text2) {
    return ::TextIsEqual(text1.c_str(), text2.c_str());
}

unsigned int raylib::Text::Length(std::string const &text) {
    return ::TextLength(text.c_str());
}


// void raylib::Text::DrawEx(std::string const &text, raylib::Font font, raylib::Vector2 const &position, float const fontSize, float const spacing, raylib::Color const &tint)
// {
//     ::DrawTextEx(font, text.c_str(), position,fontSize, spacing, tint);
// }