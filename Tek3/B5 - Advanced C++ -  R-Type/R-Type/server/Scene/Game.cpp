/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** TODO: add description
*/

#include "Game.hpp"
#include <iostream>

RType::Server::Game::Game(RType::Server::Server *) noexcept
{

}

void RType::Server::Game::update() noexcept
{
    checkCollide();
    checkDeath();
    for (auto it = _gameObjects.begin() ; it != _gameObjects.end(); ++it)
        if (dynamic_cast<RType::ECS::State *>(it->get())->getState())
            _gameObjects.erase(it);
}

void RType::Server::Game::checkDeath() noexcept
{
    for (auto &gameObject : _gameObjects) {
        auto tmp = dynamic_cast<RType::ECS::Health *>(gameObject.get());
        if (tmp != nullptr && tmp->getHealth() <= 0)
            dynamic_cast<RType::ECS::State *>(gameObject.get())->setState(true);
    }
}

void RType::Server::Game::removeCollide(int i, int j) noexcept
{
    for (int k = 0; k != (int)_collideA.size(); ++k)
        if ((dynamic_cast<RType::ECS::ID *>(_collideA.at(k).get())->getId() == dynamic_cast<RType::ECS::ID *>(_gameObjects.at(i).get())->getId() && dynamic_cast<RType::ECS::ID *>(_collideB.at(k).get())->getId() == dynamic_cast<RType::ECS::ID *>(_gameObjects.at(j).get())->getId()) || (dynamic_cast<RType::ECS::ID *>(_collideA.at(k).get())->getId() == dynamic_cast<RType::ECS::ID *>(_gameObjects.at(j).get())->getId() && dynamic_cast<RType::ECS::ID *>(_collideB.at(k).get())->getId() == dynamic_cast<RType::ECS::ID *>(_gameObjects.at(i).get())->getId())) {
            _collideA.erase(_collideA.begin()+k);
            _collideB.erase(_collideB.begin()+k);
        }
}

void RType::Server::Game::checkCollideNext(int i, int j) noexcept
{
    for (int k = 0; k != (int)_collideA.size(); ++k)
        if ((dynamic_cast<RType::ECS::ID *>(_collideA.at(k).get())->getId() != dynamic_cast<RType::ECS::ID *>(_gameObjects.at(i).get())->getId() && dynamic_cast<RType::ECS::ID *>(_collideB.at(k).get())->getId() != dynamic_cast<RType::ECS::ID *>(_gameObjects.at(j).get())->getId()) && (dynamic_cast<RType::ECS::ID *>(_collideA.at(k).get())->getId() != dynamic_cast<RType::ECS::ID *>(_gameObjects.at(j).get())->getId() && dynamic_cast<RType::ECS::ID *>(_collideB.at(k).get())->getId() != dynamic_cast<RType::ECS::ID *>(_gameObjects.at(i).get())->getId())) {
            _collideA.emplace_back(_gameObjects.at(i).get());
            _collideB.emplace_back(_gameObjects.at(j).get());
            dynamic_cast<RType::ECS::EffectHandler *>(_gameObjects.at(i).get())->loadEffect(_gameObjects.at(i), _gameObjects.at(j));
        }
}

void RType::Server::Game::checkCollide() noexcept
{
    for (int i = 0; i != (int)_gameObjects.size(); ++i)
        for (int j = 0; j != (int)_gameObjects.size(); ++j)
            if (i != j && dynamic_cast<RType::ECS::HitBox *>(_gameObjects.at(i).get())->isColliding(
                    RType::ECS::Position(dynamic_cast<RType::ECS::Position *>(_gameObjects.at(i).get())->getXPos(), dynamic_cast<RType::ECS::Position *>(_gameObjects.at(i).get())->getYPos()), RType::ECS::HitBox(dynamic_cast<RType::ECS::HitBox *>(_gameObjects.at(j).get())->getWidth(), dynamic_cast<RType::ECS::HitBox *>(_gameObjects.at(j).get())->getHeight(), dynamic_cast<RType::ECS::HitBox *>(_gameObjects.at(j).get())->getOffset()), RType::ECS::Position(dynamic_cast<RType::ECS::Position *>(_gameObjects.at(j).get())->getXPos(), dynamic_cast<RType::ECS::Position *>(_gameObjects.at(j).get())->getYPos())))
                checkCollideNext(i, j);
            else {
                removeCollide(i, j);
                i = 0;
            }
}
