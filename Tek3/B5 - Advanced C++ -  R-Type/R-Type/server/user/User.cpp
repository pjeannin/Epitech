/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#include "User.hpp"
#include <shared/Network/Requests.hpp>
#include <server/room/Room.hpp>

RType::Server::User::User(std::shared_ptr<RType::Server::Network::IClientSession> clientSession, uint32_t id, std::shared_ptr<RType::Server::IServerTcpFct> server) noexcept :
    _client(clientSession), _id(id), _serverPtr(server)
{
    _client->setHandleReceiveBufferCallback(std::bind(&RType::Server::User::handleReceiveBuffer, this, std::placeholders::_1));
    _client->setOnClose(std::bind(&RType::Server::User::close, this));
}

RType::Server::User::~User() noexcept
{}

void RType::Server::User::handleReceiveBuffer(std::string const buffer) noexcept
{
    auto request = RType::Network::RcvRequest::createFromBuffer(buffer);

    if (request == std::nullopt || UserCommand::map.find(request->code) == UserCommand::map.end())
        return;
    (this->*UserCommand::map[request->code])(*request);
}

void RType::Server::User::createConnection(RType::Network::RcvRequest const &) noexcept
{
    try {
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::SuccessCodes::SuccessfulConnection));
    } catch (std::exception const &e) {
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedConnection));
    }
}

void RType::Server::User::createLobby(RType::Network::RcvRequest const &r) noexcept
{
    try {
        auto const req = r.getStructArgs<RType::Network::Tcp::LobbyRequest>();
        std::cout << req.username << " " << req.lobbyname << std::endl;
        std::optional<uint32_t> const roomId = _serverPtr->addNewRoom(req.lobbyname, shared_from_this());
        if (roomId == std::nullopt) {
            sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedLobbyCreation));
        } else {
            roomInfos = std::make_unique<RoomInfos>(*roomId, 1, req.username);
            sendRequest(RType::Network::Request<RType::Network::OnlyIdRequest>(RType::Network::Tcp::SuccessCodes::SuccessfulLobbyCreation, roomInfos->id, 1));
        }
    } catch (std::exception const &e) {
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedLobbyCreation));
    }
}

void RType::Server::User::joinAGame(RType::Network::RcvRequest const &r) noexcept
{
    try {
        auto const req = r.getStructArgs<RType::Network::Tcp::LobbyRequest>();
        auto room = _serverPtr->getRoomByName(req.lobbyname);
        if (!room || room->users.size() >= 4) {
            sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedJoining));
        } else {
            RType::Network::Request<RType::Network::Tcp::OnlyUsernameBody> res(RType::Network::Tcp::ActionCodes::SomeoneJoinLobby, req.username);
            for (auto &user : room->users)
                user->sendRequest(res);
            _serverPtr->addPlayerToRoom(req.lobbyname, shared_from_this());
            roomInfos = std::make_unique<RoomInfos>(room->getId(), room->users.size(), req.username);
            std::vector<std::string> names;
            for (auto const &user : room->users) {
                names.emplace_back(user->roomInfos->username);
            }
            sendRequest(RType::Network::Request<RType::Network::Tcp::ListPlayerRequest>(RType::Network::Tcp::SuccessCodes::SuccessfulJoining, roomInfos->id, roomInfos->playerId, room->getName(), names));
        }
    } catch (std::exception const &e) {
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedJoining));
    }
}

void RType::Server::User::startSignal(RType::Network::RcvRequest const &) noexcept
{
    try {
        if (!roomInfos) {
            sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedStart));
            return;
        }
        auto room = _serverPtr->getRoomById(roomInfos->id);
        if (!room) {
            sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedStart));
            return;
        }
        for (std::shared_ptr<User> user : room->users) {
            if (!user->roomInfos->ready) {
                sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedStart));
                return;
            }
        }
        _serverPtr->runRoom(room->getId());
        RType::Network::Request<RType::Network::EmptyBody> res(RType::Network::Tcp::SuccessCodes::SuccessfulStart);
        for (std::shared_ptr<User> &user: room->users) {
            user->sendRequest(res);
        }
    } catch (std::exception const &e) {
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedStart));
    }
}

void RType::Server::User::readySignal(RType::Network::RcvRequest const &) noexcept
{
    try {
        if (!roomInfos) {
            sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedReadySignal));
            return;
        }
        roomInfos->ready = true;
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::SuccessCodes::SuccessfulReadySignal));
    } catch (std::exception const &e) {
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedReadySignal));
    }
}

void RType::Server::User::listPlayer(RType::Network::RcvRequest const &) noexcept
{
    try {
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::SuccessCodes::SuccessfulJoining));
    } catch (std::exception const &e) {
        sendRequest(RType::Network::Request<RType::Network::EmptyBody>(RType::Network::Tcp::FailureCodes::FailedListing));
    }
}

template<RType::Network::C_Body T_Body>
void RType::Server::User::sendRequest(RType::Network::Request<T_Body> const &request) noexcept
{
    std::shared_ptr<char[]> ptr(new char[sizeof(RType::Network::Request<T_Body>)]);
    std::memcpy(ptr.get(), &request, sizeof(RType::Network::Request<T_Body>));
    _client->send(ptr.get(), sizeof(RType::Network::Request<T_Body>));
}

void RType::Server::User::sendRequest(void *data, uint32_t size) noexcept
{
    _client->send(data, size);
}

template<RType::Network::C_Body T_Body>
void RType::Server::User::sendRequestToOther(RType::Network::Request<T_Body> const &request, uint32_t id) noexcept
{
    if (_serverPtr) {
        std::shared_ptr<char[]> ptr(new char[sizeof(RType::Network::Request<T_Body>)]);
        std::memcpy(ptr.get(), &request, sizeof(RType::Network::Request<T_Body>));
        _serverPtr->sendRequestToAnotherUser(ptr.get(), sizeof(request), id);
    }
}



void RType::Server::User::close() noexcept
{
    if (roomInfos) {
        auto room = _serverPtr->getRoomById(roomInfos->id);
        room->removePlayer(shared_from_this());
    }
    if (_serverPtr)
        _serverPtr->removeUser(_id);
}

std::string const RType::Server::User::getIp() const noexcept
{
    return _client->getIp();
}

RType::Server::Network::EndPoint RType::Server::User::getEndpointInfos() const noexcept
{
    return _client->getEndpointInfos();
}

RType::Server::User::RoomInfos::RoomInfos() noexcept : id(0), ready(false)
{}

RType::Server::User::RoomInfos::RoomInfos(uint32_t id_, uint32_t playerId_, std::string const &username_, bool const ready_) noexcept : id(id_), playerId(playerId_), username(username_), ready(ready_)
{

}
