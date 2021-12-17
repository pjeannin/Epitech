/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_ASOUND_HPP
#define RTYPE_ASOUND_HPP

#include "Position.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace RType::ECS {
    class ASound : public IComponent {
    public :
        explicit ASound(std::string path, float volume) noexcept;
        ~ASound() noexcept override = default;
        ASound(const ASound &other) noexcept;
        explicit ASound(ASound &&other) noexcept = delete;
        ASound &operator=(const ASound &other) const noexcept = delete;
        ASound &operator=(ASound &&other) const noexcept = delete;
        void setSound(const std::string&) noexcept;
        virtual void setVolume(float) noexcept = 0;
        virtual void play() noexcept = 0;

    protected:
        std::string _path;
        float _volume;
    };
}

#endif //RTYPE_ASOUND_HPP
