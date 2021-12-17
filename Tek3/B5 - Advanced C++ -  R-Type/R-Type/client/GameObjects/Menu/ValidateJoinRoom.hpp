/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_VALIDATEJOINROOM_HPP
#define RTYPE_VALIDATEJOINROOM_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"

namespace RType::Client::GameObjects {
    class ValidateJoinRoom : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position> {
    public:
        explicit ValidateJoinRoom(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position) noexcept;
        ~ValidateJoinRoom() override = default;
        ValidateJoinRoom(const ValidateJoinRoom &other) noexcept = delete;
        explicit ValidateJoinRoom(ValidateJoinRoom &&other) noexcept = delete;
        ValidateJoinRoom &operator=(const ValidateJoinRoom &other) const noexcept = delete;
        ValidateJoinRoom &operator=(ValidateJoinRoom &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        void setVisible(bool visible);
        bool getVisible();
    private:
        bool _visible;
    };
}
#endif //RTYPE_VALIDATEJOINROOM_HPP
