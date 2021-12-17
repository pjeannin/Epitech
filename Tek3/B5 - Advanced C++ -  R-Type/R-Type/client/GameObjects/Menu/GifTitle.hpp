/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_GIFTITLE_HPP
#define RTYPE_GIFTITLE_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlText.hpp"
#include "client/ECS/SfmlSound.hpp"
#include <unistd.h>
#include <iostream>
#include <vector>

namespace RType::Client::GameObjects {
    class GifTitle : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position> {
    public:
        explicit GifTitle(const RType::ECS::ID &id, const RType::ECS::SfmlDrawable &drawable, const RType::ECS::Position &position) noexcept;
        ~GifTitle() override = default;
        GifTitle(const GifTitle &other) noexcept = delete;
        explicit GifTitle(GifTitle &&other) noexcept = delete;
        GifTitle &operator=(const GifTitle &other) const noexcept = delete;
        GifTitle &operator=(GifTitle &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    private:
        std::vector<int> _clockTab;
        Clock _clock;
    };
}

#endif //RTYPE_GIFTITLE_HPP
