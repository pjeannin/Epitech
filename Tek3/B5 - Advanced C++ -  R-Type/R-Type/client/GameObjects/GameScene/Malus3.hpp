/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_MALUS3_HPP
#define RTYPE_MALUS3_HPP

#include "AMalus.hpp"
#include <iostream>
#include <vector>

namespace RType::Client::GameObjects {
    class Malus3 : public RType::ECS::AMalus {
    public:
        explicit Malus3(RType::ECS::ID, RType::ECS::Position, RType::ECS::SfmlDrawable) noexcept;
        ~Malus3() override = default;
        Malus3(const Malus3 &other) noexcept = delete;
        explicit Malus3(Malus3 &&other) noexcept = delete;
        Malus3 &operator=(const Malus3 &other) const noexcept = delete;
        Malus3 &operator=(Malus3 &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_MALUS3_HPP
