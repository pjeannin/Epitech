/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "AAmmo.hpp"

RType::ECS::AAmmo::AAmmo(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::Network::Udp::AmmoType type, RType::ECS::SfmlDrawable drawable) noexcept :
        GameObject(std::move(id), std::move(position), std::move(acceleration), std::move(drawable)), _type(type)
{

}

RType::Network::Udp::AmmoType RType::ECS::AAmmo::getName() const noexcept
{
    return (_type);
}

void RType::ECS::AAmmo::update(const RType::AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    draw((RType::ECS::Position)*this);
}
