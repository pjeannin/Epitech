//
// Created by Pierre Jeannin on 14/06/2021.
//

#include "APowerUp.hpp"


APowerUp::APowerUp(IPowerUp::Type type, raylib::Vector3 position, Model3D &model) : _type(type), _position(position), _model(model)
{
    _time1 = std::chrono::steady_clock::now();
    _animVal = 0;
}

IPowerUp::Type APowerUp::getType() const { return _type; }

void APowerUp::anim()
{
    std::chrono::steady_clock::time_point _time2 = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(_time2 - _time1).count() > 1) {
        _animVal += 1;
        if (_animVal == 180)
            _animVal = 0;
        _time1 = _time2;
    }
}

void APowerUp::draw()
{
    anim();
    _model.first->draw(_position, raylib::Vector3 {0.0f, 1.0f, 0.0f}, _animVal , raylib::Vector3 {1.0f, 1.0f, 1.0f}, raylib::Color::White());
}

bool APowerUp::isTaken() const { return (_isTook); }

raylib::Vector3 APowerUp::getPosition() const {return _position;}
