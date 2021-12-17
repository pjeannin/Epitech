/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin
** File description:
** PacmanPlayer
*/

#include "PacmanPlayer.hpp"

PacmanPlayer::PacmanPlayer() : _pos(Position(0, 0)), _isSuper(false)
{
}

PacmanPlayer::~PacmanPlayer()
{
}

const Position &PacmanPlayer::getPosition() const { return _pos; }

void PacmanPlayer::setPosition(const Position &pos) { _pos = pos; }

bool PacmanPlayer::isSuper() const { return _isSuper; }

void PacmanPlayer::setSuper(bool isSuper) { _isSuper = isSuper; }

void PacmanPlayer::move(Position movement)
{
    _pos.x += movement.x;
    _pos.y += movement.y;
}

void PacmanPlayer::addSuperTime(int elpasedTime)
{
    _superTime += elpasedTime;
    if (_superTime > 10000) {
        _superTime = 0;
        _isSuper = false;
    }
}