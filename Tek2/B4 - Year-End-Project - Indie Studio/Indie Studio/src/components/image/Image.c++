/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** TODO: add description
*/


#include "Image.hpp"

Bomberman::Image::Image() noexcept : val(nullptr), pos(0, 0), rotation(0), scale(0), color(raylib::Color::White())
{}
Bomberman::Image::Image(std::string const &path, raylib::Vector2 const &pos_, float const rotation_, float const scale_, raylib::Color const &color_) noexcept :
    val(new raylib::Texture(path)), pos(pos_), rotation(rotation_), scale(scale_), color(color_)
{}

Bomberman::Image::Image(raylib::Texture const &texture, raylib::Vector2 const &pos_, float const rotation_, float const scale_, raylib::Color const &color_) noexcept :
    val(new raylib::Texture(texture)), pos(pos_), rotation(rotation_), scale(scale_), color(color_)
{}

void Bomberman::Image::draw() const noexcept
{
    val->Draw(pos, rotation, scale, color);
}

void Bomberman::Image::load(raylib::Texture *texture, raylib::Vector2 const &pos_, float const rotation_, float const scale_, raylib::Color const &color_) noexcept
{
    val = texture;
    pos = pos_;
    rotation = rotation_;
    scale = scale_;
    color = color_;
}

void Bomberman::Image::load(std::string const &path, raylib::Vector2 const &pos_, float const rotation_, float const scale_, raylib::Color const &color_) noexcept
{
    if (!val)
        val = new raylib::Texture(path);
    else
        val->Load(path);
    pos = pos_;
    rotation = rotation_;
    scale = scale_;
    color = color_;
}

void Bomberman::Image::draw(raylib::Vector2 const &pos_) const noexcept
{
    val->Draw(pos_, rotation, scale, color);
}
