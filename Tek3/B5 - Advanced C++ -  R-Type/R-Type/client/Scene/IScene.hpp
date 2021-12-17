/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_ISCENE_HPP
#define RTYPE_ISCENE_HPP

#include <SFML/Graphics.hpp>
#include "shared/ECS/IGameObject.hpp"
#include "shared/Event/AEvent.hpp"
#include "shared/ECS/IManager.hpp"

namespace RType::ECS {
        class IGameObject;
    namespace Scene {
    class IScene : public RType::ECS::IManager {
        public:
            virtual ~IScene() noexcept = default;
            [[nodiscard]] virtual std::shared_ptr<RType::ECS::Scene::IScene> &getNextScene() noexcept = 0;
            virtual void setNextScene(std::shared_ptr<RType::ECS::Scene::IScene> scene) noexcept = 0;
            void update() noexcept override = 0;
            virtual void update(const AEvent &event) noexcept = 0;
            [[nodiscard]] virtual std::shared_ptr<sf::RenderWindow> &getWindow() noexcept = 0;
        };
    }
}

#endif //RTYPE_ISCENE_HPP
