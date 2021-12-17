/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SCORE_HPP
#define RTYPE_SCORE_HPP

#include "IComponent.hpp"

namespace RType::ECS {
    class Score : public IComponent {
        public:
            explicit Score(unsigned int const startingScore = 0) noexcept;
            ~Score() noexcept override = default;
            Score(const Score &other) noexcept;
            explicit Score(Score &&other) noexcept = delete;
            Score &operator=(const Score &other) const noexcept = delete;
            Score &operator=(Score &&other) const noexcept = delete;
            [[nodiscard]] unsigned int getScore() const noexcept;
            void setScore(unsigned int const score) noexcept;
            void addToScore(unsigned int const toAdd) noexcept;

        protected:
            unsigned int _score;
    };
}

#endif //RTYPE_SCORE_HPP
