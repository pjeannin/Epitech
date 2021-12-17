/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_AGAMEMANAGER_HPP
#define RTYPE_AGAMEMANAGER_HPP

#include <vector>
#include "IGameManager.hpp"

namespace RType::Server {
    class AGameManager : public IGameManager {
    public:
        AGameManager();
        [[nodiscard]] std::vector<std::shared_ptr<RType::ECS::IGameObject>> &getGameObjects() noexcept override;
        void update() noexcept override;

    protected:
        std::vector<std::shared_ptr<RType::ECS::IGameObject>> _gameObjects;
    };
}

#endif //RTYPE_AGAMEMANAGER_HPP
