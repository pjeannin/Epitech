/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by antonyftp
*/

#include "AI.hpp"
#include "../raylib-cpp/src/vector/Vector.hpp"

AI::AI(raylib::Vector3 position, Boat::Team const team, unsigned int id, ModelList3D &models) : _mt(time(nullptr)), _first(true), _direction(static_cast<Direction>(rand() % 4 + 1)), _time(0), _timePoint(std::chrono::steady_clock::now()), Boat(position, team, id, models)
{
    srand(time(nullptr));
}

void AI::updateBomb(std::vector<Cell *> &Cells, Bombs *bombs, int boat)
{
    Bomb *tmp = nullptr;

    switch (_direction) {
        case LEFT:
            if ((Cells[boat]->getY() > 0 && (detectBoat(boat - 13) || detectDestructibleWall(boat - 13)))
            || (Cells[boat]->getX() < 12 && (detectBoat(boat + 1) || detectDestructibleWall(boat + 1)))
            || (Cells[boat]->getX() > 0 && (detectBoat(boat - 1) || detectDestructibleWall(boat - 1)))) {
                tmp = placeBomb(_position);
                if (tmp && currentNumberOfBomb(*bombs) < _bombMax) {
                    bombs->push_back(tmp);
                    _direction = RIGHT;
                    _time = 1500 * tmp->getRange();
                }
            }
            break;
        case RIGHT:
            if ((Cells[boat]->getY() < 12 && (detectBoat(boat + 13) || detectDestructibleWall(boat + 13)))
            || (Cells[boat]->getX() < 12 && (detectBoat(boat + 1) || detectDestructibleWall(boat + 1)))
            || (Cells[boat]->getX() > 0 && (detectBoat(boat - 1) || detectDestructibleWall(boat - 1)))) {
                tmp = placeBomb(_position);
                if (tmp && currentNumberOfBomb(*bombs) < _bombMax) {
                    bombs->push_back(tmp);
                    _direction = LEFT;
                    _time = 1500 * tmp->getRange();
                }
            }
            break;
        case UP:
            if ((Cells[boat]->getX() < 12 && (detectBoat(boat + 1) || detectDestructibleWall(boat + 1)))
            || (Cells[boat]->getY() > 0 && (detectBoat(boat - 13) || detectDestructibleWall(boat - 13)))
            || (Cells[boat]->getY() < 12 && (detectBoat(boat + 13) || detectDestructibleWall(boat + 13)))) {
                tmp = placeBomb(_position);
                if (tmp && currentNumberOfBomb(*bombs) < _bombMax) {
                    bombs->push_back(tmp);
                    _direction = DOWN;
                    _time = 1500 * tmp->getRange();
                }
            }
            break;
        case DOWN:
            if ((Cells[boat]->getX() > 0 && (detectBoat(boat - 1) || detectDestructibleWall(boat - 1)))
            || (Cells[boat]->getY() > 0 && (detectBoat(boat - 13) || detectDestructibleWall(boat - 13)))
            || (Cells[boat]->getY() < 12 && (detectBoat(boat + 13) || detectDestructibleWall(boat + 13)))) {
                tmp = placeBomb(_position);
                if (tmp && currentNumberOfBomb(*bombs) < _bombMax) {
                    bombs->push_back(tmp);
                    _direction = UP;
                    _time = 1500 * tmp->getRange();
                }
            }
            break;
    }
}

std::vector<AI::Direction> *AI::getFreeDirections(std::vector<Cell *> &Cells, int boat)
{
    auto *freeDirections = new std::vector<Direction>;

    if (Cells[boat]->getY() > 0 && Cells[boat - 13]->getType() != 'X' && Cells[boat - 13]->getType() != 'O')
        freeDirections->push_back(LEFT);
    if (Cells[boat]->getY() < 12 && Cells[boat + 13]->getType() != 'X' && Cells[boat + 13]->getType() != 'O')
        freeDirections->push_back(RIGHT);
    if (Cells[boat]->getX() < 12 && Cells[boat + 1]->getType() != 'X' && Cells[boat + 1]->getType() != 'O')
        freeDirections->push_back(UP);
    if (Cells[boat]->getX() > 0 && Cells[boat - 1]->getType() != 'X' && Cells[boat - 1]->getType() != 'O')
        freeDirections->push_back(DOWN);
    return (freeDirections);
}

