/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "ABonus.hpp"

RType::ECS::ABonus::ABonus(RType::ECS::ID id, RType::ECS::Position position, RType::Network::Udp::ObjectType type, RType::ECS::SfmlDrawable drawable) noexcept :
        GameObject(std::move(id), std::move(position), std::move(drawable)), _type(type)
{

}

RType::Network::Udp::ObjectType RType::ECS::ABonus::getName() const noexcept
{
    return (_type);
}

void RType::ECS::ABonus::update(const RType::AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    draw((RType::ECS::Position)*this);
}