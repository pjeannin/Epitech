/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "AMalus.hpp"

RType::ECS::AMalus::AMalus(RType::ECS::ID id, RType::ECS::Position position, RType::Network::Udp::ObjectType type, RType::ECS::SfmlDrawable drawable) noexcept :
        GameObject(std::move(id), std::move(position), std::move(drawable)), _type(type)
{

}

RType::Network::Udp::ObjectType RType::ECS::AMalus::getName() const noexcept
{
    return (_type);
}

void RType::ECS::AMalus::update(const RType::AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    draw((RType::ECS::Position)*this);
}