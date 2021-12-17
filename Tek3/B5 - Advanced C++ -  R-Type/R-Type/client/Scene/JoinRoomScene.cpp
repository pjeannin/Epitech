/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "client/GameObjects/Picture.hpp"
#include "client/GameObjects/Menu/NavInfo.hpp"
#include "client/GameObjects/Menu/ButtonReturnJoinRoom.hpp"
#include "client/GameObjects/Menu/InputText.hpp"
#include "client/GameObjects/Text.hpp"
#include "JoinRoomScene.hpp"
#include "client/GameObjects/Menu/SpriteSelectionJoinRoom.hpp"
#include "client/GameObjects/Menu/ValidateJoinRoom.hpp"

void RType::Client::Scene::JoinRoomScene::addPlayer(std::string newPlayer)
{
    _players.push_back(newPlayer);
}

void RType::Client::Scene::JoinRoomScene::printPlayers(int startId)
{
    int nb = 1;
    int posX = 1240;
    int posY = 400;
    for (std::vector<std::string>::const_iterator i = _players.begin(); i != _players.end(); ++i) {
        _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(startId), RType::ECS::Position(posX, posY), RType::ECS::SfmlText(_window, (std::string)"#" + std::to_string(nb) + " <" + *i + ">", _font, 50, sf::Color::White)));
        posY += 100;
        if (nb == 5 || nb == 10) {
            posX += 520;
            posY = 400;
        }
        ++nb;
        ++startId;
    }
}

RType::Client::Scene::JoinRoomScene::JoinRoomScene(std::shared_ptr<sf::RenderWindow> window, std::string myPseudo, RType::Client::Client *client) noexcept: AScene(std::move(window)), _client(client)
{
    _players.push_back(myPseudo);
    _font.loadFromFile("../../assets/font/MYRIADPRO-REGULAR.OTF");
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(14), *_client->getDrawable(RType::Client::Client::Drawable::Parallax1), RType::ECS::Position(0, 0), RType::ECS::Acceleration(1, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(15), *_client->getDrawable(RType::Client::Client::Drawable::Parallax2), RType::ECS::Position(0, 0), RType::ECS::Acceleration(2, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(16), *_client->getDrawable(RType::Client::Client::Drawable::Parallax3), RType::ECS::Position(0, 0), RType::ECS::Acceleration(4, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(17), *_client->getDrawable(RType::Client::Client::Drawable::Parallax4), RType::ECS::Position(0, 0), RType::ECS::Acceleration(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(18), *_client->getDrawable(RType::Client::Client::Drawable::Background), RType::ECS::Position(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GifTitle>(RType::ECS::ID(1), *_client->getDrawable(RType::Client::Client::Drawable::GifTitle), RType::ECS::Position(1350, 10)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::NavInfo>(RType::ECS::ID(2), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/main menu/topNavCreateRoom.png", std::make_pair<unsigned int, unsigned int>(3840, 2160), std::make_pair<unsigned int, unsigned int>(3840, 2160), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.5, 0.5)), RType::ECS::Position(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GifWeapon>(RType::ECS::ID(3), *_client->getDrawable(RType::Client::Client::Drawable::GifWeapon), RType::ECS::Position(850, 600)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(4), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/frame2.png", std::make_pair<unsigned int, unsigned int>(600, 800), std::make_pair<unsigned int, unsigned int>(600, 800), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(1, 0.85)), RType::ECS::Position(1200, 350)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(5), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/littleFrame.png", std::make_pair<unsigned int, unsigned int>(500, 100), std::make_pair<unsigned int, unsigned int>(500, 100), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(1, 1)), RType::ECS::Position(1200, 225)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::SpriteSelectionJoinRoom>(RType::ECS::ID(6), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/main menu/rectangleSelection.png", std::make_pair<unsigned int, unsigned int>(1448, 134), std::make_pair<unsigned int, unsigned int>(1448, 134), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.5, 0.5)), RType::ECS::Position(0, 300), RType::ECS::SfmlSound("../../assets/sound/buttonHovered.ogg", _client->getEffectVolume()), _client));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::ValidateJoinRoom>(RType::ECS::ID(7), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/validate.png", std::make_pair<unsigned int, unsigned int>(90, 90), std::make_pair<unsigned int, unsigned int>(90, 90), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.65, 0.65)), RType::ECS::Position(475, 405)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::InputText>(RType::ECS::ID(8), RType::ECS::Position(1240, 240), RType::ECS::SfmlText(_window, "", _font, 50, sf::Color::White), RType::ECS::SfmlSound("../../assets/sound/buttonHovered.ogg", _client->getEffectVolume())));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(9), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/escape.png", std::make_pair<unsigned int, unsigned int>(400, 400), std::make_pair<unsigned int, unsigned int>(400, 400), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.4, 0.4)), RType::ECS::Position(30, 1000)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::ButtonReturnJoinRoom>(RType::ECS::ID(10), RType::ECS::Position(-10, 120), RType::ECS::SfmlText(_window, "l", _font, 50, sf::Color::White), _client));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(11), RType::ECS::Position(1210, 160), RType::ECS::SfmlText(_window, "Room name:", _font, 50, sf::Color::White)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(12), RType::ECS::Position(150, 300), RType::ECS::SfmlText(_window, "Join the room", _font, 50, sf::Color::White)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Text>(RType::ECS::ID(13), RType::ECS::Position(150, 400), RType::ECS::SfmlText(_window, "Ready", _font, 50, sf::Color::White), false));
    printPlayers(44);
}

void RType::Client::Scene::JoinRoomScene::update(const RType::AEvent &event) noexcept {
    AScene::update(event);
}
