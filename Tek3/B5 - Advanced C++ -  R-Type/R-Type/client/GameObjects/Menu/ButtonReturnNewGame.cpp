/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include <iostream>
#include "ButtonReturnNewGame.hpp"
#include "client/Scene/MainMenuScene.hpp"
#include "client/GameObjects/SoundClicked.hpp"

RType::Client::GameObjects::ButtonReturnNewGame::ButtonReturnNewGame(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText text, RType::Client::Client *client) noexcept
        : GameObject(std::move(id), std::move(position), std::move(text)), _currentButton(Target::MAIN_MENU), _client(client) {

}

void RType::Client::GameObjects::ButtonReturnNewGame::update(const RType::AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *scene) noexcept
{
    RType::Client::GameObjects::SoundClicked sound(RType::ECS::ID(1), RType::ECS::SfmlSound("../../assets/sound/buttonClicked.ogg", _client->getEffectVolume()));
    if (event.getKeyEvent()[RType::AEvent::ESC])
        switch (_currentButton) {
            case Target::MAIN_MENU: {
                sound.setVolume(_client->getEffectVolume());
                sound.play();
                ((RType::ECS::Scene::IScene *)scene)->setNextScene(std::make_shared<RType::Client::Scene::MainMenuScene>(_window, _client));
                break;
            }
        }
    draw((RType::ECS::Position)*this);
}