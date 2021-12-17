/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Malus2.hpp"
#include <utility>

RType::Client::GameObjects::Malus2::Malus2(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlDrawable drawable) noexcept:
        ECS::AMalus(std::move(id), std::move(position), RType::Network::Udp::ObjectType::Malus2, std::move(drawable))
{

}

void RType::Client::GameObjects::Malus2::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *manager) noexcept
{
    RType::ECS::AMalus::update(event, gameObjects, manager);
}