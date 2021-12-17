/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_AEVENT_HPP
#define RTYPE_AEVENT_HPP

#include <utility>
#include <vector>

#define KEY_NUMBER 49

namespace RType {
    class AEvent {
        public:
            enum Key {UP, DOWN, LEFT, RIGHT, SPACE, ENTER, ESC, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, POINT, REMOVE, UP_RELEASE, DOWN_RELEASE, LEFT_RELEASE, RIGHT_RELEASE};
            struct Controller {
                float JoystickX;
                float JoystickY;
                bool buttonA;
                bool buttonB;
            };
            explicit AEvent() noexcept;
            virtual ~AEvent() noexcept = default;
            AEvent(const AEvent &other) noexcept = delete;
            explicit AEvent(AEvent &&other) noexcept = delete;
            AEvent &operator=(const AEvent &other) const noexcept = delete;
            AEvent &operator=(AEvent &&other) const noexcept = delete;
            [[nodiscard]] const std::vector<bool> &getKeyEvent() const noexcept;
            [[nodiscard]] const Controller &getControllerEvent() const noexcept;
            bool isControllerPlugged() const noexcept;
            virtual void update() noexcept {};
        protected:
            void resetEvents() noexcept;
            std::vector<bool> _keyEvent;
            Controller _controllerEvent;
            bool _controller;
    };
}

#endif //RTYPE_AEVENT_HPP
