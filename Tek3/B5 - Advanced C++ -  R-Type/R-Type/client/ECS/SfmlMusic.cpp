/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include <iostream>
#include "SfmlMusic.hpp"

RType::ECS::SfmlMusic::SfmlMusic(const std::string &path, float volume) noexcept : AMusic(path, volume), _path(std::move(path)), _volume(std::move(volume))
{
    _music.openFromFile(_path);
    _music.setVolume(_volume);
}

RType::ECS::SfmlMusic::SfmlMusic(const RType::ECS::SfmlMusic &other) noexcept : AMusic(other), _path(std::move(other._path)), _volume(std::move(other._volume))
{
    _music.openFromFile(_path);
}

void RType::ECS::SfmlMusic::setMusic(const std::string &newMusic) noexcept
{
    _music.openFromFile(newMusic);
}

void RType::ECS::SfmlMusic::play() noexcept
{
    _music.setLoop(true);
    _music.play();
}

void RType::ECS::SfmlMusic::setVolume(float volume) noexcept {
    AMusic::setVolume(volume);
    _music.setVolume(volume);
}

