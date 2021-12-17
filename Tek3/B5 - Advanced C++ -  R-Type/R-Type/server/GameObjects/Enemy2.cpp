/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Enemy2.hpp"
#include <utility>

RType::Server::GameObjects::Enemy2::Enemy2(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::WeaponHolder weaponHolder, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept:
        ECS::AEnemy(std::move(id), std::move(position), std::move(acceleration), std::move(health), std::move(hitBox), std::move(weaponHolder), std::move(state), std::move(effectHandler), RType::Network::Udp::EnemyType::Enemy2)
{
    _pattern = PatternMovementCreation();
}

std::vector<std::pair<int, int>> RType::Server::GameObjects::Enemy2::PatternMovementCreation() noexcept {
    std::vector<std::pair<int, int>> patt;

    for (int i = 0; i <= 20; ++i)
        patt.push_back(std::pair<int, int>{-2,0});
    for (int i = 0; i <= 10; ++i)
        patt.push_back(std::pair<int, int>{-12,0});
    return patt;
}