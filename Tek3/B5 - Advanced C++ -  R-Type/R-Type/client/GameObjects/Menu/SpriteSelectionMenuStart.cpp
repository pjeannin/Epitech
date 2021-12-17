/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SpriteSelectionMenuStart.hpp"
#include <utility>
#include "client/Scene/NewGameScene.hpp"
#include "client/Scene/SettingsScene.hpp"
#include "client/Scene/TutorialScene.hpp"
#include "client/GameObjects/SoundClicked.hpp"

RType::Client::GameObjects::SpriteSelectionMenuStart::SpriteSelectionMenuStart(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept:
GameObject(std::move(id), std::move(drawable), std::move(position), std::move(hover)), _currentButton(Target::NEW_GAME), _client(client)
{

}

void RType::Client::GameObjects::SpriteSelectionMenuStart::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *scene) noexcept
{
    std::vector<bool> keys = event.getKeyEvent();
    ECS::SfmlSound sound("../../assets/sound/buttonClicked.ogg", _client->getEffectVolume());
    ECS::SfmlSound::setVolume(_client->getEffectVolume());
    sound.setVolume(_client->getEffectVolume());
    if (keys[RType::AEvent::DOWN] && _currentButton < Target::TUTORIAL) {
        _posY += 100;
        _currentButton++;
        play();
    }
    if (keys[RType::AEvent::UP] && _currentButton > Target::NEW_GAME) {
        _posY -= 100;
        _currentButton--;
        play();
    }
    if (keys[RType::AEvent::ENTER])
        switch (_currentButton) {
            case Target::NEW_GAME: {
                sound.play();
                ((RType::ECS::Scene::IScene *)scene)->setNextScene(std::make_shared<RType::Client::Scene::NewGameScene>(_window, _client));
                break;
            }
            case Target::SETTINGS: {
                sound.play();
                ((RType::ECS::Scene::IScene *)scene)->setNextScene(std::make_shared<RType::Client::Scene::SettingsScene>(_window, _client));
                break;
            }
            case Target::TUTORIAL: {
                sound.play();
                ((RType::ECS::Scene::IScene *)scene)->setNextScene(std::make_shared<RType::Client::Scene::TutorialScene>(_window, _client));
                break;
            }
        }
    draw((RType::ECS::Position)*this);
}
