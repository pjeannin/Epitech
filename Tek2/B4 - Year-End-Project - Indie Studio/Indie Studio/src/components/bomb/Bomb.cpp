/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by antonyftp
*/

#include "Bomb.hpp"

Bomb::Bomb(const raylib::Vector3 &position, int const Range, unsigned int id, ModelList3D &models) : _position(position),
_range(Range),  _remainingTime(3000), _timePoint(std::chrono::steady_clock::now()), exploded(false),
_id(id), _models(models), _barrel(models[ModelList::Barrel]), _explosion(models[ModelList::Explosion]), _explosionScale(0),
_fxExplosion("resources/sounds/explosion.ogg"), _done(false)
{}

bool Bomb::getExploded() const {return exploded;}
void Bomb::setExploded(const bool value)
{
    exploded = value;
    _fxExplosion.SetVolume(0.5);
    _fxExplosion.Play();
}

long long Bomb::getRemainingTime() const {return _remainingTime;}

void Bomb::updateRemainingTime(Map *map, std::vector<APowerUp *> &bonus)
{
    std::chrono::steady_clock::time_point newTimePoint = std::chrono::steady_clock::now();

    _remainingTime -= std::chrono::duration_cast<std::chrono::milliseconds>(newTimePoint - _timePoint).count();
    _timePoint = newTimePoint;
    if (_remainingTime <= 0)
        explodes(map, bonus);
}

static void addBonus(Cell *cell, std::vector<APowerUp *> &bonus, ModelList3D &_models)
{
    std::mt19937 mt(time(NULL));
    auto rand = mt() % 2;

    if (rand == 0) {
        switch (mt() % 4) {
            case 0:
                cell->setType('H');
                bonus.push_back(new HPUp(cell->getVector(), _models[ModelList::HPUp]));
                break;
            case 1:
                cell->setType('F');
                bonus.push_back(new FireUp(cell->getVector(), _models[ModelList::FireUp]));
                break;
            case 2:
                cell->setType('S');
                bonus.push_back(new SpeedUp(cell->getVector(), _models[ModelList::SpeedUp]));
                break;
            case 3:
                cell->setType('B');
                bonus.push_back(new BombUp(cell->getVector(), _models[ModelList::BombUp]));
                break;
        }
    }
}

void Bomb::explodes(Map *map, std::vector<APowerUp *> &bonus)
{
    bool left = true;
    bool right = true;
    bool up = true;
    bool down = true;

    for (int i = 1; i <= _range; i++) {
        if (up && (int)_position.x + i <= 12 && map->getGrid()[(roundPosition(_position.x) + i) + (13 * roundPosition(_position.z))]->getType() == 'X')
            up = false;
        if (down && (int)_position.x - i >= 0 && map->getGrid()[(roundPosition(_position.x) - i) + (13 * roundPosition(_position.z))]->getType() == 'X')
            down = false;
        if (right && (int)_position.z + i <= 12 && map->getGrid()[roundPosition(_position.x) + (13 * (roundPosition(_position.z) + i))]->getType() == 'X')
            right = false;
        if (left && (int)_position.z - i >= 0 && map->getGrid()[roundPosition(_position.x) + (13 * (roundPosition(_position.z) - i))]->getType() == 'X')
            left = false;

        if (up && (int)_position.x + i <= 12 && map->getGrid()[(roundPosition(_position.x) + i) + (13 * roundPosition(_position.z))]->getType() == 'O') {
            map->getGrid()[((int)_position.x + i) + (13 * (int)_position.z)]->setType(' ');
            addBonus(map->getGrid()[((int)_position.x + i) + (13 * (int)_position.z)], bonus, _models);
            _explosionAnim.emplace_back(roundPosition(_position.x) + i, 0, roundPosition(_position.z));
        }
        if (down && (int)_position.x - i >= 0 && map->getGrid()[(roundPosition(_position.x) - i) + (13 * roundPosition(_position.z))]->getType() == 'O') {
            map->getGrid()[(int)(_position.x - i) + (13 * (int)_position.z)]->setType(' ');
            addBonus(map->getGrid()[(int)(_position.x - i) + (13 * (int)_position.z)], bonus, _models);
            _explosionAnim.emplace_back(roundPosition(_position.x) - i, 0, roundPosition(_position.z));
        }

        if (right && (int)_position.z + i <= 12 && map->getGrid()[roundPosition(_position.x) + (13 * (roundPosition(_position.z) + i))]->getType() == 'O') {
            map->getGrid()[(int)_position.x + (13 * ((int)_position.z + i))]->setType(' ');
            addBonus(map->getGrid()[(int)_position.x + (13 * ((int)_position.z + i))], bonus, _models);
            _explosionAnim.emplace_back(roundPosition(_position.x), 0, roundPosition(_position.z) + i);
        }
        if (left && (int)_position.z - i >= 0 && map->getGrid()[roundPosition(_position.x) + (13 * (roundPosition(_position.z) - i))]->getType() == 'O') {
            map->getGrid()[(int)_position.x + (13 * ((int)_position.z - i))]->setType(' ');
            addBonus(map->getGrid()[(int)_position.x + (13 * ((int)_position.z - i))], bonus, _models);
            _explosionAnim.emplace_back(roundPosition(_position.x), 0, roundPosition(_position.z) - i);
        }
        if (up && (int)_position.x + i <= 12 && map->getGrid()[(roundPosition(_position.x) + i) + (13 * roundPosition(_position.z))]->getType() == ' ')
            _explosionAnim.emplace_back(roundPosition(_position.x) + i, 0, roundPosition(_position.z));
        if (down && (int)_position.x - i >= 0 && map->getGrid()[(roundPosition(_position.x) - i) + (13 * roundPosition(_position.z))]->getType() == ' ')
            _explosionAnim.emplace_back(roundPosition(_position.x) - i, 0, roundPosition(_position.z));
        if (right && (int)_position.z + i <= 12 && map->getGrid()[roundPosition(_position.x) + (13 * (roundPosition(_position.z) + i))]->getType() == ' ')
            _explosionAnim.emplace_back(roundPosition(_position.x), 0, roundPosition(_position.z) + i);
        if (left && (int)_position.z - i >= 0 && map->getGrid()[roundPosition(_position.x) + (13 * (roundPosition(_position.z) - i))]->getType() == ' ')
            _explosionAnim.emplace_back(roundPosition(_position.x), 0, roundPosition(_position.z) - i);
    }
    setExploded(true);
}

void Bomb::draw(Map *map)
{
    std::vector<Cell *> Cells = map->getGrid();
    Cell *vector_index;

    if (!exploded)
        _barrel.first->draw(_position, 1.0f, raylib::Color::White());
    else {
        _explosionScale += 0.08;
        for (auto i : _explosionAnim)
            _explosion.first->draw(i, _explosionScale, raylib::Color::White());
        _explosion.first->draw(_position, _explosionScale, raylib::Color::White());
    }
}

const raylib::Vector3 &Bomb::getPosition() const { return _position; }

int Bomb::getRange() const { return _range; }

float Bomb::getScale() const { return _explosionScale; }

unsigned int Bomb::getOwnerId() const { return _id; }

bool Bomb::getDone() const { return _done; }

void Bomb::setDone(bool done) { _done = done; }

