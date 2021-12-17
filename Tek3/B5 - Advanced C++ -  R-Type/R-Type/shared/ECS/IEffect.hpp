
/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Effect interface
*/

#ifndef RTYPE_IEFFECT_HPP
#define RTYPE_IEFFECT_HPP

#include <memory>
#include "shared/ECS/IGameObject.hpp"

namespace RType
{
    class IEffect
    {
    public:
        virtual ~IEffect() noexcept = default;
        virtual void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept = 0;
    };
}

#endif