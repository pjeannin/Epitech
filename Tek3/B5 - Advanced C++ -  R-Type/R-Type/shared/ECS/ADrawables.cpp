/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "ADrawables.hpp"

#include <utility>

RType::ECS::ADrawables::ADrawables(std::string drawablePath, std::pair<unsigned int, unsigned int> spriteSize, std::pair<unsigned int, unsigned int> ressourceSize, std::pair<unsigned int, unsigned int> offset, std::pair<float, float> scale, float rotation) noexcept : _drawablePath(std::move(drawablePath)), _offset(std::move(offset)), _spriteSize(std::move(spriteSize)), _scale(std::move(scale)), _ressourceSize(std::move(ressourceSize)), _rotation(std::move(rotation)) { }

const std::string &RType::ECS::ADrawables::getDrawablePath() const noexcept { return _drawablePath; }

const std::pair<unsigned int, unsigned int> &RType::ECS::ADrawables::getOffset() const noexcept { return _offset; }

const std::pair<unsigned int, unsigned int> &RType::ECS::ADrawables::getSpriteSize() const noexcept { return _spriteSize; }

void RType::ECS::ADrawables::setOffset(std::pair<unsigned int, unsigned int> const &offset) noexcept { _offset = offset; }

RType::ECS::ADrawables::ADrawables(const RType::ECS::ADrawables &other) noexcept : _drawablePath(other.getDrawablePath()), _offset(other.getOffset()), _spriteSize(other.getSpriteSize()), _scale(other.getScale()), _ressourceSize(other._ressourceSize), _rotation(other._rotation) { }

const std::pair<float, float> &RType::ECS::ADrawables::getScale() const noexcept { return _scale; }
