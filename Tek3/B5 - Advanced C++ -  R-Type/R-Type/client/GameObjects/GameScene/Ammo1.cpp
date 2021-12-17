/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Ammo1.hpp"
#include <utility>

RType::Client::GameObjects::Ammo1::Ammo1(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::SfmlDrawable drawable) noexcept:
        ECS::AAmmo(std::move(id), std::move(position), std::move(acceleration), RType::Network::Udp::AmmoType::Ammo1, std::move(drawable))
{

}

void RType::Client::GameObjects::Ammo1::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *manager) noexcept
{
    RType::ECS::AAmmo::update(event, gameObjects, manager);
}