/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_ROOM_HPP__
#define __RTYPE_ROOM_HPP__

#include <server/user/User.hpp>
#include <string>
#include <server/network/udp/IUdpServer.hpp>
#include <shared/ECS/IGameObject.hpp>
#include <shared/ECS/State.hpp>
#include <server/GameObjects/Player.hpp>
#include <memory>
#include <vector>
#include <map>
#include "IRoom.hpp"
#include "shared/Clock/clock.hpp"
#include "../swarm/Swarm.hpp"
#include <shared/ECS/IManager.hpp>

namespace RType::Server {
    namespace RoomCommand {
        static std::map<unsigned  short, void (IRoom::*)(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User>)> map{
            {RType::Network::Udp::ActionCodes::SendAmmoUpdate, &IRoom::unimplemented},
            {RType::Network::Udp::ActionCodes::SendEnemyUpdate, &IRoom::unimplemented},
            {RType::Network::Udp::ActionCodes::SendObjectUpdate, &IRoom::unimplemented},
            {RType::Network::Udp::ActionCodes::SendAmmoUpdate, &IRoom::sendAmmoUpdate},
            {RType::Network::Udp::ActionCodes::SendPing, &IRoom::unimplemented},
            {RType::Network::Udp::ActionCodes::SendPlayerUpdate, &IRoom::sendPlayerUpdate}
        };
    }

    class Room : public IRoom, public RType::ECS::IManager {
        public:
            explicit Room(std::string const &name, std::shared_ptr<RType::Server::Network::IUdpServer> udpSocket, std::shared_ptr<RType::Server::User> owner, uint32_t id) noexcept;
            ~Room() noexcept;
            Room(const Room &other) noexcept = delete;
            Room(Room &&other) noexcept = delete;
            Room &operator=(const Room &other) noexcept = delete;
            Room &operator=(Room &&other) noexcept = delete;

            void initializeRoom() noexcept;
            void run() noexcept;
            void handleReceiveRequest(RType::Network::RcvRequest const &r, std::string const &ip, uint16_t port) noexcept;
            void addPlayer(std::shared_ptr<RType::Server::User> userToAdd) noexcept;
            void removePlayer(std::shared_ptr<RType::Server::User> userToremove) noexcept;
            [[nodiscard]] std::string const &getName() const noexcept;
            [[nodiscard]] uint32_t getId() const noexcept;
            void update() noexcept final;
            [[nodiscard]] std::vector<std::shared_ptr<RType::ECS::IGameObject>> &getGameObjects() noexcept final;

            std::pair<int, int> position;
            std::pair<int, int> acceleration;

            std::vector<std::shared_ptr<RType::Server::User>> users;
            template<RType::Network::C_Body T_Body> void sendRequest(RType::Network::Request<T_Body> const &request, RType::Server::Network::EndPoint const &endpoint) noexcept;
            template<RType::Network::C_Body T_Body> void sendRequestToUsers(RType::Network::Request<T_Body> const &request) noexcept;
        private:
            void unimplemented(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User> user) noexcept final;
            void sendPlayerUpdate(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User>) noexcept final;
            void sendAmmoUpdate(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User>) noexcept final;

            std::string const _name;
            std::shared_ptr<RType::Server::Network::IUdpServer> _udpSocket;
            std::vector<std::shared_ptr<RType::ECS::IGameObject>> _gameObjects;
            std::vector<std::shared_ptr<RType::Server::GameObjects::Player>> _players;
            uint32_t _id;
            Clock _clock;
            RType::ECS::Swarm _swarm;
            uint32_t _gameObjectId;
    };
}

#endif //__RTYPE_ROOM_HPP__
