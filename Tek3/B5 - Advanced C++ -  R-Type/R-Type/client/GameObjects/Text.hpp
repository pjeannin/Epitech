/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_TEXT_HPP
#define RTYPE_TEXT_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlText.hpp"
#include <iostream>
#include <vector>
#include "client/ECS/SfmlSound.hpp"

namespace RType::Client::GameObjects {
    class Text : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::SfmlText>  {
    public:
        explicit Text(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText text, bool visible = true) noexcept;
        ~Text() override = default;
        Text(const Text &other) noexcept = delete;
        explicit Text(Text &&other) noexcept = delete;
        Text &operator=(const Text &other) const noexcept = delete;
        Text &operator=(Text &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        void setVisible(bool visible);
        bool getVisible();
    private:
        bool _visible;
    };
}

#endif //RTYPE_TEXT_HPP
