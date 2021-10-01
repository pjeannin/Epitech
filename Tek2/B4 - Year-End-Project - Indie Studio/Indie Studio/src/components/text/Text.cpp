/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** bomberman
*/

#include "Text.hpp"

Bomberman::Text::Text(raylib::Vector2 const &pos_, raylib::Font *font_, float const fontSize_, float const spacing_, raylib::Color const &color_) noexcept :
    pos(pos_),  font(font_), fontSize(fontSize_), spacing(spacing_), color(color_)
{}

void Bomberman::Text::draw(std::string const &text) noexcept
{
    raylib::Text::DrawEx(text, *font, pos, fontSize, spacing, color);
}
