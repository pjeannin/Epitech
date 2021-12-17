/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SFMLDRAWABLE_HPP
#define RTYPE_SFMLDRAWABLE_HPP

#include "shared/ECS/ADrawables.hpp"
#include "SFML/Graphics.hpp"
#include <memory>
namespace RType::ECS {
    class SfmlDrawable : public ADrawables {
        public:
            explicit SfmlDrawable(std::shared_ptr<sf::RenderWindow> window, std::string drawablePath, std::pair<unsigned int, unsigned int> spriteSize, std::pair<unsigned int, unsigned int> ressourceSize, std::pair<unsigned int, unsigned int> offset, std::pair<float, float> scale = std::make_pair(1, 1), float rotation = 0) noexcept;
            ~SfmlDrawable() noexcept override = default;
            SfmlDrawable(const SfmlDrawable &other) noexcept;
            explicit SfmlDrawable(SfmlDrawable &&other) noexcept = delete;
            SfmlDrawable &operator=(const SfmlDrawable &other) const noexcept = delete;
            SfmlDrawable &operator=(SfmlDrawable &&other) const noexcept = delete;
            void draw(const Position &position) noexcept override;
            void moveSprite() noexcept override;
        protected:
            std::shared_ptr<sf::RenderWindow> _window;
            sf::Texture _texture;
            sf::Sprite _sprite;
    };
}

#endif //RTYPE_SFMLDRAWABLE_HPP
