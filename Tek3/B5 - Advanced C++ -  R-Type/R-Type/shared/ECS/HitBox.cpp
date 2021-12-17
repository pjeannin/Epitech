/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "HitBox.hpp"

#include <utility>
#include <vector>

RType::ECS::HitBox::HitBox(unsigned int const width, unsigned int const height, std::pair<int, int> offset) noexcept : _width(width), _height(height), _offset(std::move(offset)) {}

unsigned int RType::ECS::HitBox::getWidth() const noexcept { return _width; }

unsigned int RType::ECS::HitBox::getHeight() const noexcept { return _height; }

void RType::ECS::HitBox::setWidth(unsigned int const width) noexcept { _width = width; }

void RType::ECS::HitBox::setHeight(unsigned int const height) noexcept { _height = height; }

RType::ECS::HitBox::HitBox(const RType::ECS::HitBox &other) noexcept : _width(other.getWidth()), _height(other.getHeight()), _offset(other._offset) {}

std::pair<int, int> RType::ECS::HitBox::getOffset() const noexcept { return _offset; }

bool RType::ECS::HitBox::isColliding(const RType::ECS::Position &position, const std::pair<int, int> point) const noexcept
{
    if (position.getXPos() + _offset.first < point.first && position.getXPos() + _offset.first + (int)_width > point.first && position.getYPos() + _offset.second < point.second && position.getYPos() + _offset.second + (int)_height > point.second)
        return true;
    return false;
}

bool RType::ECS::HitBox::isColliding(const RType::ECS::Position &position, const RType::ECS::HitBox &hitbox, const RType::ECS::Position &otherPosition) const noexcept
{
    std::vector<int> points{position.getXPos() + _offset.first, position.getXPos() + (int)_width + _offset.first, position.getYPos() + _offset.second, position.getYPos() + (int)_height + _offset.second};
    std::vector<std::pair<int, int>> otherPoints{{otherPosition.getXPos() + hitbox._offset.first, otherPosition.getYPos() + hitbox._offset.second},
                                                 {otherPosition.getXPos() + (int)hitbox._width + hitbox._offset.first, otherPosition.getYPos() + hitbox._offset.second},
                                                 {otherPosition.getXPos() + hitbox._offset.first, otherPosition.getYPos() + (int)hitbox._height + hitbox._offset.second},
                                                 {otherPosition.getXPos() + (int)hitbox._width + hitbox._offset.first, otherPosition.getYPos() + (int)hitbox._height + hitbox._offset.second}};
    for (std::pair<int, int> otherPoint : otherPoints)
        if (points[0] <= otherPoint.first && points[1] >= otherPoint.first && points[2] <= otherPoint.second && points[3] >= otherPoint.second)
            return true;
    return false;
}


