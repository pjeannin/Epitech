/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_AMMO2_HPP
#define RTYPE_AMMO2_HPP

#include "AAmmo.hpp"
#include <iostream>
#include <vector>

namespace RType::Client::GameObjects {
    class Ammo2 : public RType::ECS::AAmmo {
    public:
        explicit Ammo2(RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::SfmlDrawable) noexcept;
        ~Ammo2() override = default;
        Ammo2(const Ammo2 &other) noexcept = delete;
        explicit Ammo2(Ammo2 &&other) noexcept = delete;
        Ammo2 &operator=(const Ammo2 &other) const noexcept = delete;
        Ammo2 &operator=(Ammo2 &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_AMMO2_HPP
