/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** bomberman
*/


#ifndef BOMBERMAN_ANIMATION_HPP
#define BOMBERMAN_ANIMATION_HPP

#include "../image/Image.hpp"
#include "../../../raylib-cpp/src/rectangle/Rectangle.hpp"

namespace Bomberman {
    class Animation : public Image {
    public:
        explicit Animation(std::string const &path, raylib::Vector2 const &pos_, unsigned int const nbRows_, unsigned int const nbColumns_,
            raylib::Vector2 const &oui_ = raylib::Vector2(0, 0), raylib::Color const &color = raylib::Color::White()) noexcept;
        void drawRect() noexcept;
        void nextFrame() noexcept;

        raylib::Rectangle rect;
        unsigned int nbRows, nbColumns;
        unsigned int currentFrame;
        int framesCounter;
        raylib::Vector2 oui;
    };
}
#endif //BOMBERMAN_ANIMATION_HPP
