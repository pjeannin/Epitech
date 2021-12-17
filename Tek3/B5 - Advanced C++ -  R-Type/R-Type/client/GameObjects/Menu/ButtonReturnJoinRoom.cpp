/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include <iostream>
#include "ButtonReturnJoinRoom.hpp"
#include "client/GameObjects/SoundClicked.hpp"
#include "client/Scene/NewGameScene.hpp"

RType::Client::GameObjects::ButtonReturnJoinRoom::ButtonReturnJoinRoom(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText text, RType::Client::Client *client) noexcept
        : GameObject(std::move(id), std::move(position), std::move(text)), _currentButton(Target::NEW_GAME), _client(client) {

}

void RType::Client::GameObjects::ButtonReturnJoinRoom::update(const RType::AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *scene) noexcept
{
    RType::Client::GameObjects::SoundClicked sound(RType::ECS::ID(1), RType::ECS::SfmlSound("../../assets/sound/buttonClicked.ogg", _client->getEffectVolume()));
    if (event.getKeyEvent()[RType::AEvent::ESC])
        switch (_currentButton) {
            case Target::NEW_GAME: {
                sound.setVolume(_client->getEffectVolume());
                sound.play();
                ((RType::ECS::Scene::IScene *)scene)->setNextScene(std::make_shared<RType::Client::Scene::NewGameScene>(_window, _client));
                break;
            }
        }
    draw((RType::ECS::Position)*this);
}