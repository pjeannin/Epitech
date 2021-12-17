/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SFMLTEXT_HPP
#define RTYPE_SFMLTEXT_HPP

#include <SFML/Graphics.hpp>
#include "shared/ECS/AText.hpp"

namespace RType::ECS {
    class SfmlText : public AText {
    public:
        SfmlText(std::shared_ptr<sf::RenderWindow> window, std::string const &text, sf::Font const &font, unsigned int size, sf::Color const &color) noexcept;
        ~SfmlText() noexcept override = default;
        SfmlText(const SfmlText &other) noexcept;
        explicit SfmlText(SfmlText &&other) noexcept = delete;
        SfmlText &operator=(const SfmlText &other) const noexcept = delete;
        SfmlText &operator=(SfmlText &&other) const noexcept = delete;
        void setText(const std::string&) noexcept;
        void draw(const Position &position) noexcept override;

    protected:
        std::shared_ptr<sf::RenderWindow> _window;
        std::string _text;
        sf::Color _color;
        sf::Font _font;
        unsigned int _size;
        sf::Text _drawableText;
    };
}

#endif //RTYPE_SFMLTEXT_HPP
