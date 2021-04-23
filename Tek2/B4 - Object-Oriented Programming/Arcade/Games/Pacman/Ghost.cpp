/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin
** File description:
** Pacman
*/

#include "Ghost.hpp"

Ghost::Ghost() : _elapsedTime(0), _direction(Direction::unknown), _color(Color::Black()), _pos(Position(0, 0)), _basePos(Position(0, 0)), _isAlive(true), _canGoOut(false)
{
}

Ghost::~Ghost()
{
}

const Position &Ghost::getPosition() const { return _pos; }

void Ghost::setPosition(const Position &pos) { _pos = pos; }

void Ghost::setBasePosition(const Position &pos) { _basePos = pos; }

bool Ghost::isAlive() const { return _isAlive; }

void Ghost::setAlive(bool isAlive) { _isAlive = isAlive; }

Color Ghost::getColor() const { return _color; }

void Ghost::setColor(Color color) { _color = color; }

void Ghost::move(Position movement)
{
    _pos.x += movement.x;
    _pos.y += movement.y;
}

int Ghost::getElapsedTime() const { return _elapsedTime; }

void Ghost::setElapsedTime(int elapsedTime) { _elapsedTime = elapsedTime; }

Ghost::Direction Ghost::getDirection() const { return _direction; }

void Ghost::setDirection(Ghost::Direction direction) { _direction = direction; }

void Ghost::reset() { _pos = _basePos; }