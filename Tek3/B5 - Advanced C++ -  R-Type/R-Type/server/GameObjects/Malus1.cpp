/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Malus1.hpp"
#include <utility>

RType::Server::GameObjects::Malus1::Malus1(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept:
        ECS::AMalus(std::move(id), std::move(position), std::move(health), std::move(hitBox), std::move(state), std::move(effectHandler), RType::Network::Udp::ObjectType::Malus1)
{

}

void RType::Server::GameObjects::Malus1::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{

}