/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "InputText.hpp"
#include <utility>

RType::Client::GameObjects::InputText::InputText(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText text, RType::ECS::SfmlSound modif) noexcept:
        GameObject(std::move(id), std::move(position), std::move(text), std::move(modif))
{
    this->_ascii = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ.";
}

void RType::Client::GameObjects::InputText::checkKeyboard(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::Scene::IScene *) noexcept
{
    std::vector<bool> keys = event.getKeyEvent();

    if (_tmpText.size() < 10) {
        for (int i = RType::AEvent::ZERO; i < RType::AEvent::REMOVE; ++i) {
            if (keys[i]) {
                play();
                this->_tmpText += this->_ascii[i - 7];
                break;
            }
        }
    }
    if (keys[RType::AEvent::REMOVE]) {
        play();
        _tmpText = _tmpText.substr(0, _tmpText.size()-1);
    }
    ECS::SfmlText::setText(_tmpText);
}

std::string RType::Client::GameObjects::InputText::getInputText()
{
    return (_tmpText);
}

void RType::Client::GameObjects::InputText::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept
{
    checkKeyboard(event, gameObjects, ((RType::ECS::Scene::IScene *)scene));
    draw((RType::ECS::Position)*this);
}