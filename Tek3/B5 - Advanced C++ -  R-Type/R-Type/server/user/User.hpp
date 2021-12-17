/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_USER_HPP__
#define __RTYPE_USER_HPP__

#include "IUser.hpp"
#include <server/network/clientSession/IClientSession.hpp>
#include <server/network/udp/IUdpServer.hpp>
#include <shared/Network/Requests.hpp>
#include <server/IServer.hpp>
#include <server/GameObjects/Player.hpp>

#include <memory>
#include <map>

namespace RType::Server {
    namespace UserCommand {
        static std::map<unsigned  short, void (IUser::*)(RType::Network::RcvRequest const &)> map{
            {RType::Network::Tcp::ActionCodes::CreateConnection, &IUser::createConnection},
            {RType::Network::Tcp::ActionCodes::CreateLobby, &IUser::createLobby},
            {RType::Network::Tcp::ActionCodes::JoinAGame, &IUser::joinAGame},
            {RType::Network::Tcp::ActionCodes::StartSignal, &IUser::startSignal},
            {RType::Network::Tcp::ActionCodes::ReadySignal, &IUser::readySignal},
            {RType::Network::Tcp::ActionCodes::ListPlayer, &IUser::listPlayer}
        };
    }

    class User : public RType::Server::IUser, public std::enable_shared_from_this<User> {
        public:
            struct RoomInfos {
                explicit RoomInfos() noexcept;
                explicit RoomInfos(uint32_t id_, uint32_t playerId, std::string const &username_, bool const ready_ = false) noexcept;
                uint32_t id;
                uint32_t playerId;
                std::string username;
                bool ready;
                std::shared_ptr<RType::Server::GameObjects::Player> player;
            };

            explicit User(std::shared_ptr<RType::Server::Network::IClientSession> clientSession, uint32_t id, std::shared_ptr<RType::Server::IServerTcpFct> server) noexcept;
            ~User() noexcept;
            User(const User &other) noexcept = default;
            User(User &&other) noexcept = delete;
            User &operator=(const User &other) noexcept = delete;
            User &operator=(User &&other) noexcept = delete;

            void handleReceiveBuffer(std::string const buffer) noexcept;
            void sendRequest(void *data, uint32_t size) noexcept;
            std::string const getIp() const noexcept;
            RType::Server::Network::EndPoint getEndpointInfos() const noexcept;

            std::unique_ptr<RoomInfos> roomInfos;
        private:
            void createConnection(RType::Network::RcvRequest const &r) noexcept final;
            void createLobby(RType::Network::RcvRequest const &r) noexcept final;
            void joinAGame(RType::Network::RcvRequest const &r) noexcept final;
            void startSignal(RType::Network::RcvRequest const &r) noexcept final;
            void readySignal(RType::Network::RcvRequest const &r) noexcept final;
            void listPlayer(RType::Network::RcvRequest const &r) noexcept final;

            void close() noexcept;

            template<RType::Network::C_Body T_Body>
            void sendRequest(RType::Network::Request<T_Body> const &request) noexcept;

            template<RType::Network::C_Body T_Body>
            void sendRequestToOther(RType::Network::Request<T_Body> const &request, uint32_t id) noexcept;

            std::shared_ptr<RType::Server::Network::IClientSession> _client;
            uint32_t _id;
            std::shared_ptr<RType::Server::IServerTcpFct> _serverPtr;
    };

    using UserMap = std::map<uint32_t, std::shared_ptr<RType::Server::User>>;
}

#endif //__RTYPE_USER_HPP__
