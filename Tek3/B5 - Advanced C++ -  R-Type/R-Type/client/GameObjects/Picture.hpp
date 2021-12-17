/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_PICTURE_HPP
#define RTYPE_PICTURE_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"

namespace RType::Client::GameObjects {
    class Picture : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position> {
        public:
            explicit Picture(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position) noexcept;
            ~Picture() override = default;
            Picture(const Picture &other) noexcept = delete;
            explicit Picture(Picture &&other) noexcept = delete;
            Picture &operator=(const Picture &other) const noexcept = delete;
            Picture &operator=(Picture &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_PICTURE_HPP
