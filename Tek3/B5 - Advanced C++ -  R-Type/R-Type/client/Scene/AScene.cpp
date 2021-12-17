/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "AScene.hpp"

#include <utility>

RType::ECS::Scene::AScene::AScene(std::shared_ptr<sf::RenderWindow> window) noexcept : _nextScene(nullptr), _gameObjects({}), _window(std::move((window))) { }

std::shared_ptr<RType::ECS::Scene::IScene> &RType::ECS::Scene::AScene::getNextScene() noexcept { return _nextScene; }

void RType::ECS::Scene::AScene::setNextScene(std::shared_ptr<RType::ECS::Scene::IScene> scene) noexcept { _nextScene = std::move(scene); }

std::vector<std::shared_ptr<RType::ECS::IGameObject>> &RType::ECS::Scene::AScene::getGameObjects() noexcept { return _gameObjects; }

void RType::ECS::Scene::AScene::update(const RType::AEvent &event) noexcept {
    for (auto &gameObject : _gameObjects)
        gameObject->update(event, _gameObjects, this);
}

std::shared_ptr<sf::RenderWindow> &RType::ECS::Scene::AScene::getWindow() noexcept { return _window; }

void RType::ECS::Scene::AScene::update() noexcept {}


