/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SoundClicked.hpp"
#include <utility>
#include <iostream>

RType::Client::GameObjects::SoundClicked::SoundClicked(RType::ECS::ID id, RType::ECS::SfmlSound sound) noexcept:
        GameObject(std::move(id), std::move(sound))
{

}

void RType::Client::GameObjects::SoundClicked::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{

}