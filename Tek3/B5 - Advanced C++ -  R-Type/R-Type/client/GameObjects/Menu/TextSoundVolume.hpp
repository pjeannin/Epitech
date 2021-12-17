/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_TEXTSOUNDVOLUME_HPP
#define RTYPE_TEXTSOUNDVOLUME_HPP

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
        class TextSoundVolume
                : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::SfmlText, RType::ECS::SfmlSound> {
        public:
            explicit TextSoundVolume(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText volume,
                                     RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept;
            ~TextSoundVolume() override = default;
            TextSoundVolume(const TextSoundVolume &other) noexcept = delete;
            explicit TextSoundVolume(TextSoundVolume &&other) noexcept = delete;
            TextSoundVolume &operator=(const TextSoundVolume &other) const noexcept = delete;
            TextSoundVolume &operator=(TextSoundVolume &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects,
                        RType::ECS::IManager *scene) noexcept override;

        private:
            int _volume;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_TEXTSOUNDVOLUME_HPP
