/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "NavInfo.hpp"
#include <utility>
#include <iostream>

RType::Client::GameObjects::NavInfo::NavInfo(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position) noexcept:
        GameObject(std::move(id), std::move(drawable), std::move(position))
{

}

void RType::Client::GameObjects::NavInfo::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    draw((RType::ECS::Position)*this);
}
