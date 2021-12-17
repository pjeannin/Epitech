/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "Score.hpp"

RType::ECS::Score::Score(unsigned int const startingScore) noexcept : _score(startingScore) {}

unsigned int RType::ECS::Score::getScore() const noexcept { return _score; }

void RType::ECS::Score::setScore(unsigned int const score) noexcept { _score = score; }

void RType::ECS::Score::addToScore(unsigned int const toAdd) noexcept { _score += toAdd; }

RType::ECS::Score::Score(const RType::ECS::Score &other) noexcept : _score(other.getScore()) { }
