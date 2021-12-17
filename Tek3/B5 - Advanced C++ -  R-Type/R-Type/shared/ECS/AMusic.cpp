/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "AMusic.hpp"

RType::ECS::AMusic::AMusic(std::string path, float volume) noexcept : _path(std::move(path)), _volume(volume)
{

}

RType::ECS::AMusic::AMusic(const RType::ECS::AMusic &other) noexcept
{
    _path = other._path;
    _volume = other._volume;
}

void RType::ECS::AMusic::setMusic(const std::string& newMusic) noexcept
{
    _path = newMusic;
}

void RType::ECS::AMusic::setVolume(float volume) noexcept {
    _volume = volume;
}
