/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Stat
*/

#include "Stat.hpp"

RType::ECS::Stat::Stat(STAT_TYPE const type, unsigned int const value) noexcept
{
    _stats.fill(0);
    _stats[type] = value;
}

RType::ECS::Stat::Stat(std::vector<unsigned int> const &stats) noexcept
{
    _stats.fill(0);
    for (unsigned int i = 0, et = stats.size(); et > i && 4 > i; ++i)
        _stats[i] = stats[i];
}

unsigned int RType::ECS::Stat::getStat(STAT_TYPE const type) const noexcept
{
    return _stats[type];
}

void RType::ECS::Stat::setStat(STAT_TYPE const type, unsigned int const value) noexcept
{
    _stats[type] = value;
}
