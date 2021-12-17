/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_IMANAGER_HPP
#define RTYPE_IMANAGER_HPP

#include "shared/ECS/IGameObject.hpp"

namespace RType::ECS {
    class IGameObject;
    class IManager {
        public:
            virtual ~IManager() noexcept = default;
            [[nodiscard]] virtual std::vector<std::shared_ptr<RType::ECS::IGameObject>> &getGameObjects() noexcept = 0;
            virtual void update() noexcept = 0;
        };
}

#endif