/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_ASIO_HPP__
#define __RTYPE_ASIO_HPP__

#include "tcp/AsioTcpServer.hpp"
#include "udp/AsioUdpServer.hpp"
#include <server/Server.hpp>

#include <memory>

namespace RType::Server::Network {
    inline std::tuple<std::unique_ptr<RType::Server::Network::ITcpServer>, std::shared_ptr<RType::Server::Network::IUdpServer>> createAsioTcpUdpServer(::Port const port, std::shared_ptr<Server> server) {
        std::unique_ptr<RType::Server::Network::AsioTcpServer> tcpServer = RType::Server::Network::AsioTcpServer::create(port, server);
        std::shared_ptr<RType::Server::Network::AsioUdpServer> udpServer = RType::Server::Network::AsioUdpServer::create(tcpServer->getContext(), port, server);
        return std::make_tuple(std::move(tcpServer), udpServer);
    }
}
#endif //__RTYPE_ASIO_HPP__
