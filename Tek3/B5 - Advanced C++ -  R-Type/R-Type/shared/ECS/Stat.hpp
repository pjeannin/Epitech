/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Stat
*/

#ifndef RTYPE_STAT_HPP_
#define RTYPE_STAT_HPP_

#include <array>
#include <vector>
#include "IComponent.hpp"

namespace RType::ECS
{
    enum STAT_TYPE
    {
        ATTACK = 0,
        VALUE,
        HEALTH,
        ACCELERATION
    };

    class Stat : public IComponent
    {
    public:
        explicit Stat(STAT_TYPE const type, unsigned int const value = 0) noexcept;
        explicit Stat(std::vector<unsigned int> const &stats) noexcept;
        ~Stat() noexcept override = default;
        Stat(const Stat &other) noexcept;
        explicit Stat(Stat &&other) noexcept = delete;
        Stat &operator=(const Stat &other) const noexcept = delete;
        Stat &operator=(Stat &&other) const noexcept = delete;

        [[nodiscard]] unsigned int getStat(STAT_TYPE const type) const noexcept;
        void setStat(STAT_TYPE const type, unsigned int const value) noexcept;

    private:
        std::array<unsigned int, 4> _stats;
    };
}

#endif