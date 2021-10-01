/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** bomberman
*/

#include "Animation.hpp"

#include <iostream>

Bomberman::Animation::Animation(std::string const &path, raylib::Vector2 const &pos_, unsigned int const nbRows_, unsigned int const nbColumns_, raylib::Vector2 const &oui_, raylib::Color const &color_) noexcept :
    Bomberman::Image(path, pos_, 0, 0, color_), rect(0, 0, val->width / nbColumns_, val->height / nbRows_),
    nbRows(nbRows_), nbColumns(nbColumns_), currentFrame(0), framesCounter(0), oui(oui_)
{
    if (!oui.x && !oui.y) {
        oui.x = nbRows;
        oui.y = nbColumns;
    }
}

void Bomberman::Animation::drawRect() noexcept
{
    val->Draw(rect, pos, color);
}

void Bomberman::Animation::nextFrame() noexcept
{
    framesCounter = 0;
    if (++currentFrame > nbColumns)
        rect.x = 0;
    rect.x = (float)currentFrame * (float)val->width / oui.y;
    rect.y += (float)val->height / oui.x;
}
