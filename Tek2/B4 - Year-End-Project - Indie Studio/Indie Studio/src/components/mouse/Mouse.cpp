/*
** EPITECH PROJECT, 2021
** Mouse
** File description:
** Mouse
*/
#include "Mouse.hpp"
#include "../../../raylib-cpp/src/color/Color.hpp"

Mouse::Mouse() noexcept : cursor("resources/images/cursor.png")
{
    ::DisableCursor();
}

void Mouse::draw() noexcept
{
    raylib::Vector2 const cursorPos = raylib::Mouse::getPosition() - 10;
    if (cursorPos.x > 1920)
        setPosition(1920, cursorPos.y);
    if (cursorPos.x < 0)
        setPosition(0, cursorPos.y);
    if (cursorPos.y < 0)
        setPosition(cursorPos.x, 0);
    if (cursorPos.y > 1080)
        setPosition(cursorPos.x, 1080);
    cursor.Draw(cursorPos, 0, 1, raylib::Color::RayWhite());
}
