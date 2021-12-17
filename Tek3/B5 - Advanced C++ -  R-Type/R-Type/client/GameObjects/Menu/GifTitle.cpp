/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "GifTitle.hpp"
#include <utility>

RType::Client::GameObjects::GifTitle::GifTitle(const RType::ECS::ID &id, const RType::ECS::SfmlDrawable &drawable, const RType::ECS::Position &position) noexcept :
        GameObject(id, drawable, position), _clockTab({25}), _clock(1)
{
    _clock.setNextMoment(_clockTab);
}

void RType::Client::GameObjects::GifTitle::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    int check = 0;
    check = _clock.numberOfRep(0);
    for (int i = 0; i < check; ++i)
        moveSprite();
    if (_offset.second >= 13950 && _offset.first >= 1600) {
        moveSprite();
        moveSprite();
        moveSprite();
        moveSprite();
    }
    draw((RType::ECS::Position)*this);
}
