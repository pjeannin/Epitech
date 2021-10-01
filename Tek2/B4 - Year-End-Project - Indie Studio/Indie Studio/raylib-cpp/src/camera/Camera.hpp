/*
** EPITECH PROJECT, 2021
** Camera
** File description:
** Camera
*/

#ifndef __CAMERA__
#define __CAMERA__

#include <raylib.h>

namespace raylib {
    class Camera : public ::Camera3D {
    public:
        Camera(::Camera3D const& camera) noexcept;
        explicit Camera(::Vector3 const& position_, ::Vector3 const& target_, ::Vector3 const& up_, float const fovy_ = 0, int const projection_ = 0) noexcept;
        Camera& operator=(::Camera3D const& camera) noexcept;
        Camera& beginMode() noexcept;
        Camera& endMode() noexcept;
        Matrix getMatrix() const noexcept;
        Camera& setMode(int const mode) noexcept;
        Camera& setAltControl(int const altKey) noexcept;
        Camera& setSmoothZoomControl(int const szKey) noexcept;
        Camera& setMoveControls(int const frontKey, int const backKey, int const rightKey, int const leftKey, int const upKey, int const downKey) noexcept;        Camera& update() noexcept;
        Ray getMouseRay(::Vector2 const& mousePosition) const noexcept;
        Vector2 getWorldToScreen(::Vector3 const& position) const noexcept;
        Camera& drawBillboard(::Texture2D const& texture, ::Vector3 const& center, float const size, ::Color const& tint = { 255, 255, 255, 255 }) noexcept;
    };
}

#endif /* __CAMERA__ */
