#include "Camera.hpp"

raylib::Camera::Camera(::Camera3D const &camera) noexcept { *this = camera; }

raylib::Camera::Camera(::Vector3 const &position_, ::Vector3 const &target_, ::Vector3 const &up_, float const fovy_, int const projection_) noexcept {
    position = position_;
    target = target_;
    up = up_;
    fovy = fovy_;
    projection = projection_;
}

raylib::Camera &raylib::Camera::operator=(::Camera3D const &camera) noexcept {
    position = camera.position;
    target = camera.target;
    up = camera.up;
    fovy = camera.fovy;
    projection = camera.projection;
    return *this;
}

raylib::Camera &raylib::Camera::beginMode() noexcept 
{ 
    return (::BeginMode3D(*this), *this);
}

raylib::Camera &raylib::Camera::endMode() noexcept 
{ 
    return (::EndMode3D(), *this);
}

Matrix raylib::Camera::getMatrix() const noexcept 
{ 
    return ::GetCameraMatrix(*this); 
}

raylib::Camera &raylib::Camera::setMode(int const mode) noexcept 
{ 
    return (::SetCameraMode(*this, mode), *this);
}

raylib::Camera &raylib::Camera::setAltControl(int const altKey) noexcept 
{ 
    return (::SetCameraAltControl(altKey), *this); 
}

raylib::Camera &raylib::Camera::setSmoothZoomControl(int const szKey) noexcept 
{ 
    return (::SetCameraSmoothZoomControl(szKey), *this); 
}

raylib::Camera &raylib::Camera::setMoveControls(int const frontKey, int const backKey, int const rightKey, int const leftKey, int const upKey, int const downKey) noexcept 
{ 
    return (::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey), *this); 
}

raylib::Camera &raylib::Camera::update() noexcept  
{ 
    return (::UpdateCamera(this), *this);
}

Ray raylib::Camera::getMouseRay(::Vector2 const &mousePosition) const noexcept { 
    return ::GetMouseRay(mousePosition, *this);
}

Vector2 raylib::Camera::getWorldToScreen(::Vector3 const &position) const noexcept 
{ 
    return ::GetWorldToScreen(position, *this);
}

raylib::Camera &raylib::Camera::drawBillboard(::Texture2D const &texture, ::Vector3 const &center, float const size, ::Color const &tint) noexcept 
{
    return (::DrawBillboard(*this, texture, center, size, tint), *this);
}

