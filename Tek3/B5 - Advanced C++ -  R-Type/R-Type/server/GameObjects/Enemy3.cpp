/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Enemy3.hpp"
#include <utility>

RType::Server::GameObjects::Enemy3::Enemy3(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::WeaponHolder weaponHolder, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept:
        ECS::AEnemy(std::move(id), std::move(position), std::move(acceleration), std::move(health), std::move(hitBox), std::move(weaponHolder), std::move(state), std::move(effectHandler), RType::Network::Udp::EnemyType::Enemy3)
{
    _pattern = PatternMovementCreation();
}

std::vector<std::pair<int, int>> RType::Server::GameObjects::Enemy3::PatternMovementCreation() noexcept {
    std::vector<std::pair<int, int>> patt;

    for (int i = 0; i <= 50; ++i)
        patt.push_back(std::pair<int, int> {-2, 3});
    for (int i = 0; i <= 100; ++i)
        patt.push_back(std::pair<int, int> {-2, -3});
    for (int i = 0; i <= 50; ++i)
        patt.push_back(std::pair<int, int> {-2, 3});
    return patt;
}