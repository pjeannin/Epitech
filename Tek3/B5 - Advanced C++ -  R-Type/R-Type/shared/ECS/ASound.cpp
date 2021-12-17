/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "ASound.hpp"

RType::ECS::ASound::ASound(std::string path, float volume) noexcept : _path(std::move(path)), _volume(volume)
{

}

RType::ECS::ASound::ASound(const RType::ECS::ASound &other) noexcept
{
    _path = other._path;
    _volume = other._volume;
}

void RType::ECS::ASound::setSound(const std::string& newMusic) noexcept
{
    _path = newMusic;
}

void RType::ECS::ASound::setVolume(float volume) noexcept { _volume = volume; }
