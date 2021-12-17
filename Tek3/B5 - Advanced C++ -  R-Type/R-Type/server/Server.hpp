/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Babel
*/

#ifndef __BABEL_SERVER_HPP__
#define __BABEL_SERVER_HPP__

#include "server/network/tcp/ITcpServer.hpp"
#include "server/network/udp/IUdpServer.hpp"
#include "user/User.hpp"
#include "network/clientSession/IClientSession.hpp"
#include <server/room/Room.hpp>
#include "IServer.hpp"

#include <memory>
#include <utility>
#include <thread>

namespace RType::Server {
    template<class T_type>
    concept TIClientSession_T = std::is_base_of<RType::Server::Network::IClientSession, T_type>::value;

    class Server : public  RType::Server::IServerTcpFct, public std::enable_shared_from_this<Server>  {
        public:
            explicit Server() noexcept;
            ~Server() noexcept;
            Server(const Server &other) noexcept = delete;
            Server(Server &&other) noexcept = delete;
            Server &operator=(const Server &other) noexcept = delete;
            Server &operator=(Server &&other) noexcept = delete;
            void initializeTcpUdp() noexcept;

            void transmitBufferToRoom(std::string const &buffer, std::string const &ip, uint16_t port) noexcept;
            void addNewUser(std::shared_ptr<RType::Server::Network::IClientSession> clientSession) noexcept final;
            void removeUser(uint32_t id) noexcept final;
            void sendRequestToAnotherUser(void *data, uint32_t size, uint32_t id) noexcept final;
            std::optional<uint32_t> addNewRoom(std::string const &roomName, std::shared_ptr<RType::Server::User> owner) final;
            std::shared_ptr<RType::Server::Room> getRoomByName(std::string const &name) noexcept final;
            std::shared_ptr<RType::Server::Room> getRoomById(uint32_t id) noexcept final;

            void addPlayerToRoom(std::string const &roomName, std::shared_ptr<RType::Server::User> userToAdd) final;
            bool isRoom(std::string const &roomName) const noexcept final;
            void runRoom(uint32_t id);

            void run() noexcept;
            static void catchStoppedSignal(int const signal) noexcept;
        private:

            uint32_t _id;
            uint32_t _roomId;
            std::unique_ptr<RType::Server::Network::ITcpServer> _tcp;
            std::shared_ptr<RType::Server::Network::IUdpServer> _udp;
            RType::Server::UserMap _users;
            std::vector<std::thread> _gameThreadPoll;
            std::thread _tcpServerThread;
            std::map<uint32_t, std::shared_ptr<RType::Server::Room>> _rooms;
    };
}

#endif //__BABEL_SERVER_HPP__
