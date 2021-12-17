/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/

#include "Room.hpp"

extern bool isRunning;

RType::Server::Room::Room(std::string const &name, std::shared_ptr<RType::Server::Network::IUdpServer> udpSocket, std::shared_ptr<RType::Server::User> owner, uint32_t id) noexcept :
    users({ owner }), _name(name), _udpSocket(udpSocket), _id(id), _clock(3), _gameObjectId(8)
{
    _clock.setNextMoment(std::vector<int>{60, 15000, 60});
}

void RType::Server::Room::initializeRoom() noexcept
{
    unsigned char i = RType::Network::Udp::PlayerID::Player1;
    for (auto &user : users) {
        user->roomInfos->player = std::make_shared<RType::Server::GameObjects::Player>(RType::ECS::ID(i), RType::ECS::Position(200, 200 * i), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::Score(0) ,RType::ECS::WeaponHolder(), RType::ECS::EffectHandler());
        ++i;
        _players.emplace_back(user->roomInfos->player);
        user->roomInfos->player->id = user->roomInfos->id;
        std::pair<int, int> position;
        std::pair<int, int> acceleration;
        position.first = user->roomInfos->player->getXPos();
        position.second = user->roomInfos->player->getYPos();
        acceleration.first = user->roomInfos->player->getXAcceleration();
        acceleration.second = user->roomInfos->player->getYAcceleration();
        auto finalRequest = RType::Network::Request<RType::Network::Udp::PlayerUpdate>(RType::Network::Udp::ActionCodes::SendPlayerUpdate, position, acceleration, user->roomInfos->player->getHealth(), user->roomInfos->player->getScore(), static_cast<RType::Network::Udp::PlayerID>(user->roomInfos->player->getId()), user->roomInfos->id);
        sendRequest(finalRequest, user->getEndpointInfos());
    }
}

void RType::Server::Room::update() noexcept
{
    if (_clock.numberOfRep(0))
        for (auto &player: _players) {
            std::cout << player->getYPos() << std::endl;
            position.first = player->getXPos();
            position.second = player->getYPos();
            acceleration.first = player->getXAcceleration();
            acceleration.second = player->getYAcceleration();
            RType::Network::Udp::PlayerUpdate player__(position, acceleration, player->getHealth(), player->getScore(), static_cast<RType::Network::Udp::PlayerID>(player->getId()), player->id);
            auto finalRequest = RType::Network::Request<RType::Network::Udp::PlayerUpdate>(RType::Network::Udp::ActionCodes::SendPlayerUpdate, player__);
            sendRequestToUsers(finalRequest);
        }

    if (_clock.numberOfRep(2))
        for (int i = 0; i < _gameObjects.size(); ++i) {
            _gameObjects[i]->update(RType::AEvent(), _gameObjects, this);
            if (dynamic_cast<RType::ECS::Position *>(_gameObjects[i].get())->getXPos() <= -200)
                _gameObjects.erase(_gameObjects.begin() + i);
        }
    if (_clock.numberOfRep(1))
        for (uint16_t nbMonsterToGenerate = 2; nbMonsterToGenerate > 0; --nbMonsterToGenerate) {
            ++_gameObjectId;
            std::shared_ptr<RType::ECS::AEnemy> enemy = _swarm.genSwarm(1, _gameObjectId)[0];
            _gameObjects.emplace_back(enemy);
            position.first = enemy->getXPos();
            position.second = enemy->getYPos();
            acceleration.first = enemy->getXAcceleration();
            acceleration.second = enemy->getYAcceleration();
            sendRequestToUsers(RType::Network::Request<RType::Network::Udp::EnemyUpdate>(RType::Network::Udp::ActionCodes::SendEnemyUpdate, position, acceleration, enemy->getName(), enemy->getId(), _id));
        }
}

void RType::Server::Room::run() noexcept
{
    initializeRoom();
    while (isRunning) {
        update();
    }
}

std::string const &RType::Server::Room::getName() const noexcept { return _name; }

void RType::Server::Room::addPlayer(std::shared_ptr<RType::Server::User> userToAdd) noexcept
{
    users.emplace_back(userToAdd);
}

uint32_t RType::Server::Room::getId() const noexcept
{
    return _id;
}

RType::Server::Room::~Room() noexcept {}

void RType::Server::Room::handleReceiveRequest(RType::Network::RcvRequest const &request, std::string const &ip, uint16_t port) noexcept
{
    if (RoomCommand::map.find(request.code) == RoomCommand::map.end())
        return;
    std::shared_ptr<RType::Server::User> user;
    for (auto &tmp : users) {
        RType::Server::Network::EndPoint endpoint = tmp->getEndpointInfos();
        if (std::get<RType::Server::Network::EndPointI::Ip>(endpoint) == ip && std::get<RType::Server::Network::EndPointI::Port>(endpoint) + 1 == port) {
            user = tmp;
        }
    }
    if (user)
        (this->*RoomCommand::map[request.code])(request, user);
}

void RType::Server::Room::unimplemented(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User>) noexcept
{

}

void RType::Server::Room::sendPlayerUpdate(const RType::Network::RcvRequest &rcv_request, std::shared_ptr<RType::Server::User> user) noexcept
{
    auto request = rcv_request.getStructArgs<RType::Network::Udp::PlayerUpdate>();
    auto player = user->roomInfos->player;
    player->setXAcceleration(request.acceleration.first);
    player->setYAcceleration(request.acceleration.second);
    player->setXPos(request.position.first);
    player->setYPos(request.position.second);
    std::cout << "sendPlayerUpdate " << player->getXPos() << " " << player->getYPos() << " " << request.position.first << " " << request.position.second << std::endl;
    player->setScore(request.score);
    player->setHealth(request.health);
}

template<RType::Network::C_Body T_Body>
void RType::Server::Room::sendRequest(RType::Network::Request<T_Body> const &request, RType::Server::Network::EndPoint const &endpoint) noexcept
{
    std::shared_ptr<char[]> ptr(new char[sizeof(request)]);
    std::memcpy(ptr.get(), &request, sizeof(request));
    _udpSocket->send(ptr.get(), sizeof(request), endpoint);
}

void RType::Server::Room::removePlayer(std::shared_ptr<RType::Server::User> userToremove) noexcept
{
    unsigned char id = 0;

    DEBUG_PRINT(users.size());
    for (auto const &user : users) {
        if (userToremove == user) {
            _players.erase(_players.begin() + id);
            users.erase(users.begin() + id);
            break;
        }
        ++id;
    }
    DEBUG_PRINT(users.size());
}

template<RType::Network::C_Body T_Body>
void RType::Server::Room::sendRequestToUsers(RType::Network::Request<T_Body> const &request) noexcept
{
    for (auto &user: users)
        sendRequest(request, user->getEndpointInfos());
}

void RType::Server::Room::sendAmmoUpdate(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User>) noexcept
{
}

std::vector<std::shared_ptr<RType::ECS::IGameObject>> &RType::Server::Room::getGameObjects() noexcept
{
    return _gameObjects;
}


