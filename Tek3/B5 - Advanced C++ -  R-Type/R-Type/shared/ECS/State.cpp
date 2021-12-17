/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** State
*/

#include "State.hpp"

bool RType::ECS::State::getState() const noexcept { return _destroyed; };

void RType::ECS::State::setState(bool const state) noexcept { _destroyed = state; };

RType::ECS::State::State(const RType::ECS::State &other) noexcept : _destroyed(std::move(other.getState())) {}

RType::ECS::State::State() noexcept : _destroyed(false) {}