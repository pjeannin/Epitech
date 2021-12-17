/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_ISERVER_HPP__
#define __RTYPE_ISERVER_HPP__

#include <memory>
#include <optional>

namespace RType::Server {
    class User;
    class Room;
}

namespace RType::Server {
    class IServerTcpFct {
        public:
            virtual void addNewUser(std::shared_ptr<RType::Server::Network::IClientSession> clientSession) noexcept = 0;
            virtual void removeUser(uint32_t id) noexcept = 0;
            virtual void sendRequestToAnotherUser(void *data, uint32_t size, uint32_t id) noexcept = 0;
            virtual std::optional<uint32_t> addNewRoom(std::string const &roomName, std::shared_ptr<RType::Server::User> owner) = 0;
            virtual void addPlayerToRoom(std::string const &roomName, std::shared_ptr<RType::Server::User> userToAdd) = 0;
            virtual bool isRoom(std::string const &roomName) const noexcept = 0;
            virtual std::shared_ptr<RType::Server::Room> getRoomByName(std::string const &name) noexcept = 0;
            virtual std::shared_ptr<RType::Server::Room> getRoomById(uint32_t id) noexcept = 0;
            virtual void runRoom(uint32_t id) = 0;
    };
}

#endif //__RTYPE_ISERVER_HPP__
