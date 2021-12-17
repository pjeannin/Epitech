/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_DAMMAGE_HPP
#define RTYPE_DAMMAGE_HPP

#include "shared/ECS/IComponent.hpp"
#include "shared/ECS/IGameObject.hpp"
#include "shared/ECS/Id.hpp"
#include "IEffect.hpp"

namespace RType::ECS
{
    class Dammage : public IComponent
    {
    public:
        explicit Dammage(int damage) noexcept;
        ~Dammage() noexcept override = default;
        Dammage(const Dammage &other) noexcept;
        explicit Dammage(Dammage &&other) noexcept = delete;
        Dammage &operator=(const Dammage &other) const noexcept = delete;
        Dammage &operator=(Dammage &&other) const noexcept = delete;

        [[nodiscard]] int getDamage() const noexcept;
        void setDamage(int const damage) noexcept;

    protected:
        int _damage;
    };
}

#endif //RTYPE_DAMMAGE_HPP
