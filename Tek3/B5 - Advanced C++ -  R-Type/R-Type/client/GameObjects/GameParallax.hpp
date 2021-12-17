/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_GAMEPARALLAX_HPP
#define RTYPE_GAMEPARALLAX_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlText.hpp"
#include "client/ECS/SfmlSound.hpp"
#include <unistd.h>
#include <iostream>
#include <vector>

namespace RType::Client::GameObjects {
    class GameParallax: public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position, RType::ECS::Acceleration> {
    public:
        explicit GameParallax(const RType::ECS::ID &id, const RType::ECS::SfmlDrawable &drawable, const RType::ECS::Position &position, const RType::ECS::Acceleration &acceleration) noexcept;
        ~GameParallax() override = default;
        GameParallax(const GameParallax &other) noexcept = delete;
        explicit GameParallax(GameParallax &&other) noexcept = delete;
        GameParallax &operator=(const GameParallax &other) const noexcept = delete;
        GameParallax &operator=(GameParallax &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    private:
        std::vector<int> _clockTab;
        Clock _clock;
    };
}

#endif //RTYPE_GAMEPARALLAX_HPP
