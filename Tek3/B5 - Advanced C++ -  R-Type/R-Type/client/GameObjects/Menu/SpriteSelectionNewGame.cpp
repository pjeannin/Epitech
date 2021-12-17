/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SpriteSelectionNewGame.hpp"
#include "client/Scene/JoinRoomScene.hpp"
#include "client/Scene/CreateRoomScene.hpp"
#include <utility>
#include "client/GameObjects/SoundClicked.hpp"
#include "InputText.hpp"

RType::Client::GameObjects::SpriteSelectionNewGame::SpriteSelectionNewGame(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept:
        GameObject(std::move(id), std::move(drawable), std::move(position), std::move(hover)), _currentButton(Target::JOIN), _pseudo(""), _client(client)
{

}

void RType::Client::GameObjects::SpriteSelectionNewGame::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept
{
    std::vector<bool> keys = event.getKeyEvent();
    ECS::SfmlSound sound("../../assets/sound/buttonClicked.ogg", _client->getEffectVolume());
    ECS::SfmlSound::setVolume(_client->getEffectVolume());
    sound.setVolume(_client->getEffectVolume());
    if (keys[RType::AEvent::DOWN] && _currentButton < Target::CREATE) {
        _posY += 100;
        _currentButton++;
        play();
    }
    if (keys[RType::AEvent::UP] && _currentButton > Target::JOIN) {
        _posY -= 100;
        _currentButton--;
        play();
    }
    for (auto &gameObject :gameObjects)
        if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 10)
            _pseudo = dynamic_cast<InputText *>(gameObject.get())->getInputText();
    if (keys[RType::AEvent::ENTER] && !_pseudo.empty()) {
        _client->setUsername(_pseudo);
        switch (_currentButton) {
            case Target::JOIN:
                sound.play();
                ((RType::ECS::Scene::IScene *) scene)->setNextScene(
                        std::make_shared<RType::Client::Scene::JoinRoomScene>(_window, _pseudo, _client));
                break;
            case Target::CREATE:
                sound.play();
                ((RType::ECS::Scene::IScene *) scene)->setNextScene(
                        std::make_shared<RType::Client::Scene::CreateRoomScene>(_window, _pseudo, _client));
                break;
        }
    }
    draw((RType::ECS::Position)*this);
}