int AI::getBoat(std::vector<Cell *> &Cells)
{
    char toFind = ' ';

    switch (_id) {
        case 2:
            toFind = 'Q';
            break;
        case 3:
            toFind = 'R';
            break;
        case 4:
            toFind = 'S';
            break;
    }
    for (int i = 0; i < Cells.size(); ++i) {
        if (Cells[i]->getType() == toFind)
            return (i);
    }
    return (0);
}

void AI::updateDirection(std::vector<Cell *> &Cells, std::vector<Direction> *freeDirections, int boat)
{
    _oldCell = raylib::Vector3(roundPosition(_position.x), roundPosition(_position.y), roundPosition(_position.z));
    switch (freeDirections->at(_mt() % freeDirections->size())) {
        case LEFT:
            _direction = LEFT;
            break;
        case RIGHT:
            _direction = RIGHT;
            break;
        case UP:
            _direction = UP;
            break;
        case DOWN:
            _direction = DOWN;
            break;
    }
}

bool AI::detectCrossroad(std::vector<Direction> *freeDirections)
{
    float decimalX = _position.x - roundPosition(_position.x);
    float decimalY = _position.z - roundPosition(_position.z);

    if (freeDirections->size() > 2 && -0.2 <= decimalX && decimalX <= 0.2 && -0.2 <= decimalY && decimalY <= 0.2 &&
    !(raylib::Vector3(roundPosition(_position.x), roundPosition(_position.y), roundPosition(_position.z)) == _oldCell))
        return (true);
    return (false);
}

bool AI::checkDirection(raylib::Vector3 &diff)
{
    switch (_direction) {
        case UP:
            if (diff.x > 0)
                return (true);
            break;
        case DOWN:
            if (diff.x < 0)
                return (true);
            break;
        case LEFT:
            if (diff.z < 0)
                return (true);
            break;
        case RIGHT:
            if (diff.z> 0)
                return (true);
            break;
    }
    return (false);
}

