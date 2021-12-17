/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_IGAMEOBJECT_HPP
#define RTYPE_IGAMEOBJECT_HPP

#include <memory>
#include "shared/Event/AEvent.hpp"
#include "shared/ECS/IManager.hpp"
#include "IManager.hpp"

namespace RType::ECS {
    class IManager;
    class IGameObject {
        public:
            enum Type {
                PLAYER,
                ENEMY,
                Ammo,
                OBJECT
            };
            virtual ~IGameObject() noexcept = default;
            virtual void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *manager) noexcept = 0;
            [[nodiscard]] virtual Type getType() const noexcept = 0;
    };
}

#endif //RTYPE_IGAMEOBJECT_HPP
