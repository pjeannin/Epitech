/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Buy Airpods
*/

#include <utility>
#include <iostream>
#include "SfmlTcpClient.hpp"

RType::Client::Network::SfmlTcpClient::SfmlTcpClient() noexcept :
    _status(Status::DISCONNECTED), _port(0)
{
    _selector.add(_socket);
}

bool RType::Client::Network::SfmlTcpClient::connect(const std::string &ipAddress, unsigned short port) noexcept {
    sf::Socket::Status status = _socket.connect(ipAddress, port);

    _ipAddress = ipAddress;
    _port = port;
    if (status == sf::Socket::Done) {
        _status = Status::CONNECTED;
        OK_PRINT("Connected to " + ipAddress + ":" + std::to_string(port));
        return true;
    }
    return false;
}

void RType::Client::Network::SfmlTcpClient::disconnect() noexcept {
    _socket.disconnect();
    _status = Status::DISCONNECTED;
}

bool RType::Client::Network::SfmlTcpClient::send(void *toSend, size_t size) noexcept {
    char buffer[size + 3];

    std::memcpy(buffer, toSend, size);
    std::strcpy(buffer + size, "\r\n");
    if (_socket.send(buffer, size + 3) == sf::Socket::Done)
        return true;
    return false;
}

std::optional<::RType::Network::RcvRequest> RType::Client::Network::SfmlTcpClient::tryReceive() noexcept {
    char buffer[BUFFER_SIZE];
    size_t readBytes;sf::SocketSelector selector;
    selector.add(_socket);

    if (selector.wait(sf::milliseconds(1)))
        if (_socket.receive(buffer, BUFFER_SIZE, readBytes) == sf::Socket::Done)
            return ::RType::Network::RcvRequest::createFromBuffer(std::string(buffer, readBytes));
    return std::nullopt;
}

RType::Client::Network::ITcp::Status RType::Client::Network::SfmlTcpClient::getStatus() const noexcept { return _status; }

bool RType::Client::Network::SfmlTcpClient::sendText(const std::string &message) noexcept {
    sf::Socket::Status status = _socket.send(message.c_str(), message.size());
    if (status == sf::Socket::Done)
        return true;
    return false;
}

uint16_t RType::Client::Network::SfmlTcpClient::getPort() const noexcept
{
    return _socket.getLocalPort();
}
