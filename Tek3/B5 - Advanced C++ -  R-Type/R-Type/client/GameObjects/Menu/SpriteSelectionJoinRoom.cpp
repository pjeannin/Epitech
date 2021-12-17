/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SpriteSelectionJoinRoom.hpp"
#include <utility>
#include "client/Scene/NewGameScene.hpp"
#include "client/GameObjects/SoundClicked.hpp"
#include "ValidateJoinRoom.hpp"
#include "InputText.hpp"

RType::Client::GameObjects::SpriteSelectionJoinRoom::SpriteSelectionJoinRoom(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept:
        GameObject(std::move(id), std::move(drawable), std::move(position), std::move(hover)), _currentButton(Target::JOINROOM), _client(client), _validate(false), _validateRoom(false)
{

}

void RType::Client::GameObjects::SpriteSelectionJoinRoom::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *) noexcept
{
    std::vector<bool> keys = event.getKeyEvent();
    ECS::SfmlSound sound("../../assets/sound/buttonClicked.ogg", _client->getEffectVolume());
    ECS::SfmlSound::setVolume(_client->getEffectVolume());
    sound.setVolume(_client->getEffectVolume());
    if (keys[RType::AEvent::DOWN] && _currentButton == Target::JOINROOM && _validateRoom) {
        _posY += 100;
        _currentButton++;
        play();
    }
    if (keys[RType::AEvent::UP] && _currentButton == Target::READY) {
        _posY -= 100;
        _currentButton--;
        play();
    }
    if (keys[RType::AEvent::ENTER])
        switch (_currentButton) {
            case Target::JOINROOM: {
                sound.play();
                bool ok = false;
                bool okText = false;
                std::string roomName;
                for (auto &gameObject :gameObjects)
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 8 && !(roomName = dynamic_cast<RType::Client::GameObjects::InputText *>(gameObject.get())->getText()).empty())
                        okText = true;
                for (auto &gameObject :gameObjects) {
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 6 && dynamic_cast<RType::ECS::Position *>(gameObject.get())->getYPos() == 300 && okText)
                        ok = true;
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 13 && ok) {
                        dynamic_cast<RType::Client::GameObjects::Text *>(gameObject.get())->setVisible(true);
                        _validateRoom = true;
                        _client->sendJoinGame(roomName, _client->getUsername());
                    }
                }
                break;
            }
            case Target::READY: {
                sound.play();
                bool ok = false;
                for (auto &gameObject :gameObjects) {
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 6 &&
                        dynamic_cast<RType::ECS::Position *>(gameObject.get())->getYPos() == 400)
                        ok = true;
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 7 && ok) {
                        dynamic_cast<RType::Client::GameObjects::ValidateJoinRoom *>(gameObject.get())->setVisible(true);
                        _validate = true;
                        _client->sendReadySignal();
                    }
                }
                break;
            }
        }
    draw((RType::ECS::Position)*this);
}

