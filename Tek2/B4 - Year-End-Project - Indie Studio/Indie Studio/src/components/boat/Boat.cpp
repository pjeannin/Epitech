/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by antonyftp
*/

#include "Boat.hpp"
#include <iostream>

Boat::Boat(raylib::Vector3 const &position, Boat::Team const team, unsigned int id, ModelList3D &models) : _position(position),
_team(team), _speed(1.0f), _bombRange(1), _id(id), _bombMax(1), _isAlive(true), _hp(1), _boat(models[ModelList::BoatBlue]),
_powerUpB("resources/images/powerUpB.png"), _powerUpW("resources/images/powerUpW.png"),
_powerUpF("resources/images/powerUpF.png"), _powerUpS("resources/images/powerUpS.png"), _models(models),
_fxSelect("resources/sounds/select.ogg"),_direction(UP),
_zAnim(0),
_anim(true),
_tmp(0, 0, 0),
_time1(std::chrono::steady_clock::now())
{
    _idMap.insert(std::map<unsigned int, char>::value_type(1, 'P'));
    _idMap.insert(std::map<unsigned int, char>::value_type(2, 'Q'));
    _idMap.insert(std::map<unsigned int, char>::value_type(3, 'R'));
    _idMap.insert(std::map<unsigned int, char>::value_type(4, 'S'));
}

void Boat::kill() { _isAlive = false; }

Bomb *Boat::placeBomb(raylib::Vector3 const &position)
{
    return (new Bomb(raylib::Vector3(roundPosition(position.x), roundPosition(position.y), roundPosition(position.z)), _bombRange, _id, _models));
}

void Boat::giveBonus(APowerUp *powerUp)
{
    if (powerUp->getType() == IPowerUp::HP_UP)
        hpUp();
    if (powerUp->getType() == IPowerUp::FIRE_UP)
        fireUp();
    if (powerUp->getType() == IPowerUp::BOMB_UP)
        bombUp();
    if (powerUp->getType() == IPowerUp::SPEED_UP)
        speedUp();
}

void Boat::drawPowerUpS()
{
    switch (_id) {
        case 1: {
            _powerUpS.pos = raylib::Vector2(18, 748);
            _powerUpS.draw();
            DrawText(std::to_string((int) ((_speed - 1.0) / 0.3) + 1).c_str(),
                     38, 768, 12, PINK);
            break;
        }
        case 2: {
            _powerUpS.pos = raylib::Vector2(1879, 748);
            _powerUpS.draw();
            DrawText(std::to_string((int) ((_speed - 1.0) / 0.3) + 1).c_str(),
                     1899, 768, 12, PINK);
            break;
        }
        case 3: {
            _powerUpS.pos = raylib::Vector2(1837, 338);
            _powerUpS.draw();
            DrawText(std::to_string((int) ((_speed - 1.0) / 0.3) + 1).c_str(),
                     1857, 358, 12, PINK);
            break;
        }
        case 4: {
            _powerUpS.pos = raylib::Vector2(53, 337);
            _powerUpS.draw();
            DrawText(std::to_string(
                    (int) ((_speed - 1.0) / 0.3) + 1).c_str(), 73, 358, 12,
                     PINK);
            break;
            }
    }
}

void Boat::drawPowerUpB()
{
    switch (_id) {
        case 1: {
            _powerUpB.pos = raylib::Vector2(112, 749);
            _powerUpB.draw();
            DrawText(std::to_string(_bombMax - 1).c_str(), 132, 769, 12, PINK);
            break;
        }
        case 2: {
            _powerUpB.pos = raylib::Vector2(1784, 748);
            _powerUpB.draw();
            DrawText(std::to_string(_bombMax - 1).c_str(), 1804, 768, 12, PINK);
            break;
        }
        case 3: {
            _powerUpB.pos = raylib::Vector2(1744, 337);
            _powerUpB.draw();
            DrawText(std::to_string(_bombMax - 1).c_str(), 1764, 357, 12, PINK);
            break;
        }
        case 4: {
            _powerUpB.pos = raylib::Vector2(148, 337);
            _powerUpB.draw();
            DrawText(std::to_string(_bombMax - 1).c_str(), 168, 357, 12, PINK);
            break;
        }
    }
}

void Boat::drawPowerUpW()
{

}

void Boat::drawPowerUpF()
{
    switch (_id) {
        case 1: {
            _powerUpF.pos = raylib::Vector2(159, 748);
            _powerUpF.draw();
            DrawText(std::to_string(_bombRange - 1).c_str(), 179, 768, 12,
                     PINK);
            break;
        }
        case 2: {
            _powerUpF.pos = raylib::Vector2(1737, 748);
            _powerUpF.draw();
            DrawText(std::to_string(_bombRange - 1).c_str(), 1757, 768, 12,
                     PINK);
            break;
        }
        case 3: {
            _powerUpF.pos = raylib::Vector2(1697, 339);
            _powerUpF.draw();
            DrawText(std::to_string(_bombRange - 1).c_str(), 1717, 359, 12,
                     PINK);
            break;
        }
        case 4: {
            _powerUpF.pos = raylib::Vector2(194, 339);
            _powerUpF.draw();
            DrawText(std::to_string(_bombRange - 1).c_str(), 214, 359, 12,
                     PINK);
            break;
        }
    }
}

