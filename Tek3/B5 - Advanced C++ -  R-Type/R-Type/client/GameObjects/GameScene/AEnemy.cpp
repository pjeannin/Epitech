/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "AEnemy.hpp"

RType::ECS::AEnemy::AEnemy(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::Network::Udp::EnemyType type, RType::ECS::SfmlDrawable drawable) noexcept :
    GameObject(std::move(id), std::move(position), std::move(acceleration), std::move(drawable)), _type(type)
{

}

RType::Network::Udp::EnemyType RType::ECS::AEnemy::getName() const noexcept
{
    return (_type);
}

void RType::ECS::AEnemy::update(const RType::AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    draw((RType::ECS::Position)*this);
}