/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Bonus2.hpp"
#include <utility>

RType::Client::GameObjects::Bonus2::Bonus2(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlDrawable drawable) noexcept:
        ECS::ABonus(std::move(id), std::move(position), RType::Network::Udp::ObjectType::Bonus2, std::move(drawable))
{

}

void RType::Client::GameObjects::Bonus2::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *manager) noexcept
{
    RType::ECS::ABonus::update(event, gameObjects, manager);
}