/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "AEnemy.hpp"

#include <server/room/Room.hpp>
#include <shared/Network/Requests.hpp>

RType::ECS::AEnemy::AEnemy(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::WeaponHolder weaponHolder, RType::ECS::State state, RType::ECS::EffectHandler effectHandler, RType::Network::Udp::EnemyType type) noexcept :
    GameObject(std::move(id), std::move(position), std::move(acceleration), std::move(health), std::move(hitBox), std::move(weaponHolder), std::move(state), std::move(effectHandler)), _type(type), _clock(2)
{
    this->_clock.setNextMoment(std::vector<int> {50, 75});
    this->_patternMove = 0;
}

RType::Network::Udp::EnemyType RType::ECS::AEnemy::getName() const noexcept
{
    return (_type);
}

void RType::ECS::AEnemy::update(const RType::AEvent &, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &, RType::ECS::IManager *manager) noexcept
{
    int movementRep = this->_clock.numberOfRep(0);
    int shotRep = this->_clock.numberOfRep(1);

    auto room = (RType::Server::Room *)manager;
    for (int i = 0; i < movementRep; ++i)
        movementPattern();
//    for (int i = 0; i < shotRep; ++i)
//        shot();
    std::pair<int, int> position;
    std::pair<int, int> acceleration;
    position.first = getXPos();
    position.second = getYPos();
    acceleration.first = getXAcceleration();
    acceleration.second = getYAcceleration();
    room->sendRequestToUsers(RType::Network::Request<RType::Network::Udp::EnemyUpdate>(RType::Network::Udp::ActionCodes::SendEnemyUpdate, position, acceleration, getName(), getId(), room->getId()));
}

void RType::ECS::AEnemy::movementPattern() noexcept {
    if (this->_patternMove >= this->_pattern.size())
        this->_patternMove = 0;
    //if (getXPos() + this->_pattern[this->_patternMove].first <= 0)
    setXPos(getXPos() + this->_pattern[this->_patternMove].first);
    if (getYPos() + this->_pattern[this->_patternMove].second <= 0)
        setYPos(0);
    else if (getYPos() + this->_pattern[this->_patternMove].second >= 1080)
        setYPos(1080);
    else
        setYPos(getYPos() + this->_pattern[this->_patternMove].second);
    ++this->_patternMove;
}