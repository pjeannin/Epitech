/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_ATEXT_HPP
#define RTYPE_ATEXT_HPP

#include "Position.hpp"
#include <SFML/Graphics.hpp>

namespace RType::ECS {
    class AText : public IComponent {
        public :
            explicit AText(std::string text, unsigned short size) noexcept;
            ~AText() noexcept override = default;
            AText(const AText &other) noexcept;
            explicit AText(AText &&other) noexcept = delete;
            AText &operator=(const AText &other) const noexcept = delete;
            AText &operator=(AText &&other) const noexcept = delete;
            virtual void draw(const Position &position) noexcept = 0;
            [[nodiscard]] const std::string &getText() const noexcept;
            void setText(const std::string&) noexcept;
            [[nodiscard]] unsigned short getSize() const noexcept;
        private :
            std::string _text;
            unsigned short _size;
    };
}


#endif //RTYPE_ATEXT_HPP
