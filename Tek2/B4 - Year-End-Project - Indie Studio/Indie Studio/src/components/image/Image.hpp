/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** TODO: add description
*/


#ifndef BOMBERMAN_IMAGE_HPP
#define BOMBERMAN_IMAGE_HPP

#include "../../../raylib-cpp/src/texture/Texture.hpp"
#include "../../../raylib-cpp/src/vector/Vector.hpp"

#include <string>

namespace Bomberman {
    class Image {
    public:
        explicit Image(std::string const &path, raylib::Vector2 const &pos_ = raylib::Vector2(0, 0), float const roation_ = 0, float const scale_ = 1, raylib::Color const &color_ = raylib::Color::White()) noexcept;
        explicit Image() noexcept;
        explicit Image(raylib::Texture const &texture, raylib::Vector2 const &pos_ = raylib::Vector2(0, 0), float const roation_ = 0, float const scale_ = 1, raylib::Color const &color_ = raylib::Color::White()) noexcept;
        void draw() const noexcept;
        void draw(raylib::Vector2 const &pos) const noexcept;
        void load(std::string const &path, raylib::Vector2 const &pos_ = raylib::Vector2(0, 0), float const roation_ = 0, float const scale_ = 0, raylib::Color const &color_ = raylib::Color::White()) noexcept;
        void load(raylib::Texture *texture, raylib::Vector2 const &pos_ = raylib::Vector2(0, 0), float const roation_ = 0, float const scale_ = 0, raylib::Color const &color_ = raylib::Color::White()) noexcept;

        raylib::Texture *val;
        raylib::Vector2 pos;
        raylib::Color color;
        float scale;
        float rotation;
    };
}
#endif //BOMBERMAN_IMAGE_HPP
