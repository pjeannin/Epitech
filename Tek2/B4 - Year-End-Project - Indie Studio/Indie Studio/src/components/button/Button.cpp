#include "Button.hpp"
#include "src/utils/Utils.hpp"
#include "../../../raylib-cpp/src/mouse/Mouse.hpp"

#include <iostream>

Bomberman::Button::Button(std::string const &texture_, unsigned char const nbFrames) noexcept :
    texture(new raylib::Texture(texture_)), frameHeight(frameHeight = (float)texture->height / nbFrames),
    sourceRect(0, 0, (float)texture->width, frameHeight), action(false), state(0), hover(false),
    loadedInClass(true)
{}

Bomberman::Button::Button(raylib::Texture *texture_, unsigned char const nbFrames) noexcept :
    texture(texture_), frameHeight(frameHeight = (float)texture->height / nbFrames),
    sourceRect(0, 0, (float)texture->width, frameHeight), action(false), state(0), hover(false),
    loadedInClass(true)
{}

Bomberman::Button::Button() noexcept :
    frameHeight(0), sourceRect(0, 0, 0, 0),
    action(false), state(0), hover(false), loadedInClass(false)
{}

void Bomberman::Button::loadTexture(std::string const &path, unsigned char const nbFrames) noexcept
{
    if (loadedInClass && texture)
        delete texture;
    texture = new raylib::Texture(windowsPath(path));
    frameHeight = (float)texture->height / (float)nbFrames;
    sourceRect = raylib::Rectangle(0, 0, (float)texture->width, frameHeight);
    loadedInClass = true;
}

void Bomberman::Button::draw(raylib::Vector2 const &pos, raylib::Color const &color) const noexcept
{
    texture->Draw(sourceRect, pos, color);
}

void Bomberman::Button::draw(raylib::Color const &color) noexcept
{
    texture->Draw(sourceRect, raylib::Vector2(bounds.x, bounds.y), color);
}

bool Bomberman::Button::check(std::function<void(Button &button)> onClick, std::function<void(Button &button)> onHover, std::function<bool(Button &button)> isNotDisabled) noexcept
{
    if (raylib::Mouse::getPosition().checkCollision(bounds) && isNotDisabled(*this)) {
        if (!hover) {
            hover = true;
            onHover(*this);
        }
        if (raylib::Mouse::IsButtonDown(MOUSE_LEFT_BUTTON))
            state = 2;
        else
            state = 1;
        if (raylib::Mouse::IsButtonReleased(MOUSE_LEFT_BUTTON)) {
            onClick(*this);
        }
    } else {
        hover = false;
        state = 0;
    }
    sourceRect.y = (float)state * frameHeight;
    return false;
}

void Bomberman::Button::reset() noexcept
{
    action = false;
}

void Bomberman::Button::loadTexture(raylib::Texture *texture_, unsigned char const nbFrames) noexcept
{
    if (loadedInClass && texture)
        delete texture;
    texture = texture_;
    frameHeight = (float)texture->height / (float)nbFrames;
    sourceRect = raylib::Rectangle(0, 0, (float)texture->width, frameHeight);
    loadedInClass = false;
}
