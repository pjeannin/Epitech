/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Weapon Interface
*/

#ifndef BABEL_IWEAPON_HPP
#define BABEL_IWEAPON_HPP

#include "IGameObject.hpp"

namespace RType::ECS {
    class IWeapon {
    public:
        virtual const IGameObject &shot() noexcept = 0;
    };
}

#endif //BABEL_IWEAPON_HPP
