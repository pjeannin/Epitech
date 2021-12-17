/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_HITBOX_HPP
#define RTYPE_HITBOX_HPP

#include <utility>
#include "Position.hpp"

namespace RType::ECS
{
    class HitBox : public IComponent
    {
    public:
        explicit HitBox(unsigned int const width, unsigned int const height, std::pair<int, int> offset = {0, 0}) noexcept;
        ~HitBox() noexcept override = default;
        HitBox(const HitBox &other) noexcept;
        explicit HitBox(HitBox &&other) noexcept = delete;
        HitBox &operator=(const HitBox &other) const noexcept = delete;
        HitBox &operator=(HitBox &&other) const noexcept = delete;

        [[nodiscard]] unsigned int getWidth() const noexcept;
        [[nodiscard]] unsigned int getHeight() const noexcept;
        void setWidth(unsigned int const width) noexcept;
        void setHeight(unsigned int const height) noexcept;
        [[nodiscard]] std::pair<int, int> getOffset() const noexcept;
        [[nodiscard]] bool isColliding(const RType::ECS::Position &position, std::pair<int, int> point) const noexcept;
        [[nodiscard]] bool isColliding(const RType::ECS::Position &position, const RType::ECS::HitBox &HitBox, const RType::ECS::Position &otherPostion) const noexcept;

    protected:
        unsigned int _width;
        unsigned int _height;
        std::pair<int, int> _offset;
    };
}

#endif //RTYPE_HITBOX_HPP
