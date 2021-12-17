/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SFMLMUSIC_HPP
#define RTYPE_SFMLMUSIC_HPP

#include <SFML/Audio.hpp>
#include "shared/ECS/AMusic.hpp"

namespace RType::ECS {
    class SfmlMusic : public AMusic {
    public:
        SfmlMusic(std::string const &path, float volume) noexcept;
        ~SfmlMusic() noexcept override = default;
        SfmlMusic(const SfmlMusic &other) noexcept;
        explicit SfmlMusic(SfmlMusic &&other) noexcept = delete;
        SfmlMusic &operator=(const SfmlMusic &other) const noexcept = delete;
        SfmlMusic &operator=(SfmlMusic &&other) const noexcept = delete;
        void setMusic(const std::string&) noexcept override;
        void setVolume(float) noexcept override;
        void play() noexcept override;

    protected:
        std::string _path;
        float _volume;
        sf::Music _music;
    };
}

#endif //RTYPE_SFMLMUSIC_HPP
