/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Malus3.hpp"
#include <utility>

RType::Client::GameObjects::Malus3::Malus3(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlDrawable drawable) noexcept:
        ECS::AMalus(std::move(id), std::move(position), RType::Network::Udp::ObjectType::Malus3, std::move(drawable))
{

}

void RType::Client::GameObjects::Malus3::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *manager) noexcept
{
    RType::ECS::AMalus::update(event, gameObjects, manager);
}