void Boat::checkCollideBonus(std::vector<APowerUp *>&bonus)
{
    for (int i = 0; i < bonus.size(); i++) {
        if (bonus.at(i)->getPosition() == raylib::Vector3(roundPosition(_position.x), roundPosition(_position.y), roundPosition(_position.z))) {
            giveBonus(bonus.at(i));
            bonus.erase(bonus.begin() + i);
            _fxSelect.Play();
        }
    }
}

void Boat::move(Boat::Direction direction, Map *map, std::vector<APowerUp *>&bonus, Bombs &bombs)
{
    raylib::Vector3 former(_position.x, _position.y, _position.z);

    switch (direction) {
        case LEFT:
            _direction = LEFT;
            if (notCollide(raylib::Vector3(_position.x, _position.y, _position.z - 0.05f * (float)_speed), map, bombs))
                _position.z -= 0.05f * (float)_speed;
            break;
        case RIGHT:
            _direction = RIGHT;
            if (notCollide(raylib::Vector3(_position.x, _position.y, _position.z + 0.05f * (float)_speed), map, bombs))
                _position.z += 0.05f * (float)_speed;
            break;
        case UP:
            _direction = UP;
            if (notCollide(raylib::Vector3(_position.x + 0.05f * (float)_speed, _position.y, _position.z), map, bombs))
                _position.x += 0.05f * (float)_speed;
            break;
        case DOWN:
            _direction = DOWN;
            if (notCollide(raylib::Vector3(_position.x - 0.05f * (float)_speed, _position.y, _position.z), map, bombs))
                _position.x -= 0.05f * (float)_speed;
            break;
    }
    raylib::Vector3 newer(_position.x, _position.y, _position.z);
        checkCollideBonus(bonus);
    if (former == newer)
        return;
    else {
        map->getGrid().at(roundPosition(former.x) + (13 * roundPosition(former.z)))->setType(' ');
        map->getGrid().at(roundPosition(_position.x) + (13 * roundPosition(_position.z)))->setType(_idMap.at(_id));
    }
}

void Boat::anim()
{
    std::chrono::steady_clock::time_point _time2 = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(_time2 - _time1).count() > 100) {
        if (_zAnim <= -0.05)
            _anim = false;
        if (_zAnim >= 0)
            _anim = true;
        if (_anim)
            _zAnim -= 0.007;
        if (!_anim)
            _zAnim += 0.007;
        _time1 = _time2;
    }
    _tmp.y = _zAnim;
}

void Boat::draw()
{
    raylib::Color color;

    switch (_team) {
        case BLUE_TEAM:
            color = raylib::Color::Blue();
            break;
        case RED_TEAM:
            color = raylib::Color::Red();
            break;
        case GREEN_TEAM:
            color = raylib::Color::Green();
            break;
        case YELLOW_TEAM:
            color = raylib::Color::Yellow();
            break;
    }
    if (!_isAlive)
        _position.y -= 0.01f;
    _tmp = _position;
    if (_isAlive)
        anim();
    switch (_direction) {
        case UP:
            _boat.first->draw(_tmp, raylib::Vector3 {0.0f, 1.0f, 0.0f }, 0.0f + _position.y * 500, raylib::Vector3 { 1.0f, 1.0f, 1.0f }, raylib::Color::White());
            break;
        case RIGHT:
            _boat.first->draw(_tmp, raylib::Vector3 { 0.0f, 1.0f, 0.0f }, -90.0f + _position.y * 500, raylib::Vector3 { 1.0f, 1.0f, 1.0f }, raylib::Color::White());
            break;
        case LEFT:
            _boat.first->draw(_tmp, raylib::Vector3 { 0.0f, 1.0f, 0.0f }, 90.0f + _position.y * 500, raylib::Vector3 { 1.0f, 1.0f, 1.0f }, raylib::Color::White());
            break;
        case DOWN:
            _boat.first->draw(_tmp, raylib::Vector3 { 0.0f, 1.0f, 0.0f }, 180.0f + _position.y * 500, raylib::Vector3 { 1.0f, 1.0f, 1.0f }, raylib::Color::White());
            break;
    }
}

int Boat::getBombMax() const { return _bombMax; }

void Boat::setBombMax(const int bomb) { _bombMax = bomb;}

int Boat::getBombRange() const { return _bombRange; }

