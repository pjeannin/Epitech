/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include <iostream>
#include "Picture.hpp"
#include <utility>

RType::Client::GameObjects::Picture::Picture(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position) noexcept : RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position>(std::move(id), std::move(drawable), std::move(position)) { }

void RType::Client::GameObjects::Picture::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept {
    draw((RType::ECS::Position)*this);
}
