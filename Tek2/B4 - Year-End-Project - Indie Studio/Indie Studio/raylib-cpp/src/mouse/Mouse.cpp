#include "Mouse.hpp"

bool raylib::Mouse::IsButtonPressed(int const button) noexcept 
{
    return ::IsMouseButtonPressed(button);
}

bool raylib::Mouse::IsButtonDown(int const button) noexcept 
{
    return ::IsMouseButtonDown(button);
}

bool raylib::Mouse::IsButtonReleased(int const button) noexcept 
{
    return ::IsMouseButtonReleased(button);
}

bool raylib::Mouse::IsButtonUp(int const button) noexcept 
{
    return ::IsMouseButtonUp(button);
}

int raylib::Mouse::getX() noexcept 
{
    return ::GetMouseX();
}

int raylib::Mouse::getY() noexcept 
{
    return ::GetMouseY();
}

void raylib::Mouse::SetX(int const x) noexcept 
{
    ::SetMousePosition(x, getY());
}

void raylib::Mouse::SetY(int const y) noexcept 
{
    ::SetMousePosition(getX(), y);
}

raylib::Vector2 raylib::Mouse::getPosition() noexcept 
{
    return ::GetMousePosition();
}

void raylib::Mouse::setPosition(int const x, int const y) noexcept 
{
    ::SetMousePosition(x, y);
}

void raylib::Mouse::setOffset(int const offsetX, int const offsetY) noexcept 
{
    ::SetMouseOffset(offsetX, offsetY);
}

void raylib::Mouse::setScale(float const scaleX, float const scaleY) noexcept 
{
    ::SetMouseScale(scaleX, scaleY);
}

float raylib::Mouse::getWheelMove() noexcept 
{
    return ::GetMouseWheelMove();
}

void raylib::Mouse::setCursor(int const cursor) noexcept 
{
    ::SetMouseCursor(cursor);
}

int raylib::Mouse::getTouchX() noexcept 
{
    return ::GetTouchX();
}

int raylib::Mouse::getTouchY() noexcept 
{
    return ::GetTouchY();
}

raylib::Vector2 raylib::Mouse::getTouchPosition(int const index) noexcept 
{
    return ::GetTouchPosition(index);
}
