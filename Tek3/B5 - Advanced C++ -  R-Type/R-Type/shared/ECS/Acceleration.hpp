/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Acceleration
*/

#ifndef RTYPE_ACCELERATION_HPP
#define RTYPE_ACCELERATION_HPP

#include "IComponent.hpp"

namespace RType::ECS {
    class Acceleration : public IComponent {
        public:
            explicit Acceleration(int const x, int const y) noexcept;
            ~Acceleration() noexcept override = default;
            Acceleration(const Acceleration &other) noexcept;
            explicit Acceleration(Acceleration &&other) noexcept = delete;
            Acceleration &operator=(const Acceleration &other) const noexcept = delete;
            Acceleration &operator=(Acceleration &&other) const noexcept = delete;

            [[nodiscard]] int getXAcceleration() const noexcept;
            [[nodiscard]] int getYAcceleration() const noexcept;
            void setXAcceleration(int const x) noexcept;
            void setYAcceleration(int const y) noexcept;
        protected:
            int _accelerationX;
            int _accelerationY;
    };
}

#endif //RTYPE_ACCELERATION_HPP
