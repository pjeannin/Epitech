/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_ASCENE_HPP
#define RTYPE_ASCENE_HPP

#include <vector>
#include "IScene.hpp"

namespace RType::ECS::Scene {
    class AScene : public IScene {
        public:
            explicit AScene(std::shared_ptr<sf::RenderWindow> window) noexcept;
            ~AScene() noexcept override = default;
            [[nodiscard]] std::shared_ptr<RType::ECS::Scene::IScene> &getNextScene() noexcept override;
            void setNextScene(std::shared_ptr<RType::ECS::Scene::IScene> scene) noexcept override;
            [[nodiscard]] std::vector<std::shared_ptr<RType::ECS::IGameObject>> &getGameObjects() noexcept override;
            void update() noexcept override;
            void update(const AEvent &event) noexcept override;
            std::shared_ptr<sf::RenderWindow> &getWindow() noexcept override;

        protected:
            std::shared_ptr<RType::ECS::Scene::IScene> _nextScene;
            std::vector<std::shared_ptr<RType::ECS::IGameObject>> _gameObjects;
            std::shared_ptr<sf::RenderWindow> _window;
    };
}

#endif //RTYPE_ASCENE_HPP
