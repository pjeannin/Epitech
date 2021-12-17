/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include <iostream>
#include "SfmlText.hpp"

RType::ECS::SfmlText::SfmlText(std::shared_ptr<sf::RenderWindow> window, const std::string &text, const sf::Font &font, unsigned int size,
                               const sf::Color &color) noexcept : AText(text, size),  _window(std::move(window)), _color(color), _font(font), _size(size), _drawableText(text, font, size) { }

RType::ECS::SfmlText::SfmlText(const RType::ECS::SfmlText &other) noexcept : AText(other), _window(std::move(other._window)), _color(other._color), _font(other._font), _size(other._size), _drawableText(other._drawableText) { }

void RType::ECS::SfmlText::draw(const RType::ECS::Position &position) noexcept {
    _drawableText.setPosition((float)position.getXPos(), (float)position.getYPos());
    _drawableText.setFillColor(_color);
    _window->draw(_drawableText);
}

void RType::ECS::SfmlText::setText(const std::string &newText) noexcept {
    AText::setText(newText);
    _drawableText.setString(newText);
}

