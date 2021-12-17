/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Effects header
*/

#ifndef RTYPE_EFFECT_HPP
#define RTYPE_EFFECT_HPP

#include "IEffect.hpp"

namespace RType
{
    class RegenHealth : public IEffect
    {
    public:
        RegenHealth() = default;
        ~RegenHealth() override = default;
        void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept override;
    };

    class IncreaseDamage : public IEffect
    {
    public:
        IncreaseDamage() = default;
        ~IncreaseDamage() override = default;
        void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept override;
    };

    class DecreaseDamage : public IEffect
    {
    public:
        DecreaseDamage() = default;
        ~DecreaseDamage() override = default;
        void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept override;
    };

    class SlowSpeed : public IEffect
    {
    public:
        SlowSpeed() = default;
        ~SlowSpeed() override = default;
        void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept override;
    };

    class DamageBoth : public IEffect
    {
    public:
        DamageBoth() = default;
        ~DamageBoth() override = default;
        void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept override;
    };

    class Kill : public IEffect
    {
    public:
        Kill() = default;
        ~Kill() override = default;
        void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept override;
    };

    class DamageAndDestroyItself : public IEffect
    {
    public:
        DamageAndDestroyItself() = default;
        ~DamageAndDestroyItself() override = default;
        void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept override;
    };

    class IncreaseSpeed : public IEffect
    {
    public:
        IncreaseSpeed() = default;
        ~IncreaseSpeed() override = default;
        void castEffect(const std::shared_ptr<ECS::IGameObject> &org, const   std::shared_ptr<ECS::IGameObject> &oth) const noexcept override;
    };
}

#endif