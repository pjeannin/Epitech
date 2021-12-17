/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "client/GameObjects/Picture.hpp"
#include "client/GameObjects/Menu/NavInfo.hpp"
#include "client/GameObjects/Menu/SpriteSelectionSettings.hpp"
#include "client/GameObjects/Menu/TextMusicVolume.hpp"
#include "client/GameObjects/Menu/TextSoundVolume.hpp"
#include "SettingsScene.hpp"
#include "client/GameObjects/Menu/ButtonReturnSettings.hpp"

RType::Client::Scene::SettingsScene::SettingsScene(std::shared_ptr<sf::RenderWindow> window, RType::Client::Client *client) noexcept: AScene(std::move(window)), _client(client) {
    _font.loadFromFile("../../assets/font/MYRIADPRO-REGULAR.OTF");
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(11), *_client->getDrawable(RType::Client::Client::Drawable::Parallax1), RType::ECS::Position(0, 0), RType::ECS::Acceleration(1, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(12), *_client->getDrawable(RType::Client::Client::Drawable::Parallax2), RType::ECS::Position(0, 0), RType::ECS::Acceleration(2, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(13), *_client->getDrawable(RType::Client::Client::Drawable::Parallax3), RType::ECS::Position(0, 0), RType::ECS::Acceleration(4, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(14), *_client->getDrawable(RType::Client::Client::Drawable::Parallax4), RType::ECS::Position(0, 0), RType::ECS::Acceleration(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(15), *_client->getDrawable(RType::Client::Client::Drawable::Background), RType::ECS::Position(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GifTitle>(RType::ECS::ID(1), *_client->getDrawable(RType::Client::Client::Drawable::GifTitle), RType::ECS::Position(1350, 10)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::NavInfo>(RType::ECS::ID(2), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/main menu/topNavSettings.png", std::make_pair<unsigned int, unsigned int>(3840, 2160), std::make_pair<unsigned int, unsigned int>(3840, 2160), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.5, 0.5)), RType::ECS::Position(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GifWeapon>(RType::ECS::ID(3), *_client->getDrawable(RType::Client::Client::Drawable::GifWeapon), RType::ECS::Position(1050, 600)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::SpriteSelectionSettings>(RType::ECS::ID(4), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/main menu/rectangleSelection.png", std::make_pair<unsigned int, unsigned int>(1448, 134), std::make_pair<unsigned int, unsigned int>(1448, 134), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.5, 0.5)), RType::ECS::Position(0, 300), RType::ECS::SfmlSound("../../assets/sound/buttonHovered.ogg", _client->getEffectVolume()), _client));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::TextMusicVolume>(RType::ECS::ID(5), RType::ECS::Position(460, 300), RType::ECS::SfmlText(_window, std::to_string((int)_client->getMusicVolume()) + "%", _font, 50, sf::Color::White), RType::ECS::SfmlSound("../../assets/sound/buttonHovered.ogg", _client->getMusicVolume()), _client));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::TextSoundVolume>(RType::ECS::ID(6), RType::ECS::Position(460, 400), RType::ECS::SfmlText(_window, std::to_string((int)_client->getEffectVolume()) + "%", _font, 50, sf::Color::White), RType::ECS::SfmlSound("../../assets/sound/buttonHovered.ogg", _client->getEffectVolume()), _client));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(7), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/escape.png", std::make_pair<unsigned int, unsigned int>(400, 400), std::make_pair<unsigned int, unsigned int>(400, 400), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.4, 0.4)), RType::ECS::Position(30, 1000)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::ButtonReturnSettings>(RType::ECS::ID(8), RType::ECS::Position(-10, 120), RType::ECS::SfmlText(_window, "l", _font, 50, sf::Color::White), _client));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(9), RType::ECS::Position(150, 300), RType::ECS::SfmlText(_window, "Music volume", _font, 50, sf::Color::White)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(10), RType::ECS::Position(150, 400), RType::ECS::SfmlText(_window, "Effect volume", _font, 50, sf::Color::White)));
}

void RType::Client::Scene::SettingsScene::update(const RType::AEvent &event) noexcept {
    AScene::update(event);
}

