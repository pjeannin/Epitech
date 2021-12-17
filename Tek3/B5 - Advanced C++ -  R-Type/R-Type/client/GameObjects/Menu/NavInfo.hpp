/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_NAVINFO_HPP
#define RTYPE_NAVINFO_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/Scene/MainMenuScene.hpp"

namespace RType::Client::GameObjects {
    class NavInfo : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position>  {
    public:
        explicit NavInfo(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position) noexcept;
        ~NavInfo() override = default;
        NavInfo(const NavInfo &other) noexcept = delete;
        explicit NavInfo(NavInfo &&other) noexcept = delete;
        NavInfo &operator=(const NavInfo &other) const noexcept = delete;
        NavInfo &operator=(NavInfo &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_NAVINFO_HPP
