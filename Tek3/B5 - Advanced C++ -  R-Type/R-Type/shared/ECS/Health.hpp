/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_HEALTH_HPP
#define RTYPE_HEALTH_HPP

#include "IComponent.hpp"

namespace RType::ECS {
    class Health : public IComponent {
        public:
            explicit Health(unsigned short const defaultHealth) noexcept;
            ~Health() noexcept override = default;
            Health(const Health &other) noexcept;
            explicit Health(Health &&other) noexcept = delete;
            Health &operator=(const Health &other) const noexcept = delete;
            Health &operator=(Health &&other) const noexcept = delete;
            [[nodiscard]] int getHealth() const noexcept;
            [[nodiscard]] int getDefaultHealth() const noexcept;
            void removeHealth(unsigned short const toRemove) noexcept;
            void addHealth(unsigned short const toAdd) noexcept;
            void setHealth(unsigned short const health) noexcept;
        protected:
            unsigned short _health;
            unsigned short _defaultHealth;
    };
}


#endif //RTYPE_HEALTH_HPP
