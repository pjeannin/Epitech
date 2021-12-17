/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include <iostream>
#include "ValidateJoinRoom.hpp"
#include <utility>

RType::Client::GameObjects::ValidateJoinRoom::ValidateJoinRoom(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position) noexcept : RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position>(std::move(id), std::move(drawable), std::move(position)), _visible(false) { }

bool RType::Client::GameObjects::ValidateJoinRoom::getVisible() {
    return (_visible);
}

void RType::Client::GameObjects::ValidateJoinRoom::setVisible(bool visible) {
    _visible = visible;
}

void RType::Client::GameObjects::ValidateJoinRoom::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept {
    if (_visible)
        draw((RType::ECS::Position)*this);
}
