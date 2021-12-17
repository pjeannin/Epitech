/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SfmlDrawable.hpp"
#include <utility>
#include <iostream>

RType::ECS::SfmlDrawable::SfmlDrawable(std::shared_ptr<sf::RenderWindow> window, std::string drawablePath, std::pair<unsigned int, unsigned int> spriteSize, std::pair<unsigned int, unsigned int> ressourceSize, std::pair<unsigned int, unsigned int> offset, std::pair<float, float> scale, float rotation) noexcept : ADrawables(std::move(drawablePath), std::move(spriteSize), std::move(ressourceSize), std::move(offset), std::move(scale), std::move(rotation)), _window(std::move(window)) {
    _texture.loadFromFile(_drawablePath);
    _sprite.setTexture(_texture);
    _sprite.setScale(_scale.first, _scale.second);
    _sprite.setRotation(_rotation);
    _sprite.setTextureRect(sf::IntRect(_offset.first, _offset.second, _spriteSize.first, _spriteSize.second));
}

void RType::ECS::SfmlDrawable::draw(const Position &position) noexcept {
    _sprite.setPosition(position.getXPos(), position.getYPos());
    _window->draw(_sprite);
}

RType::ECS::SfmlDrawable::SfmlDrawable(const RType::ECS::SfmlDrawable &other) noexcept : ADrawables(other), _window(other._window) {
    _texture.loadFromFile(_drawablePath);
    _sprite.setTexture(_texture);
    _sprite.setScale(_scale.first, _scale.second);
    _sprite.setRotation(_rotation);
    _sprite.setTextureRect(sf::IntRect(_offset.first, _offset.second, _spriteSize.first, _spriteSize.second));
}

void RType::ECS::SfmlDrawable::moveSprite() noexcept {
    if (_offset.first + _spriteSize.first >= _ressourceSize.first) {
        _offset.first = 0;
        if (_offset.second + _spriteSize.second >= _ressourceSize.second) {
            _offset.second = 0;
        } else {
            _offset.second += _spriteSize.second;
        }
    } else {
        _offset.first += _spriteSize.first;
    }
    _sprite.setTextureRect(sf::IntRect(_offset.first, _offset.second, _spriteSize.first, _spriteSize.second));
}
