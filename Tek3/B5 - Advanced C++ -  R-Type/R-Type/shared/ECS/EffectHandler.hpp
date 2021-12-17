
/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Effect handler header
*/

#ifndef RTYPE_EVENT_HPP
#define RTYPE_EVENT_HPP

#include "shared/ECS/IComponent.hpp"
#include "shared/ECS/IGameObject.hpp"
#include "shared/ECS/Id.hpp"
#include "IEffect.hpp"

namespace RType::ECS
{
    class EffectHandler : public IComponent
    {
    public:
        explicit EffectHandler(std::vector<std::shared_ptr<RType::ECS::ID>> ids = {}, std::vector<std::shared_ptr<RType::IEffect>> effects = {}) noexcept;
        ~EffectHandler() noexcept override = default;
        EffectHandler(const EffectHandler &other) noexcept;
        explicit EffectHandler(EffectHandler &&other) noexcept = delete;
        EffectHandler &operator=(const EffectHandler &other) const noexcept = delete;
        EffectHandler &operator=(EffectHandler &&other) const noexcept = delete;
        [[nodiscard]] std::vector<std::shared_ptr<RType::ECS::ID>> getIds() const noexcept;
        [[nodiscard]] std::vector<std::shared_ptr<RType::IEffect>> getEffects() const noexcept;

        void loadEffect(const std::shared_ptr<IGameObject> &org, const std::shared_ptr<IGameObject> &oth) const noexcept;
        void addEffect(const ID &id, const std::shared_ptr<RType::IEffect> &effect) noexcept;
        void removeEffect(const ID &id) noexcept;

    private:
        //std::vector<std::pair<RType::ECS::ID, std::shared_ptr<RType::IEffect>>> _effects;
        std::vector<std::shared_ptr<RType::ECS::ID>> _ids;
        std::vector<std::shared_ptr<RType::IEffect>> _effects;
    };
}

#endif