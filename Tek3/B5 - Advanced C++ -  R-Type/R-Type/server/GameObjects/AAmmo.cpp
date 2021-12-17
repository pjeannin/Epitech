/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "AAmmo.hpp"

RType::ECS::AAmmo::AAmmo(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler, RType::ECS::Dammage dammage, RType::ECS::ID senderId, RType::Network::Udp::AmmoType type) noexcept :
        GameObject(std::move(id), std::move(position), std::move(acceleration), std::move(health), std::move(hitBox), std::move(state), std::move(effectHandler), std::move(dammage)),_senderId(senderId), _type(type), _clock(1)
{
    this->_clock.setNextMoment(std::vector<int> {50});
}

RType::ECS::ID RType::ECS::AAmmo::getSenderId() const noexcept
{
    return (_senderId);
}

RType::Network::Udp::AmmoType RType::ECS::AAmmo::getName() const noexcept
{
    return (_type);
}

void RType::ECS::AAmmo::update(const RType::AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    int nextMovement = this->_clock.numberOfRep(0);

    for (int i = 0; i < nextMovement; ++i)
        setXPos(getXPos() - 5);
}
