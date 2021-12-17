/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Bonus1.hpp"
#include <utility>

RType::Server::GameObjects::Bonus1::Bonus1(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept:
        ECS::ABonus(std::move(id), std::move(position), std::move(health), std::move(hitBox), std::move(state), std::move(effectHandler), RType::Network::Udp::ObjectType::Bonus1)
{

}

void RType::Server::GameObjects::Bonus1::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{

}