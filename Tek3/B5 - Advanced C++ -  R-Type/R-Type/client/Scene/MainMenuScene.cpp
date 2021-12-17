/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "MainMenuScene.hpp"
#include <utility>

RType::Client::Scene::MainMenuScene::MainMenuScene(std::shared_ptr<sf::RenderWindow> window, RType::Client::Client *client) noexcept : AScene(std::move(window)), _client(client) {
    _font.loadFromFile("../../assets/font/MYRIADPRO-REGULAR.OTF");
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(8), *_client->getDrawable(RType::Client::Client::Drawable::Parallax1), RType::ECS::Position(0, 0), RType::ECS::Acceleration(1, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(9), *_client->getDrawable(RType::Client::Client::Drawable::Parallax2), RType::ECS::Position(0, 0), RType::ECS::Acceleration(2, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(10), *_client->getDrawable(RType::Client::Client::Drawable::Parallax3), RType::ECS::Position(0, 0), RType::ECS::Acceleration(4, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(11), *_client->getDrawable(RType::Client::Client::Drawable::Parallax4), RType::ECS::Position(0, 0), RType::ECS::Acceleration(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(12), *_client->getDrawable(RType::Client::Client::Drawable::Background), RType::ECS::Position(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GifWeapon>(RType::ECS::ID(1), *_client->getDrawable(RType::Client::Client::Drawable::GifWeapon), RType::ECS::Position(1050, 600)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GifTitle>(RType::ECS::ID(2), *_client->getDrawable(RType::Client::Client::Drawable::GifTitle), RType::ECS::Position(1350, 10)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::NavInfo>(RType::ECS::ID(3), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/main menu/topNavMenu.png", std::make_pair<unsigned int, unsigned int>(3840, 2160), std::make_pair<unsigned int, unsigned int>(3840, 2160), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.5, 0.5)), RType::ECS::Position(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::SpriteSelectionMenuStart>(RType::ECS::ID(4), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/main menu/rectangleSelection.png", std::make_pair<unsigned int, unsigned int>(1448, 134), std::make_pair<unsigned int, unsigned int>(1448, 134), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.5, 0.5)), RType::ECS::Position(0, 300), RType::ECS::SfmlSound("../../assets/sound/buttonHovered.ogg", _client->getEffectVolume()), _client));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(5), RType::ECS::Position(150, 300), RType::ECS::SfmlText(_window, "New Game", _font, 50, sf::Color::White)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(6), RType::ECS::Position(150, 400), RType::ECS::SfmlText(_window, "Settings", _font, 50, sf::Color::White)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(7), RType::ECS::Position(150, 500), RType::ECS::SfmlText(_window, "Tutorial", _font, 50, sf::Color::White)));
}

void RType::Client::Scene::MainMenuScene::update(const RType::AEvent &event) noexcept {
    ECS::Scene::AScene::update(event);
}