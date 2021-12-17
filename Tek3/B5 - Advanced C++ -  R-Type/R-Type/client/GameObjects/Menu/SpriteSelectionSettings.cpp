/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SpriteSelectionSettings.hpp"
#include <utility>
#include "client/GameObjects/SoundClicked.hpp"

RType::Client::GameObjects::SpriteSelectionSettings::SpriteSelectionSettings(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept:
        GameObject(std::move(id), std::move(drawable), std::move(position), std::move(hover)), _nbButtons(2), _buttonSelected(1), _client(client)
{

}

void RType::Client::GameObjects::SpriteSelectionSettings::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    std::vector<bool> keys = event.getKeyEvent();
    ECS::SfmlSound sound("../../assets/sound/buttonClicked.ogg", _client->getEffectVolume());
    ECS::SfmlSound::setVolume(_client->getEffectVolume());
    sound.setVolume(_client->getEffectVolume());
    if (keys[RType::AEvent::DOWN] && _buttonSelected < _nbButtons) {
        play();
        _posY += 100;
        _buttonSelected++;
    }
    if (keys[RType::AEvent::UP] && _buttonSelected > 1) {
        play();
        _posY -= 100;
        _buttonSelected--;
    }
    draw((RType::ECS::Position)*this);
}
