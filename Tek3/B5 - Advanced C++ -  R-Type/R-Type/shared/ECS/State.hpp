/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** State header
*/

#ifndef RTYPE_STATE_HPP
#define RTYPE_STATE_HPP

#include "IComponent.hpp"

namespace RType::ECS
{
    class State : public IComponent
    {
    public:
        explicit State() noexcept;
        ~State() noexcept override = default;
        State(const State &other) noexcept;
        explicit State(State &&other) noexcept = delete;
        State &operator=(const State &other) const noexcept = delete;
        State &operator=(State &&other) const noexcept = delete;

        [[nodiscard]] bool getState() const noexcept;
        void setState(bool const state) noexcept;

    private:
        bool _destroyed;
    };
}

#endif