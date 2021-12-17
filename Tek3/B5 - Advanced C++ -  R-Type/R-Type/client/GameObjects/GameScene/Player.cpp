/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "Player.hpp"

RType::ECS::SfmlDrawable generatePlayerDrawable(RType::Network::Udp::PlayerID playerId, std::shared_ptr<sf::RenderWindow> window) noexcept {
    switch (playerId) {
        case RType::Network::Udp::Player1:
            return RType::ECS::SfmlDrawable(window, "../../assets/sprites/player1.png", std::make_pair<unsigned int, unsigned int>(58, 55), std::make_pair<unsigned int, unsigned int>(58, 55), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair(1.1, 1.1));
        case RType::Network::Udp::Player2:
            return RType::ECS::SfmlDrawable(window, "../../assets/sprites/player2.png", std::make_pair<unsigned int, unsigned int>(58, 55), std::make_pair<unsigned int, unsigned int>(58, 55), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair(1.1, 1.1));
        case RType::Network::Udp::Player3:
            return RType::ECS::SfmlDrawable(window, "../../assets/sprites/player3.png", std::make_pair<unsigned int, unsigned int>(58, 55), std::make_pair<unsigned int, unsigned int>(58, 55), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair(1.1, 1.1));
        case RType::Network::Udp::Player4:
            return RType::ECS::SfmlDrawable(window, "../../assets/sprites/player4.png", std::make_pair<unsigned int, unsigned int>(58, 55), std::make_pair<unsigned int, unsigned int>(58, 55), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair(1.1, 1.1));
    }
    return RType::ECS::SfmlDrawable(window, "../../assets/sprites/player4.png", std::make_pair<unsigned int, unsigned int>(102, 102), std::make_pair<unsigned int, unsigned int>(714, 408), std::make_pair<unsigned int, unsigned int>(0, 0)); //Just to take the warning away
}

RType::Client::GameObjects::Player::Player(RType::ECS::ID id, std::shared_ptr<sf::RenderWindow> window, RType::Network::Udp::PlayerID playerId, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::Score score, RType::ECS::WeaponHolder weaponHolder, bool isMe) noexcept : RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::Health, RType::ECS::Score, RType::ECS::WeaponHolder>(std::move(id), generatePlayerDrawable(playerId, window), std::move(position), std::move(acceleration), std::move(health), std::move(score), std::move(weaponHolder)), _isMe(isMe), _clock(3) {
    _type = PLAYER;
    _clock.setNextMoment(std::vector<int>{7, 75, 10});
}

bool RType::Client::GameObjects::Player::keyMovement(const RType::AEvent& event) noexcept {
    std::vector<bool> ev = event.getKeyEvent();
    bool isEv = false;
    if (ev[RType::AEvent::Key::DOWN]) {
        _accelerationY = 2;
        isEv = true;
    } else if (ev[RType::AEvent::Key::UP]) {
        _accelerationY = -2;
        isEv = true;
    } else if (ev[RType::AEvent::Key::DOWN_RELEASE] || ev[RType::AEvent::Key::UP_RELEASE]) {
        _accelerationY = 0;
    }
    if (ev[RType::AEvent::Key::RIGHT]) {
        _accelerationX = 2;
        isEv = true;
    } else if (ev[RType::AEvent::Key::LEFT]) {
        _accelerationX = -2;
        isEv = true;
    } else if (ev[RType::AEvent::Key::RIGHT_RELEASE] || ev[RType::AEvent::Key::LEFT_RELEASE]) {
        _accelerationX = 0;
    }
    return isEv;
}

bool RType::Client::GameObjects::Player::controllerMovement(const RType::AEvent& event) noexcept {
    RType::AEvent::Controller ctrl = event.getControllerEvent();
    bool ev = false;

    if (ctrl.JoystickX > 30) {
        _accelerationX = 2;
        ev = true;
    } else if (ctrl.JoystickX < -30) {
        _accelerationX = -2;
        ev = true;
    } else {
        _accelerationX = 0;
    }
    if (ctrl.JoystickY > 30) {
        _accelerationY = 2;
        ev = true;
    } else if (ctrl.JoystickY < -30) {
        _accelerationY = -2;
        ev = true;
    } else {
        _accelerationY = 0;
    }
    return ev;
}

void RType::Client::GameObjects::Player::movementByPlayer(const RType::AEvent& event) noexcept {
    bool ev = false;

    if (event.isControllerPlugged())
        ev = this->controllerMovement(event);
    else
        ev = this->keyMovement(event);

}

void RType::Client::GameObjects::Player::update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *manager) noexcept {
    int numberOfShots = 0;
    int numberOfMove = _clock.numberOfRep(0);
    if (_isMe) {
        numberOfShots = _clock.numberOfRep(1);
        movementByPlayer(event);
        for (int i = 0; i < numberOfShots; ++i) {
//            if (event.isControllerPlugged() && event.getControllerEvent().buttonA)
//                shot();
//            else if (event.getKeyEvent()[RType::AEvent::SPACE]) {
//                shot();
//            }
        }
    }
    for (int i = 0; i < numberOfMove; ++i) {
        updateMove();
        if (_isMe) {
            ((RType::Client::Scene::GameScene *) manager)->sendPlayerUpdate(this);
        }
    }
    draw((RType::ECS::Position)*this);
}

void RType::Client::GameObjects::Player::updateMove() noexcept {
    if (_posX + _accelerationX <= 0)
        _posX = 0;
    else if (_posX + _accelerationX >= 1915)
        _posX = 1915;
    else
        _posX += _accelerationX;
    if (_posY + _accelerationY <= 0)
        _posY = 0;
    else if (_posY + _accelerationY >= 1075)
        _posY = 1075;
    else
        _posY += _accelerationY;
}

bool RType::Client::GameObjects::Player::isMe() const noexcept { return _isMe; }
