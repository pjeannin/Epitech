/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/

#include "AsioTcpServer.hpp"
#include <server/network/clientSession/AsioClientSession.hpp>
#include <shared/utils/print.hpp>
#include <iostream>

RType::Server::Network::AsioTcpServer::AsioTcpServer(::Port const port, std::shared_ptr<Server> server) noexcept :
    _port(port), //_signals(_context, SIGINT, SIGTERM),
    _endpoint(asio::ip::tcp::v4(), port), _acceptor(asio::ip::tcp::acceptor(_context, _endpoint)),
    _server(server)
{
//    _signals.async_wait([&](auto const &, auto const &){ _context.stop(); });
}

bool RType::Server::Network::AsioTcpServer::listen() noexcept
{
    try {
        OK_PRINT("Listening on port: " << _endpoint.address().to_string() << ":" << _port);
        std::cout <<"Waiting for connection ..." << std::endl;
        acceptNewConnection();
        _context.run();
    } catch(asio::error_code const &e) {
        ERROR_PRINT(e.message());
    }
    return false;
}

asio::io_context &RType::Server::Network::AsioTcpServer::getContext() noexcept
{
    return _context;
}

std::unique_ptr<RType::Server::Network::AsioTcpServer> RType::Server::Network::AsioTcpServer::create(::Port const port, std::shared_ptr<Server> server) noexcept
{
    return std::make_unique<RType::Server::Network::AsioTcpServer>(port, server);
}

void RType::Server::Network::AsioTcpServer::acceptNewConnection()
{
    _acceptor.async_accept([&](asio::error_code const &error, asio::ip::tcp::socket socket) {
        if (error)
            ERROR_PRINT("Failed to accept connection: " << error.message());
        else {
//            socket.set_option(asio::socket_base::debug(true)); // TODO toggle debbug mode to true + add ifndef in function of DEBUG define || Check if works
            _server->addNewUser(std::make_shared<RType::Server::Network::AsioClientSession>(socket));
        }
        acceptNewConnection();
    });
}



RType::Server::Network::AsioTcpServer::~AsioTcpServer() noexcept
{
    stop();
}

void RType::Server::Network::AsioTcpServer::stop() noexcept
{
    _context.stop();
}
