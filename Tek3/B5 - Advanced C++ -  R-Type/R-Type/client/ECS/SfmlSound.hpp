/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SFMLSOUND_HPP
#define RTYPE_SFMLSOUND_HPP

#include <SFML/Audio.hpp>
#include "shared/ECS/ASound.hpp"

namespace RType::ECS {
    class SfmlSound : public ASound {
    public:
        SfmlSound(std::string const &path, float volume) noexcept;
        ~SfmlSound() noexcept override = default;
        SfmlSound(const SfmlSound &other) noexcept;
        explicit SfmlSound(SfmlSound &&other) noexcept = delete;
        SfmlSound &operator=(const SfmlSound &other) const noexcept = delete;
        SfmlSound &operator=(SfmlSound &&other) const noexcept = delete;
        void setSound(const std::string&) noexcept;
        void setVolume(float) noexcept override;
        void play() noexcept override;

    protected:
        std::string _path;
        float _volume;
        sf::SoundBuffer _buffer;
        sf::Sound _sound;
    };
}

#endif //RTYPE_SFMLSOUND_HPP
