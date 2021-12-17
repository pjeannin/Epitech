/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "TextMusicVolume.hpp"
#include <utility>

RType::Client::GameObjects::TextMusicVolume::TextMusicVolume(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText volume, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept:
        GameObject(std::move(id), std::move(position), std::move(volume), std::move(hover)), _volume(client->getMusicVolume()), _client(client)
{

}

void RType::Client::GameObjects::TextMusicVolume::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *) noexcept
{
    std::vector<bool> keys = event.getKeyEvent();
    for (auto &gameObject :gameObjects)
        if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == 5 && dynamic_cast<RType::ECS::Position *>(gameObject.get())->getYPos() == 300) {
            if (keys[RType::AEvent::LEFT] && _volume > 0) {
                setText(std::to_string(_volume - 5) + "%");
                _volume -= 5;
                _client->setMusicVolume(_volume);
                ECS::SfmlSound::setVolume(_client->getEffectVolume());
                play();
            } else if (keys[RType::AEvent::RIGHT] && _volume < 100) {
                setText(std::to_string(_volume + 5) + "%");
                _volume += 5;
                _client->setMusicVolume(_volume);
                ECS::SfmlSound::setVolume(_client->getEffectVolume());
                play();
            }
        }
    draw((RType::ECS::Position)*this);
}
