/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_ADRAWABLES_HPP
#define RTYPE_ADRAWABLES_HPP

#include <string>
#include "Position.hpp"
#include "../Clock/clock.hpp"

namespace RType::ECS {
    class ADrawables : public IComponent {
        public:
            explicit ADrawables(std::string drawablePath, std::pair<unsigned int, unsigned int> spriteSize, std::pair<unsigned int, unsigned int> ressourceSize, std::pair<unsigned int, unsigned int> offset, std::pair<float, float> scale, float rotation) noexcept;
            ~ADrawables() noexcept override = default;
            ADrawables(const ADrawables &other) noexcept;
            explicit ADrawables(ADrawables &&other) noexcept = delete;
            ADrawables &operator=(const ADrawables &other) const noexcept = delete;
            ADrawables &operator=(ADrawables &&other) const noexcept = delete;
            [[nodiscard]] const std::string &getDrawablePath() const noexcept;
            [[nodiscard]] const std::pair<unsigned int, unsigned int> &getOffset() const noexcept;
            [[nodiscard]] const std::pair<unsigned int, unsigned int> &getSpriteSize() const noexcept;
            [[nodiscard]] const std::pair<float, float> &getScale() const noexcept;
            void setOffset(std::pair<unsigned int, unsigned int> const &offset) noexcept;
            virtual void draw(const Position &position) noexcept = 0;
            virtual void moveSprite() noexcept = 0;
    protected:
        std::string _drawablePath;
        std::pair<unsigned int, unsigned int> _offset;
        std::pair<unsigned int, unsigned int> _spriteSize;
        std::pair<float, float> _scale;
        std::pair<unsigned int, unsigned int> _ressourceSize;
        float _rotation;
    };
}

#endif //RTYPE_ADRAWABLES_HPP
