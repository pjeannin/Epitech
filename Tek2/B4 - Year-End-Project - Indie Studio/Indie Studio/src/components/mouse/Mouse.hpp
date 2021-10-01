/*
** EPITECH PROJECT, 2021
** Mouse
** File description:
** Mouse
*/

#ifndef __B_MOUSE__
#define __B_MOUSE__

#include "../../../raylib-cpp/src/mouse/Mouse.hpp"
#include "../../../raylib-cpp/src/texture/Texture.hpp"

class Mouse : public raylib::Mouse {
public:
    explicit Mouse() noexcept;
    void draw() noexcept;
private:
    raylib::Texture cursor;
    // raylib::Vector2 mousePos;
};

#endif /* __B_MOUSE__ */
