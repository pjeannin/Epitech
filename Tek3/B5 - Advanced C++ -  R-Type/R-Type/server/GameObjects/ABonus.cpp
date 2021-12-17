/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "ABonus.hpp"

RType::ECS::ABonus::ABonus(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler, RType::Network::Udp::ObjectType type) noexcept :
        GameObject(std::move(id), std::move(position), std::move(health), std::move(hitBox), std::move(state), std::move(effectHandler)), _type(type)
{

}

RType::Network::Udp::ObjectType RType::ECS::ABonus::getName() const noexcept
{
    return (_type);
}

void RType::ECS::ABonus::update(const RType::AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{

}