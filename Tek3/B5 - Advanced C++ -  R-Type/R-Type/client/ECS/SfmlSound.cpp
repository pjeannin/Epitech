/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include <iostream>
#include "SfmlSound.hpp"

RType::ECS::SfmlSound::SfmlSound(const std::string &path, float volume) noexcept : ASound(path, volume),  _path(std::move(path)), _volume(std::move(volume))
{
    _buffer.loadFromFile(_path);
    _sound.setBuffer(_buffer);
}

RType::ECS::SfmlSound::SfmlSound(const RType::ECS::SfmlSound &other) noexcept : ASound(other),  _path(std::move(other._path)), _volume(std::move(other._volume))
{
    _buffer.loadFromFile(_path);
    _sound.setBuffer(_buffer);
}

void RType::ECS::SfmlSound::setSound(const std::string &newSound) noexcept
{
    ASound::setSound(newSound);
    _buffer.loadFromFile(_path);
    _sound.setBuffer(_buffer);
}

void RType::ECS::SfmlSound::play() noexcept
{
    _sound.setVolume(_volume);
    _sound.play();
}

void RType::ECS::SfmlSound::setVolume(float volume) noexcept {
    ASound::setVolume(volume);
    _volume = volume;
    _sound.setVolume(volume);
}
