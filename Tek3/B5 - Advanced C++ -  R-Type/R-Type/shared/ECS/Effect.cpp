/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Effects
*/

#include "Effect.hpp"
#include "shared/ECS/Stat.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/WeaponHolder.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/ECS/State.hpp"

void RType::RegenHealth::castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept
{
    ECS::Stat *stat{dynamic_cast<ECS::Stat *>(org.get())};
    ECS::Health *health{dynamic_cast<ECS::Health *>(oth.get())};
    if (nullptr == stat || nullptr == health)
        return;
    health->addHealth(stat->getStat(ECS::STAT_TYPE::HEALTH));
}

void RType::IncreaseDamage::castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept
{
    ECS::Stat *stat{dynamic_cast<ECS::Stat *>(org.get())};
    ECS::WeaponHolder *weapon{dynamic_cast<ECS::WeaponHolder *>(oth.get())};
    if (nullptr == stat || nullptr == weapon)
        return;
    weapon->setDamage(weapon->getDamage() + stat->getStat(ECS::STAT_TYPE::ATTACK));
}

void RType::DecreaseDamage::castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept
{
    ECS::Stat *stat{dynamic_cast<ECS::Stat *>(org.get())};
    ECS::WeaponHolder *weapon{dynamic_cast<ECS::WeaponHolder *>(oth.get())};
    if (nullptr == stat || nullptr == weapon)
        return;
    weapon->setDamage(weapon->getDamage() - stat->getStat(ECS::STAT_TYPE::ATTACK));
}

void RType::SlowSpeed::castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept
{
    ECS::Stat *stat{dynamic_cast<ECS::Stat *>(org.get())};
    ECS::Acceleration *acceleration{dynamic_cast<ECS::Acceleration *>(oth.get())};
    if (nullptr == stat || nullptr == acceleration)
        return;
    acceleration->setXAcceleration(acceleration->getXAcceleration() - stat->getStat(ECS::ACCELERATION));
}

void RType::DamageBoth::castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept
{
    ECS::Stat *stat{dynamic_cast<ECS::Stat *>(org.get())};
    ECS::Health *orgHealth{dynamic_cast<ECS::Health *>(org.get())}, *othHealth{dynamic_cast<ECS::Health *>(oth.get())};
    if (nullptr == stat || nullptr == orgHealth || nullptr == othHealth)
        return;
    othHealth->removeHealth(stat->getStat(ECS::STAT_TYPE::ATTACK));
    orgHealth->removeHealth(stat->getStat(ECS::STAT_TYPE::ATTACK));
}

void RType::Kill::castEffect(const std::shared_ptr<ECS::IGameObject> &org __attribute__((unused)), const std::shared_ptr<ECS::IGameObject> &oth) const noexcept
{
    ECS::Health *health{dynamic_cast<ECS::Health *>(oth.get())};
    if (nullptr == health)
    {
        ECS::State *state{dynamic_cast<ECS::State *>(oth.get())};
        if (nullptr == state)
            return;
        state->setState(true);
    }
    else
        health->removeHealth(health->getHealth());
}

void RType::DamageAndDestroyItself::castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept
{
    ECS::Stat *stat{dynamic_cast<ECS::Stat *>(org.get())};
    ECS::Health *othHealth{dynamic_cast<ECS::Health *>(oth.get())}, *orgHealth{dynamic_cast<ECS::Health *>(org.get())};
    if (nullptr == othHealth || nullptr == stat)
        return;
    if (nullptr == orgHealth)
    {
        ECS::State *state{dynamic_cast<ECS::State *>(org.get())};
        if (nullptr == state)
            return;
        state->setState(true);
    }
    else
        othHealth->removeHealth(stat->getStat(ECS::STAT_TYPE::ATTACK));
}

void RType::IncreaseSpeed::castEffect(const std::shared_ptr<ECS::IGameObject> &org, const std::shared_ptr<ECS::IGameObject> &oth) const noexcept
{
    ECS::Stat *stat{dynamic_cast<ECS::Stat *>(org.get())};
    ECS::Acceleration *acceleration{dynamic_cast<ECS::Acceleration *>(oth.get())};
    if (nullptr == stat || nullptr == acceleration)
        return;
    acceleration->setXAcceleration(acceleration->getXAcceleration() + stat->getStat(ECS::ACCELERATION));
}