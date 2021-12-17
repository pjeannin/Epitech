/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_IGAMEMANAGER_HPP
#define RTYPE_IGAMEMANAGER_HPP

#include <memory>
#include "shared/ECS/IManager.hpp"

namespace RType::Server {
    class IGameManager : public ECS::IManager {
    public:
        ~IGameManager() override = default;
        [[nodiscard]] std::vector<std::shared_ptr<RType::ECS::IGameObject>> &getGameObjects() noexcept override = 0;
        void update() noexcept override = 0;
    };
}

#endif