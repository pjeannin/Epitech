/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** bomberman
*/


#include "Fade.hpp"

Bomberman::Transition::Fade::Fade() noexcept : val(0), isRunning(false), _black(raylib::Color::Black())
{

}

void Bomberman::Transition::Fade::startTransition(float const transitionVal) noexcept
{
    val = transitionVal;
    isRunning = true;
    _startD = GetTime();
}

bool Bomberman::Transition::Fade::isTransitionRunning() noexcept
{
    return isRunning;
}

bool Bomberman::Transition::Fade::isTransitionDone() noexcept
{
    return isRunning && val > 1 && (GetTime() - _startD) >= 1.5;
}

void Bomberman::Transition::Fade::draw(Core &core) noexcept
{
    _black.Fade(val).DrawRectangle(0, 0, core.screenSize.x, core.screenSize.y + 300);
}

void Bomberman::Transition::Fade::stop() noexcept
{
    isRunning = false;
}

void Bomberman::Transition::Fade::update() noexcept
{
    if (isRunning && val < 1)
        val += 0.02;
    if (!isRunning && val > 0)
        val -= 0.02;
}
