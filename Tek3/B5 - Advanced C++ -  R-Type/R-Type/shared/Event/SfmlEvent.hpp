/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SFMLEVENT_HPP
#define RTYPE_SFMLEVENT_HPP

#include "AEvent.hpp"
#include "SFML/Graphics.hpp"
#include <memory>
#include "SFML/Window/Joystick.hpp"

namespace RType {
    class SfmlEvent : public AEvent {
        public:
            explicit SfmlEvent(std::shared_ptr<sf::RenderWindow>  window) noexcept;
            ~SfmlEvent() noexcept override = default;
            SfmlEvent(const SfmlEvent &other) noexcept = delete;
            explicit SfmlEvent(SfmlEvent &&other) noexcept = delete;
            SfmlEvent &operator=(const SfmlEvent &other) const noexcept = delete;
            SfmlEvent &operator=(SfmlEvent &&other) const noexcept = delete;
            void update() noexcept override;
            void keyboard(const sf::Event &event) noexcept;
            void keyboardR(const sf::Event &event) noexcept;
        private:
            std::shared_ptr<sf::RenderWindow> _window;
            std::vector<sf::Keyboard::Key> _keys;
    };
}


#endif //RTYPE_SFMLEVENT_HPP
