/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** bomberman
*/


#ifndef BOMBERMAN_TEXT_HPP
#define BOMBERMAN_TEXT_HPP

#include "../../../raylib-cpp/src/text/Text.hpp"
#include "../../../raylib-cpp/src/color/Color.hpp"

#include <string>

namespace Bomberman {
    class Text {
    public:
        explicit Text(raylib::Vector2 const &pos_ = raylib::Vector2(0, 0), raylib::Font *font_ = nullptr, float constfontSize = 35, float const spacing = 2, raylib::Color const &color = raylib::Color::White()) noexcept;

        void draw(std::string const &text) noexcept;
        raylib::Vector2 pos;
        raylib::Font *font;
        float fontSize, spacing;
        raylib::Color color;
    };
}
#endif //BOMBERMAN_TEXT_HPP
