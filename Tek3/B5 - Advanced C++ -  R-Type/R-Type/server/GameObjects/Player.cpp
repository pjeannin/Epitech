/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Player.hpp"
#include <utility>

RType::Server::GameObjects::Player::Player(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::Score score, RType::ECS::WeaponHolder weaponHolder, RType::ECS::EffectHandler effectHandler) noexcept:
        GameObject(std::move(id), std::move(position), std::move(acceleration), std::move(health), std::move(hitBox), std::move(score), std::move(weaponHolder), std::move(effectHandler))
{

}

void RType::Server::GameObjects::Player::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{

}

std::string RType::Server::GameObjects::Player::getName() noexcept
{
    return (_name);
}

void RType::Server::GameObjects::Player::setName(const std::string &name) noexcept
{
    _name = name;
}
