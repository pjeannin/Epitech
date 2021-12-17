/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "shared/Event/AEvent.hpp"
#include "AGameManager.hpp"

RType::Server::AGameManager::AGameManager() {

}

std::vector<std::shared_ptr<RType::ECS::IGameObject>> &RType::Server::AGameManager::getGameObjects() noexcept { return _gameObjects; }

void RType::Server::AGameManager::update() noexcept {
    RType::AEvent event;
    for (auto &gameObject : _gameObjects)
        gameObject->update(event, _gameObjects, this);
}
