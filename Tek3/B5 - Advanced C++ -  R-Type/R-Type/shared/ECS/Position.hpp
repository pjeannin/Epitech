/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Position Game Object
*/

#ifndef RTYPE_POSITION_HPP
#define RTYPE_POSITION_HPP

#include "IComponent.hpp"

namespace RType::ECS {
    class Position : public IComponent {
        public:
            explicit Position(int const x, int const y) noexcept;
            ~Position() noexcept override = default;
            Position(const Position &pos) noexcept;
            explicit Position(Position &&pos) noexcept = delete;
            Position &operator=(const Position &pos) const noexcept = delete;
            Position &operator=(Position &&pos) const noexcept = delete;

            [[nodiscard]] int getXPos() const noexcept;
            [[nodiscard]] int getYPos() const noexcept;
            void setXPos(int const x) noexcept;
            void setYPos(int const y) noexcept;

        protected:
            int _posX;
            int _posY;
    };
}

#endif //RTYPE_POSITION_HPP
