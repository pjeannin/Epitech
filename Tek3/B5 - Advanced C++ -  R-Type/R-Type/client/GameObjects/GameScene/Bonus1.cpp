/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Bonus1.hpp"
#include <utility>

RType::Client::GameObjects::Bonus1::Bonus1(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlDrawable drawable) noexcept:
        ECS::ABonus(std::move(id), std::move(position), RType::Network::Udp::ObjectType::Bonus1, std::move(drawable))
{

}

void RType::Client::GameObjects::Bonus1::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *manager) noexcept
{
    RType::ECS::ABonus::update(event, gameObjects, manager);
}