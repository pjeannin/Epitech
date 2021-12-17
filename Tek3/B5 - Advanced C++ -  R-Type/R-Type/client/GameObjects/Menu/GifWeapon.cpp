/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "GifWeapon.hpp"
#include <utility>

RType::Client::GameObjects::GifWeapon::GifWeapon(const RType::ECS::ID &id, const RType::ECS::SfmlDrawable &drawable, const RType::ECS::Position &position) noexcept :
        GameObject(id, drawable, position), _clockTab({10}), _clock(1)
{
    _clock.setNextMoment(_clockTab);
}

void RType::Client::GameObjects::GifWeapon::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    int check = 0;
    check = _clock.numberOfRep(0);
    for (int i = 0; i < check; ++i)
        moveSprite();
    if (_offset.second >= 12760 && _offset.first >= 2820) {
        moveSprite();
        moveSprite();
        moveSprite();
    }
    draw((RType::ECS::Position)*this);
}
