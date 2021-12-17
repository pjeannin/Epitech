/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Enemy1.hpp"
#include <utility>

RType::Client::GameObjects::Enemy1::Enemy1(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::SfmlDrawable drawable) noexcept:
        ECS::AEnemy(std::move(id), std::move(position), std::move(acceleration), RType::Network::Udp::EnemyType::Enemy1, std::move(drawable))
{

}

void RType::Client::GameObjects::Enemy1::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *manager) noexcept
{
    RType::ECS::AEnemy::update(event, gameObjects, manager);
}