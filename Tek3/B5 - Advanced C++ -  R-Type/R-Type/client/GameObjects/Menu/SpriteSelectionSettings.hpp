/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SPRITESELECTIONSETTINGS_HPP
#define RTYPE_SPRITESELECTIONSETTINGS_HPP

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
        class SpriteSelectionSettings
                : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position, RType::ECS::SfmlSound> {
        public:
            explicit SpriteSelectionSettings(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable,
                                             RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept;
            ~SpriteSelectionSettings() override = default;
            SpriteSelectionSettings(const SpriteSelectionSettings &other) noexcept = delete;
            explicit SpriteSelectionSettings(SpriteSelectionSettings &&other) noexcept = delete;
            SpriteSelectionSettings &operator=(const SpriteSelectionSettings &other) const noexcept = delete;
            SpriteSelectionSettings &operator=(SpriteSelectionSettings &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects,
                        RType::ECS::IManager *scene) noexcept override;
        private:
            int _nbButtons;
            int _buttonSelected;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_SPRITESELECTIONSETTINGS_HPP