void Boat::setBombRange(const int bomb) { _bombRange = bomb;}

float Boat::getSpeed() const { return _speed; }

void Boat::setSpeed(const float speed) { _speed = speed;}

bool Boat::isIsAlive() const { return _isAlive; }

void Boat::setIsAlive(bool const isAlive) { _isAlive = isAlive; }

int Boat::getHP() const {return _hp;}

void Boat::setHP(const int hp) {_hp = hp;}

const raylib::Vector3 &Boat::getPosition() const { return _position; }

Boat::Team Boat::getTeam() const { return _team; }

void Boat::bombUp() { ++_bombMax; }

void Boat::speedUp() { _speed += 0.3f; }

void Boat::fireUp() { ++_bombRange; }

void Boat::hpUp() { ++_hp;}

bool Boat::notCollide(raylib::Vector3 position, Map *map, Bombs &bombs) {
    raylib::Rectangle player(position.x - 0.3, position.z - 0.3, 0.6, 0.6);

    for (int i = 0; i < map->getGrid().size(); ++i)
        if ((map->getGrid()[i]->getType() == 'X' || map->getGrid()[i]->getType() == 'O')
        && player.CheckCollision(raylib::Rectangle(map->getGrid()[i]->getX() - 0.5, map->getGrid()[i]->getY() - 0.5, 1, 1)))
            return (false);
    for (int i = -1; i < 14; ++i)
        for (int j = -1; j < 14; ++j)
            if ((i == -1 || j == -1 || i == 13 || j == 13) && player.CheckCollision(raylib::Rectangle(i - 0.5, j - 0.5, 1, 1)))
                return (false);
    for (auto & bomb : bombs) {
        if ((roundPosition(_position.x) != roundPosition(bomb->getPosition().x)
        || roundPosition(_position.z) != roundPosition(bomb->getPosition().z))
        && player.CheckCollision(raylib::Rectangle(bomb->getPosition().x - 0.25, bomb->getPosition().z - 0.25, 0.5, 0.5)))
            return (false);
    }

    return (true);
}

int Boat::currentNumberOfBomb(Bombs &bombs) const
{
    int nb = 0;

    for (auto & bomb : bombs)
        if (bomb->getOwnerId() == _id)
            ++nb;
    return (nb);
}

unsigned int Boat::getId() const { return _id; }

static void removeBoat(Bomb &bomb, std::vector<Boat *> &boats, Cell *cell)
{
    switch (cell->getType()) {
        case 'P':
            for (auto & boat : boats) {
                if (boat->getId() == 1) {
                    boat->setHP(boat->getHP() - 1);
                    if (boat->getHP() == 0) {
                        boat->kill();
                        cell->setType(' ');
                    }
                }
            }
            break;
        case 'Q':
            for (auto & boat : boats) {
                if (boat->getId() == 2) {
                    boat->setHP(boat->getHP() - 1);
                    if (boat->getHP() <= 0) {
                        boat->kill();
                        cell->setType(' ');
                    }
                }
            }
            break;
        case 'R':
            for (auto & boat : boats) {
                if (boat->getId() == 3) {
                    boat->setHP(boat->getHP() - 1);
                    if (boat->getHP() <= 0) {
                        boat->kill();
                        cell->setType(' ');
                    }
                }
            }
            break;
        case 'S':
            for (auto & boat : boats) {
                if (boat->getId() == 4) {
                    boat->setHP(boat->getHP() - 1);
                    if (boat->getHP() <= 0) {
                        boat->kill();
                        cell->setType(' ');
                    }
                }
            }
            break;
        default:
            break;
    }
}

void killBoats(std::vector<Boat *> &boats, Bomb &bomb, Map &map)
{
    if (bomb.getDone())
        return;
    bomb.setDone(true);
    removeBoat(bomb, boats, map.getGrid()[((int)bomb.getPosition().x) + (13 * (int)bomb.getPosition().z)]);
    for (int i = 1; i <= bomb.getRange(); ++i) {
        if (((int)bomb.getPosition().x + i <= 12))
            removeBoat(bomb, boats, map.getGrid()[((int)bomb.getPosition().x + i) + (13 * (int)bomb.getPosition().z)]);
        if ((int)bomb.getPosition().x - i >= 0)
            removeBoat(bomb, boats, map.getGrid()[((int)bomb.getPosition().x - i) + (13 * (int)bomb.getPosition().z)]);
        if ((int)bomb.getPosition().z + i <= 12)
            removeBoat(bomb, boats, map.getGrid()[(int)bomb.getPosition().x + (13 * ((int)bomb.getPosition().z + i))]);
        if ((int)bomb.getPosition().z - i >= 0)
            removeBoat(bomb, boats, map.getGrid()[(int)bomb.getPosition().x + (13 * ((int)bomb.getPosition().z - i))]);
    }
}
