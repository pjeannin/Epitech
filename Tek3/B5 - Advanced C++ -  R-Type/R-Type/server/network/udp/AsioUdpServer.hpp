/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_ASIOUDPSERVER_HPP__
#define __RTYPE_ASIOUDPSERVER_HPP__

#include "./IUdpServer.hpp"
#include "../network.hpp"
#include <server/Server.hpp>

#include <asio.hpp>

namespace RType::Server::Network {
    class AsioUdpServer : public RType::Server::Network::IUdpServer {
        public:
            static std::shared_ptr<RType::Server::Network::AsioUdpServer> create(asio::io_context &context, ::Port const port, std::shared_ptr<Server> server) noexcept;
            explicit AsioUdpServer(asio::io_context &context, ::Port const port, std::shared_ptr<Server> server) noexcept;
            ~AsioUdpServer() noexcept override = default;
            AsioUdpServer(const AsioUdpServer &other) noexcept = delete;
            AsioUdpServer(AsioUdpServer &&other) noexcept = delete;
            AsioUdpServer &operator=(const AsioUdpServer &other) noexcept = delete;
            AsioUdpServer &operator=(AsioUdpServer &&other) noexcept = delete;

            bool listen() noexcept final;
            void stop() noexcept final;
            void receiveRequest() noexcept;
            void send(void const *data, uint32_t size, RType::Server::Network::EndPoint const &endpoint) noexcept final;
        private:
            ::Port _port;
            asio::ip::udp::socket _socket;
            asio::ip::udp::endpoint _endpoint;
            std::shared_ptr<Server> _server;
    };
}

#endif //__RTYPE_ASIOUDPSERVER_HPP__
