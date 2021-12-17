/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_TEXTMUSICVOLUME_HPP
#define RTYPE_TEXTMUSICVOLUME_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlText.hpp"
#include <iostream>
#include <vector>
#include "client/ECS/SfmlSound.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;
    namespace GameObjects {
        class TextMusicVolume : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::SfmlText, RType::ECS::SfmlSound> {
        public:
            explicit TextMusicVolume(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText volume,
                                     RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept;
            ~TextMusicVolume() override = default;
            TextMusicVolume(const TextMusicVolume &other) noexcept = delete;
            explicit TextMusicVolume(TextMusicVolume &&other) noexcept = delete;
            TextMusicVolume &operator=(const TextMusicVolume &other) const noexcept = delete;
            TextMusicVolume &operator=(TextMusicVolume &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects,
                        RType::ECS::IManager *scene) noexcept override;

        private:
            int _volume;
            RType::Client::Client *_client;
        };
}
}

#endif //RTYPE_TEXTMUSICVOLUME_HPP
