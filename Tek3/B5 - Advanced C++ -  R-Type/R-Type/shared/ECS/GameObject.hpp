/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_GAMEOBJECT_HPP__
#define __RTYPE_GAMEOBJECT_HPP__

#include "shared/ECS/IComponent.hpp"
#include "client/Scene/IScene.hpp"
#include "IGameObject.hpp"

#include <type_traits>

template<class T>
concept CComponent = std::is_base_of<RType::ECS::IComponent, T>::value;

namespace RType::ECS {
    template<CComponent ... Props>
    class GameObject : public RType::ECS::IGameObject, public Props ... {
        public:
            explicit GameObject(Props ... props) noexcept: Props(props)... { _type = OBJECT; }
            ~GameObject() noexcept override = default;
            GameObject(const GameObject &other) noexcept = delete;
            explicit GameObject(GameObject &&other) noexcept = delete;
            GameObject &operator=(const GameObject &other) const noexcept = delete;
            GameObject &operator=(GameObject &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *manager) noexcept override = 0;
            [[nodiscard]] Type getType() const noexcept override { return _type; }

    protected:
        Type _type;
    };
}

#endif //__RTYPE_GAMEOBJECT_HPP__
