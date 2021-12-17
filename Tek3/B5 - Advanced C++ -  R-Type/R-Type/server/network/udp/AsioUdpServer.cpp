/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/

#include <shared/utils/print.hpp>
#include "AsioUdpServer.hpp"
#include <shared/Network/Requests.hpp>

#include <iostream>

std::shared_ptr<RType::Server::Network::AsioUdpServer> RType::Server::Network::AsioUdpServer::create(asio::io_context &context, ::Port const port, std::shared_ptr<Server> server) noexcept
{
    return std::make_shared<RType::Server::Network::AsioUdpServer>(context, port, server);
}

RType::Server::Network::AsioUdpServer::AsioUdpServer(asio::io_context &context, ::Port const port, std::shared_ptr<Server> server) noexcept :
    _port(port), _socket(context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 4242)), _server(server)
{}

bool RType::Server::Network::AsioUdpServer::listen() noexcept
{
    try {
        receiveRequest();
    } catch(asio::error_code const &e) {
        ERROR_PRINT(e.message());
    }
    return false;
}

void RType::Server::Network::AsioUdpServer::stop() noexcept
{}

void RType::Server::Network::AsioUdpServer::receiveRequest() noexcept
{
    char buffer[BUFFER_SIZE] = {0};
    _socket.async_receive_from(asio::buffer(buffer, BUFFER_SIZE), _endpoint, [&](std::error_code const &err, std::size_t const bytesTransfered){
        if (!err) {
            if (bytesTransfered >= HEADER_SIZE) {
                _server->transmitBufferToRoom(std::string(buffer, bytesTransfered), _endpoint.address().to_string(), _endpoint.port());
            }
            receiveRequest();
        } else {
            ERROR_PRINT("UdpClient failed to async receive: " << err.message());
        }
    });
}

void RType::Server::Network::AsioUdpServer::send(void const *data, uint32_t size, RType::Server::Network::EndPoint const &endpoint) noexcept
{
    std::error_code ec;
    asio::ip::address ip_address = asio::ip::address::from_string(std::get<RType::Server::Network::EndPointI::Ip>(endpoint), ec);
    if (ec.value()) {
        ERROR_PRINT("failed to create ip from " << std::get<RType::Server::Network::EndPointI::Ip>(endpoint) << ":" << std::get<RType::Server::Network::EndPointI::Port>(endpoint) + 1);
        return;
    }
    _socket.async_send_to(asio::buffer(data, size), asio::ip::udp::endpoint(ip_address, std::get<RType::Server::Network::EndPointI::Port>(endpoint) + 1), [&](std::error_code const &err, std::size_t const) {
        if (err)
            ERROR_PRINT("UdpClient failed to async send: " << err.message());
     });
}
