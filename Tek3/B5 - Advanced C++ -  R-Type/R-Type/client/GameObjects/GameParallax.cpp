/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "GameParallax.hpp"
#include <utility>

RType::Client::GameObjects::GameParallax::GameParallax(const RType::ECS::ID &id, const RType::ECS::SfmlDrawable &drawable, const RType::ECS::Position &position, const RType::ECS::Acceleration &acceleration) noexcept :
        GameObject(id, drawable, position, acceleration), _clockTab({10}), _clock(1)
{
    _clock.setNextMoment(_clockTab);
}

void RType::Client::GameObjects::GameParallax::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    int check = 0;
    check = _clock.numberOfRep(0);
    for (int i = 0; i < check; ++i)
        this->setXPos(this->getXPos() - this->getXAcceleration());
    if (this->getXPos() <= -1920)
        this->setXPos(0);
        /*moveSprite();*/
/*    if (_offset.second >= 13950 && _offset.first >= 1600) {
        moveSprite();
        moveSprite();
        moveSprite();
        moveSprite();
   }*/
    draw((RType::ECS::Position)*this);
}