/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "Text.hpp"
#include <utility>

RType::Client::GameObjects::Text::Text(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText text, bool visible) noexcept:
        GameObject(std::move(id), std::move(position), std::move(text)), _visible(visible)
{

}

void RType::Client::GameObjects::Text::setVisible(bool visible)
{
    _visible = visible;
}

bool RType::Client::GameObjects::Text::getVisible()
{
    return (_visible);
}

void RType::Client::GameObjects::Text::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    if (_visible)
        draw((RType::ECS::Position)*this);
}