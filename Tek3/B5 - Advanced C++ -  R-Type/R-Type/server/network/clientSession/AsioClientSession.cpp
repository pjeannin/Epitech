/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/

#include "AsioClientSession.hpp"

#include <iostream>
#include <shared/utils/print.hpp>
#include <shared/Network/Requests.hpp>
#include <shared/utils/print.hpp>
#include <server/network/udp/AsioUdpServer.hpp>

RType::Server::Network::AsioClientSession::AsioClientSession(asio::ip::tcp::socket &socket) noexcept :
    _tcpSocket(std::move(socket)), _udpEndpoint(_tcpSocket.remote_endpoint().address(), _tcpSocket.remote_endpoint().port())
{
    OK_PRINT( "New client accepted -> " << _tcpSocket.remote_endpoint().address().to_string() << ":" << _tcpSocket.remote_endpoint().port());
    startToReceive();
}

RType::Server::Network::AsioClientSession::~AsioClientSession() noexcept
{}

void RType::Server::Network::AsioClientSession::startToReceive() noexcept
{
    char buffer[BUFFER_SIZE] = {0};
    _tcpSocket.async_receive(asio::buffer(buffer, BUFFER_SIZE), [&](std::error_code const &err, std::size_t const bytesTransfered) {
        if (!err) {
            if (bytesTransfered >= HEADER_SIZE && _handleReceiveBufferCallback) {
                DEBUG_PRINT(std::string(buffer, bytesTransfered));
                _handleReceiveBufferCallback(std::string(buffer, bytesTransfered));
            }
            startToReceive();
        } else if (err == asio::error::eof) {
            OK_PRINT("Client has closed connection");
            close();
        } else {
            ERROR_PRINT("TcpClient failed to async receive: " << err.message());
            close();
        }
    });
}

void RType::Server::Network::AsioClientSession::setHandleReceiveBufferCallback(handlerReceiveBufferCallbackT func) noexcept
{
    _handleReceiveBufferCallback = func;
}

void RType::Server::Network::AsioClientSession::setOnClose(std::function<void()> onClose_) noexcept
{
    _onClose = onClose_;
}

void RType::Server::Network::AsioClientSession::close() noexcept
{
    if (_tcpSocket.is_open())
        _tcpSocket.close();
    if (_onClose)
        _onClose();
}

void RType::Server::Network::AsioClientSession::send(void *data, uint32_t size) noexcept
{
    asio::async_write(_tcpSocket, asio::buffer(data, size), [&](std::error_code const &err, std::size_t const){
        if (err) {
            ERROR_PRINT("TcpClient failed to async write: " << err.message());
        }
    });
}

std::string const RType::Server::Network::AsioClientSession::getIp() const noexcept
{
    return _udpEndpoint.address().to_string();
}

RType::Server::Network::EndPoint RType::Server::Network::AsioClientSession::getEndpointInfos() const noexcept
{
    return std::make_tuple<std::string const, uint16_t>(_udpEndpoint.address().to_string(), _udpEndpoint.port());
}

