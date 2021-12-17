/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SpriteSelectionCreateRoom.hpp"
#include <utility>
#include "client/Scene/NewGameScene.hpp"
#include "client/GameObjects/SoundClicked.hpp"
#include "ValidateCreateRoom.hpp"
#include "InputText.hpp"

RType::Client::GameObjects::SpriteSelectionCreateRoom::SpriteSelectionCreateRoom(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept:
        GameObject(std::move(id), std::move(drawable), std::move(position), std::move(hover)), _currentButton(Target::READY), _client(client), _validate(false)
{

}

void RType::Client::GameObjects::SpriteSelectionCreateRoom::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *) noexcept
{
    std::vector<bool> keys = event.getKeyEvent();
    ECS::SfmlSound sound("../../assets/sound/buttonClicked.ogg", _client->getEffectVolume());
    ECS::SfmlSound::setVolume(_client->getEffectVolume());
    sound.setVolume(_client->getEffectVolume());
    if (keys[RType::AEvent::DOWN] && _currentButton == Target::READY && _validate) {
        _posY += 100;
        _currentButton++;
        play();
    }
    if (keys[RType::AEvent::UP] && _currentButton == Target::STARTGAME) {
        _posY -= 100;
        _currentButton--;
        play();
    }
    if (keys[RType::AEvent::ENTER])
        switch (_currentButton) {
            case Target::READY: {
                sound.play();
                bool ok = false;
                bool okText = false;
                std::string roomName;
                for (auto &gameObject : gameObjects)
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 8 && !(roomName = dynamic_cast<RType::Client::GameObjects::InputText *>(gameObject.get())->getText()).empty())
                        okText = true;
                for (auto &gameObject : gameObjects) {
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 6 && dynamic_cast<RType::ECS::Position *>(gameObject.get())->getYPos() == 300 && okText)
                        ok = true;
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 7 && ok) {
                        dynamic_cast<RType::Client::GameObjects::ValidateCreateRoom *>(gameObject.get())->setVisible(true);
                        _validate = true;
                        _client->sendCreateLobby(roomName, _client->getUsername());
                        usleep(500);
                        _client->sendReadySignal();
                    }
                    if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 13 && ok)
                        dynamic_cast<RType::Client::GameObjects::Text *>(gameObject.get())->setVisible(true);
                }
                break;
            }
            case Target::STARTGAME: {
                sound.play();
                _client->sendStartSignal();
                break;
            }
        }
    draw((RType::ECS::Position)*this);
}

