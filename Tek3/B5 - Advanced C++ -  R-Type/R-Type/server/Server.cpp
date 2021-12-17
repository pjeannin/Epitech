/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Babel
*/

#include <server/Server.hpp>
#include <server/network/tcp/AsioTcpServer.hpp>
#include <server/network/Asio.hpp>
#include <shared/utils/print.hpp>

#include <csignal>
#include <iostream>
#include <algorithm>

bool isRunning = true;

RType::Server::Server::Server() noexcept : _id(0), _roomId(0)
{
    std::signal(SIGINT, RType::Server::Server::catchStoppedSignal);
    std::signal(SIGKILL, RType::Server::Server::catchStoppedSignal);
    std::signal(SIGTERM, RType::Server::Server::catchStoppedSignal);
}

void RType::Server::Server::initializeTcpUdp() noexcept
{
    auto servers = RType::Server::Network::createAsioTcpUdpServer(4242, shared_from_this());
    _tcp = std::move(std::get<0>(servers));
    _udp = std::move(std::get<1>(servers));
}

void RType::Server::Server::run() noexcept
{
    _tcpServerThread = std::thread([&]{ _tcp->listen(); });
    _udp->listen();
    while (isRunning) {
        pause();
    }
}

void RType::Server::Server::addNewUser(std::shared_ptr<RType::Server::Network::IClientSession> clientSession) noexcept
{
    ++_id;
    _users.emplace(_id, std::make_shared<User>(clientSession, _id, shared_from_this()));
}

void RType::Server::Server::removeUser(uint32_t id) noexcept
{
    _users.erase(id);
}

void RType::Server::Server::sendRequestToAnotherUser(void *data, uint32_t size, uint32_t id) noexcept
{
    _users[id]->sendRequest(data, size);
}

void RType::Server::Server::catchStoppedSignal(int const) noexcept
{
    OK_PRINT("Server has been stopped");
    isRunning = false;
}

std::optional<uint32_t> RType::Server::Server::addNewRoom(std::string const &roomName, std::shared_ptr<RType::Server::User> owner)
{
    if (isRoom(roomName))
        return {};
    ++_roomId;
    _rooms.emplace(_roomId, std::make_shared<RType::Server::Room>(roomName, _udp, owner, _roomId));
    return _roomId;
}

void RType::Server::Server::addPlayerToRoom(std::string const &roomName, std::shared_ptr<RType::Server::User> userToAdd)
{
    auto const &it = std::find_if(_rooms.begin(), _rooms.end(), [roomName](std::pair<uint32_t, std::shared_ptr<RType::Server::Room>> const &e) -> bool {
        return e.second->getName() == roomName;
    });
    if (it != _rooms.end()) {
        it->second->addPlayer(userToAdd);
    }
}

bool RType::Server::Server::isRoom(std::string const &roomName) const noexcept
{
    auto const &it = std::find_if(_rooms.begin(), _rooms.end(), [roomName](std::pair<uint32_t, std::shared_ptr<RType::Server::Room>> const &e) -> bool {
        return e.second->getName() == roomName;
    });
    return it != _rooms.end();
}

std::shared_ptr<RType::Server::Room> RType::Server::Server::getRoomByName(std::string const &name) noexcept
{
    auto const &it = std::find_if(_rooms.begin(), _rooms.end(), [name](std::pair<uint32_t, std::shared_ptr<RType::Server::Room>> const &e) -> bool {
        return e.second->getName() == name;
    });
    if (it != _rooms.end())
        return it->second;
    return nullptr;
}

std::shared_ptr<RType::Server::Room> RType::Server::Server::getRoomById(uint32_t id) noexcept
{
    if (_rooms.find(id) == _rooms.end())
        return nullptr;
    return _rooms[id];
}

RType::Server::Server::~Server() noexcept
{
    for (auto &gameThread : _gameThreadPoll) {
        gameThread.join();
    }
    _tcpServerThread.join();
    _tcp->stop();
    _users.clear();

    //TODO stop thread + check if server are shutdown + delete all vector
}

void RType::Server::Server::transmitBufferToRoom(std::string const &buffer, std::string const &ip, uint16_t port) noexcept
{
    auto request = RType::Network::RcvRequest::createFromBuffer(buffer);

    if (request == std::nullopt)
        return;
    auto r = request->getStructArgs<RType::Network::OnlyIdRequest>();
    auto room = getRoomById(r.id);
    if (!room)
        return;
    room->handleReceiveRequest(*request, ip, port);
}

void RType::Server::Server::runRoom(uint32_t id)
{
    _gameThreadPoll.emplace_back(std::bind(&RType::Server::Room::run, _rooms[id]));
}
