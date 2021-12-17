/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_VALIDATECREATEROOM_HPP
#define RTYPE_VALIDATECREATEROOM_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"

namespace RType::Client::GameObjects {
    class ValidateCreateRoom : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position> {
    public:
        explicit ValidateCreateRoom(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position) noexcept;
        ~ValidateCreateRoom() override = default;
        ValidateCreateRoom(const ValidateCreateRoom &other) noexcept = delete;
        explicit ValidateCreateRoom(ValidateCreateRoom &&other) noexcept = delete;
        ValidateCreateRoom &operator=(const ValidateCreateRoom &other) const noexcept = delete;
        ValidateCreateRoom &operator=(ValidateCreateRoom &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        void setVisible(bool visible);
        bool getVisible();
    private:
        bool _visible;
    };
}

#endif //RTYPE_VALIDATECREATEROOM_HPP
