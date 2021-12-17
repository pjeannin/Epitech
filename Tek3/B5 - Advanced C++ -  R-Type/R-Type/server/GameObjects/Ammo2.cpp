/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Ammo2.hpp"
#include <utility>

RType::Client::GameObjects::Ammo2::Ammo2(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler, RType::ECS::Dammage dammage, RType::ECS::ID senderId) noexcept:
        ECS::AAmmo(std::move(id), std::move(position), std::move(acceleration), std::move(health), std::move(hitBox), std::move(state), std::move(effectHandler), std::move(dammage), senderId, RType::Network::Udp::AmmoType::Ammo2)
{

}