/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** bomberman
*/

#include "../../../raylib-cpp/src/color/Color.hpp"
#include "../../../raylib-cpp/src/texture/Texture.hpp"
#include "../../../raylib-cpp/src/vector/Vector.hpp"
#include "../../../raylib-cpp/src/rectangle/Rectangle.hpp"

#include <string>
#include <functional>

#ifndef BOMBERMAN_BUTTON_HPP
#define BOMBERMAN_BUTTON_HPP

#define GET_BOUNDS_X(offset) (float)core.getWidth() / 2.0f - (float)button->texture->width / 2.0f offset
#define GET_BOUNDS_Y(offset) (float)core.getHeight() / 2.0f - (float)button->texture->height / 3 / 2.0f offset
#define SET_BUTTONS_BOUNDS(name, X, Y) button = _buttons[ButtonsList::name]; \
button->bounds = raylib::Rectangle( GET_BOUNDS_X(X),  GET_BOUNDS_Y(Y), (float)button->texture->width, (float)button->frameHeight)

namespace Bomberman {
    class Button {
    public:
        explicit Button() noexcept;
        explicit Button(std::string const &texture_, unsigned char const nbFrames = 2) noexcept;
        explicit Button(raylib::Texture *texture_, unsigned char const nbFrames = 2) noexcept;

        ~Button() noexcept = default;

        void loadTexture(std::string const &path, unsigned char const nbFrames = 2) noexcept;
        void loadTexture(raylib::Texture *texture_, unsigned char const nbFrames = 2) noexcept;
        void draw(raylib::Color const &color = raylib::Color::White()) noexcept;
        bool check(std::function<void(Button &button)> onClick, std::function<void(Button &button)> onHover, std::function<bool(Button &button)> isNotDisabled = [](Button &button) {
            return true;
        }) noexcept;

        void reset() noexcept;

        void draw(raylib::Vector2 const &pos, raylib::Color const &color = raylib::Color::White()) const noexcept;

        raylib::Texture *texture;
        float frameHeight;
        raylib::Rectangle sourceRect;
        raylib::Rectangle bounds;
        bool action;
        unsigned char state;
        bool hover;
    private:
        bool loadedInClass;
    };
}

#endif //BOMBERMAN_BUTTON_HPP
