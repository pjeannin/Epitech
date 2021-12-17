//
// Created by Frederic Forster on 11/11/2021.
//

#ifndef RTYPE_AMUSIC_HPP
#define RTYPE_AMUSIC_HPP

#include "Position.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace RType::ECS {
    class AMusic : public IComponent {
        public :
            explicit AMusic(std::string path, float volume) noexcept;
            ~AMusic() noexcept override = default;
            AMusic(const AMusic &other) noexcept;
            explicit AMusic(AMusic &&other) noexcept = delete;
            AMusic &operator=(const AMusic &other) const noexcept = delete;
            AMusic &operator=(AMusic &&other) const noexcept = delete;
            virtual void setMusic(const std::string&) noexcept;
            virtual void setVolume(float) noexcept;
            virtual void play() noexcept = 0;

        protected:
            std::string _path;
            float _volume;
    };
}

#endif //RTYPE_AMUSIC_HPP
