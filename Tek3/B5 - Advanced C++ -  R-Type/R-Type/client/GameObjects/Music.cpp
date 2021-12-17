/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include <iostream>
#include "Music.hpp"
#include <utility>

RType::Client::GameObjects::Music::Music(RType::ECS::ID id, RType::ECS::SfmlMusic music) noexcept : RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlMusic>(std::move(id), std::move(music)), _isPlaying(false)
{

}

void RType::Client::GameObjects::Music::update(const AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *) noexcept
{
    if (!_isPlaying) {
        play();
        _isPlaying = true;
    }
}
