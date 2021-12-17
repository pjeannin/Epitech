/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_GIFWEAPON_HPP
#define RTYPE_GIFWEAPON_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlText.hpp"
#include "client/ECS/SfmlSound.hpp"
#include <unistd.h>
#include <iostream>
#include <vector>

namespace RType::Client::GameObjects {
    class GifWeapon : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position> {
        public:
            explicit GifWeapon(const RType::ECS::ID &id, const RType::ECS::SfmlDrawable &drawable, const RType::ECS::Position &position) noexcept;
            ~GifWeapon() override = default;
            GifWeapon(const GifWeapon &other) noexcept = delete;
            explicit GifWeapon(GifWeapon &&other) noexcept = delete;
            GifWeapon &operator=(const GifWeapon &other) const noexcept = delete;
            GifWeapon &operator=(GifWeapon &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        private:
            std::vector<int> _clockTab;
            Clock _clock;
    };
}

#endif //RTYPE_GIFWEAPON_HPP
