/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_WEAPONHOLDER_HPP
#define RTYPE_WEAPONHOLDER_HPP

#include <memory>
#include "IComponent.hpp"
#include "IWeapon.hpp"

namespace RType::ECS
{
    class WeaponHolder : public IComponent
    {
    public:
        explicit WeaponHolder(std::shared_ptr<IWeapon> weapon = nullptr, unsigned int const damage = 1) noexcept;
        ~WeaponHolder() noexcept override = default;
        WeaponHolder(const WeaponHolder &other) noexcept;
        explicit WeaponHolder(WeaponHolder &&other) noexcept = delete;
        WeaponHolder &operator=(const WeaponHolder &other) const noexcept = delete;
        WeaponHolder &operator=(WeaponHolder &&other) const noexcept = delete;
        [[nodiscard]] bool hasWeapon() const noexcept;
        [[nodiscard]] const std::shared_ptr<RType::ECS::IWeapon> &getWeapon() const noexcept;
        [[nodiscard]] unsigned int getDamage() const noexcept;
        void setWeapon(std::shared_ptr<IWeapon> const &weapon) noexcept;
        void setDamage(unsigned int const damage) noexcept;
        void shot() const noexcept;

    protected:
        std::shared_ptr<IWeapon> _weapon;
        unsigned int _damage;
    };
}

#endif //RTYPE_WEAPONHOLDER_HPP
