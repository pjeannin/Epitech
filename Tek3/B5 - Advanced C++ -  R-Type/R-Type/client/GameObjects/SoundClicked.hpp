/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SOUNDCLICKED_HPP
#define RTYPE_SOUNDCLICKED_HPP

#include "shared/ECS/GameObject.hpp"
#include "client/ECS/SfmlSound.hpp"
#include "shared/ECS/Id.hpp"

namespace RType::Client::GameObjects {
    class SoundClicked : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlSound>  {
    public:
        explicit SoundClicked(RType::ECS::ID id, RType::ECS::SfmlSound sound) noexcept;
        ~SoundClicked() override = default;
        SoundClicked(const SoundClicked &other) noexcept = delete;
        explicit SoundClicked(SoundClicked &&other) noexcept = delete;
        SoundClicked &operator=(const SoundClicked &other) const noexcept = delete;
        SoundClicked &operator=(SoundClicked &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_SOUNDCLICKED_HPP
