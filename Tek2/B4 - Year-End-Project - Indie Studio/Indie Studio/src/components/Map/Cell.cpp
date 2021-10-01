/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Cell
*/

#include "Cell.hpp"

Cell::Cell(int x, int y, char type, raylib::Vector3 vector) : _x(x), _y(y), _floorType(type), isVisited(false),
                                                              _vector(vector)
{
}

int Cell::getX() const {return _x;}

int Cell::getY() const {return _y;}

char Cell::getType() const {return _floorType;}

void Cell::setX(const int x) {_x = x;}

void Cell::setY(const int y) {_y = y;}

void Cell::setType(const char type) {_floorType = type;}

bool Cell::getVisited() const {return isVisited;}

void Cell::setVisited(const bool value) {isVisited = value;}

raylib::Vector3 Cell::getVector() {return _vector;}

void Cell::setVectorY(const float vector) { _vector.y = vector; }