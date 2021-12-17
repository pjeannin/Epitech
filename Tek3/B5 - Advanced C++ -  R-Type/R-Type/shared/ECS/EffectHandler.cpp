/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Effect handler
*/

#include "EffectHandler.hpp"

#include <iostream>
#include <utility>
#include "Effect.hpp"

RType::ECS::EffectHandler::EffectHandler(std::vector<std::shared_ptr<RType::ECS::ID>> ids, std::vector<std::shared_ptr<RType::IEffect>> effects) noexcept : _ids{std::move(ids)}, _effects{std::move(effects)} {}

RType::ECS::EffectHandler::EffectHandler(const RType::ECS::EffectHandler &other) noexcept : _ids(other.getIds()), _effects(other.getEffects()) { }

void RType::ECS::EffectHandler::loadEffect(const std::shared_ptr<IGameObject> &org, const std::shared_ptr<IGameObject> &oth) const noexcept
{
    ID *id{dynamic_cast<ID *>(oth.get())};
    if (nullptr == id)
        return;
    for (unsigned int it = 0, et = _ids.size(); et > it; ++it)
        if (_ids[it].get()->getId() == id->getId())
            _effects[it].get()->castEffect(org, oth);
}

void RType::ECS::EffectHandler::addEffect(const ID &id, const std::shared_ptr<RType::IEffect> &effect) noexcept
{
    for (unsigned int it = 0, et = _ids.size(); et > it; ++it)
        if (_ids[it].get()->getId() == id.getId())
        {
            _effects[it].reset();
            _effects[it] = effect;
            return;
        }
    _ids.emplace_back(std::make_shared<RType::ECS::ID>(id));
    _effects.emplace_back(effect);
}

void RType::ECS::EffectHandler::removeEffect(const ID &id) noexcept
{
    for (unsigned int it = 0, et = _ids.size(); et > it; ++it)
        if (_ids[it].get()->getId() == id.getId())
        {
            _ids.erase(_ids.begin() + it);
            _effects.erase(_effects.begin() + it);
        }
}

std::vector<std::shared_ptr<RType::ECS::ID>> RType::ECS::EffectHandler::getIds() const noexcept
{
    return (_ids);
}

std::vector<std::shared_ptr<RType::IEffect>> RType::ECS::EffectHandler::getEffects() const noexcept
{
    return (_effects);
}
