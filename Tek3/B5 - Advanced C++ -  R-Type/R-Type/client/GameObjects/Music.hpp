/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_MUSIC_HPP
#define RTYPE_MUSIC_HPP

#include "shared/ECS/GameObject.hpp"
#include "client/ECS/SfmlMusic.hpp"
#include "shared/ECS/Id.hpp"

namespace RType::Client::GameObjects {
    class Music : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlMusic>  {
        public:
            explicit Music(RType::ECS::ID id, RType::ECS::SfmlMusic music) noexcept;
            ~Music() override = default;
            Music(const Music &other) noexcept = delete;
            explicit Music(Music &&other) noexcept = delete;
            Music &operator=(const Music &other) const noexcept = delete;
            Music &operator=(Music &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        private:
            bool _isPlaying;
    };
}

#endif //RTYPE_MUSIC_HPP
