/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** bomberman
*/

#ifndef BOMBERMAN_FADE_HPP
#define BOMBERMAN_FADE_HPP

#include "../../../../raylib-cpp/src/color/Color.hpp"
#include "../../../core/Core.hpp"

namespace Bomberman {
    namespace Transition {
        class Fade {
        public:
            explicit Fade() noexcept;

            void update() noexcept;
            void draw(Core &core) noexcept;
            void startTransition(float const transitionVal = 1) noexcept;
            void stop() noexcept;
            bool isTransitionRunning() noexcept;
            bool isTransitionDone() noexcept;
            float val;
            bool isRunning;
        private:
            raylib::Color _black;
            double _startD;
        };
    }
}
#endif //BOMBERMAN_FADE_HPP