bool AI::dodgeBomb(Bombs &bombs, Map *map)
{
    std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now();
    if (_time > 0) {
        _time -= std::chrono::duration_cast<std::chrono::milliseconds>(tp - _timePoint).count();
        return (false);
    }
    _timePoint = tp;
    for (int j = 0; j < bombs.size(); ++j) {
        bool left = true;
        bool right = true;
        bool up = true;
        bool down = true;

        for (int i = 1; i <= bombs[j]->getRange(); i++) {
            if (up && (int)roundPosition(bombs[j]->getPosition().x) + i <= 12 && map->getGrid()[(roundPosition(bombs[j]->getPosition().x) + i) + (13 * roundPosition(roundPosition(bombs[j]->getPosition().z)))]->getType() == 'X')
                up = false;
            if (down && (int)roundPosition(bombs[j]->getPosition().x) - i >= 0 && map->getGrid()[roundPosition(roundPosition(bombs[j]->getPosition().x) - i) + (13 * roundPosition(roundPosition(bombs[j]->getPosition().z)))]->getType() == 'X')
                down = false;
            if (right && (int)roundPosition(bombs[j]->getPosition().z) + i <= 12 && map->getGrid()[roundPosition(roundPosition(bombs[j]->getPosition().x)) + (13 *(roundPosition(roundPosition(bombs[j]->getPosition().z) +i)))]->getType() =='X')
                right = false;
            if (left && (int)roundPosition(bombs[j]->getPosition().z) - i >= 0 && map->getGrid()[roundPosition(roundPosition(bombs[j]->getPosition().x)) + (13 *(roundPosition(roundPosition(bombs[j]->getPosition().z) -i)))]->getType() =='X')
                left = false;
            if (up && (int)roundPosition(bombs[j]->getPosition().x) + i <= 12 &&
                raylib::Vector3(roundPosition(bombs[j]->getPosition().x + i), roundPosition(bombs[j]->getPosition().y), roundPosition(bombs[j]->getPosition().z)) ==
                raylib::Vector3(roundPosition(_position.x), roundPosition(_position.y), roundPosition(_position.z))) {
                raylib::Vector3 diff(roundPosition(bombs[j]->getPosition().x + i) - (_position.x), roundPosition(bombs[j]->getPosition().y) + (_position.y), roundPosition(bombs[j]->getPosition().z) - (_position.z));
                if (checkDirection(diff))
                    return (true);

            }
            if (down && (int)roundPosition(bombs[j]->getPosition().x) - i >= 0 &&
                raylib::Vector3(roundPosition(bombs[j]->getPosition().x - i), roundPosition(bombs[j]->getPosition().y), roundPosition(bombs[j]->getPosition().z)) ==
                raylib::Vector3(roundPosition(_position.x), roundPosition(_position.y), roundPosition(_position.z))) {
                raylib::Vector3 diff(roundPosition(bombs[j]->getPosition().x - i) - (_position.x), roundPosition(bombs[j]->getPosition().y) + (_position.y), roundPosition(bombs[j]->getPosition().z) - (_position.z));
                if (checkDirection(diff))
                    return (true);
            }

            if (right && (int)roundPosition(bombs[j]->getPosition().z) + i <= 12 &&
                raylib::Vector3(roundPosition(bombs[j]->getPosition().x), roundPosition(bombs[j]->getPosition().y), roundPosition(bombs[j]->getPosition().z + i)) ==
                raylib::Vector3(roundPosition(_position.x), roundPosition(_position.y), roundPosition(_position.z))) {
                raylib::Vector3 diff(roundPosition(bombs[j]->getPosition().x) - (_position.x), roundPosition(bombs[j]->getPosition().y) + (_position.y), roundPosition(bombs[j]->getPosition().z + 1) - (_position.z));
                if (checkDirection(diff))
                    return (true);
            }

            if (left && (int)roundPosition(bombs[j]->getPosition().z) - i >= 0 &&
                raylib::Vector3(roundPosition(bombs[j]->getPosition().x), roundPosition(bombs[j]->getPosition().y), roundPosition(bombs[j]->getPosition().z - i)) ==
                raylib::Vector3(roundPosition(_position.x), roundPosition(_position.y), roundPosition(_position.z))) {
                raylib::Vector3 diff(roundPosition(bombs[j]->getPosition().x) - (_position.x), roundPosition(bombs[j]->getPosition().y) + (_position.y), roundPosition(bombs[j]->getPosition().z - 1) - (_position.z));
                if (checkDirection(diff))
                return (true);
            }
        }
    }
    return (false);
}

void AI::reverseDirection(Bombs &bombs, Map *map, std::vector<APowerUp *>&bonus)
{
    switch (_direction) {
        case LEFT:
            _direction = RIGHT;
            break;
        case RIGHT:
            _direction = LEFT;
            break;
        case UP:
            _direction = DOWN;
            break;
        case DOWN:
            _direction = UP;
            break;
    }
    move(_direction, map, bonus, bombs);

}

void AI::update(Bombs &bombs, Map *map, std::vector<APowerUp *>&bonus)
{
    std::vector<Cell *> Cells = map->getGrid();
    int boat = getBoat(Cells);
    auto freeDirections = getFreeDirections(Cells, boat);
    raylib::Vector3 oldPosition = _position;

    if (!_isAlive)
        return;
    if (_first) {
        updateDirection(Cells, freeDirections, boat);
        _first = false;
    }
    else if (detectCrossroad(freeDirections))
        updateDirection(Cells, freeDirections, boat);
    updateBomb(Cells, &bombs, boat);
    move(this->_direction, map, bonus, bombs);
    if (_position == oldPosition) {
        updateDirection(Cells, freeDirections, boat);
        move(this->_direction, map, bonus, bombs);
    }
    if (dodgeBomb(bombs, map))
        reverseDirection(bombs, map, bonus);
}