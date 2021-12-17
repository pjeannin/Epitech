/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Clock header
*/

#ifndef CLOCK_HPP
    #define CLOCK_HPP

    #include <chrono>
    #include <vector>
    #include <iostream>
    class Clock {
        public:
            explicit Clock(int nb) noexcept;
            ~Clock() noexcept = default;
            Clock(const Clock &pos) noexcept = delete;
            explicit Clock(Clock &&pos) noexcept = delete;
            Clock &operator=(const Clock &pos) const noexcept = delete;
            Clock &operator=(Clock &&pos) const noexcept = delete;
            void setNextMoment(std::vector<int>) noexcept;
            [[nodiscard]]int numberOfRep(int) noexcept;
            void deleteElem(int) noexcept;
            void addElem(int) noexcept;
        private:
            std::vector<std::time_t> _prevMoment;
            std::vector<int> _nextMomentIn;
    };

#endif