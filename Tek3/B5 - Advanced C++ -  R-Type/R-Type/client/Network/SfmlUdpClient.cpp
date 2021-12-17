/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "SfmlUdpClient.hpp"

RType::Client::Network::SfmlUdpClient::SfmlUdpClient(unsigned int port)
{
    _socket.bind(port);
}

bool RType::Client::Network::SfmlUdpClient::send(void *toSend, size_t size, const std::string &ip, unsigned short port) noexcept {
    char buffer[size + 3];

    std::memcpy(buffer, toSend, size);
    std::strcpy(buffer + size, "\r\n");
    return _socket.send(buffer, size + 3, ip, port) == sf::Socket::Done;
}

bool RType::Client::Network::SfmlUdpClient::sendText(const std::string &toSend, const std::string &ip, unsigned short port) noexcept {
    return send((void *)toSend.c_str(), toSend.size(), ip, port);
}

std::optional<::RType::Network::RcvRequest> RType::Client::Network::SfmlUdpClient::tryReceive() noexcept {
    char buffer[BUFFER_SIZE];
    size_t readBytes;
    sf::SocketSelector selector;
    sf::IpAddress ip;
    unsigned short port;

    //DEBUG_PRINT("getLocal Port:" << _socket.getLocalPort());
    selector.add(_socket);
    if (selector.wait(sf::milliseconds(1)))
        if (_socket.receive(buffer, BUFFER_SIZE, readBytes, ip, port) == sf::Socket::Done) {
            ///DEBUG_PRINT(ip << ":" << port << " -> " << buffer << " " << readBytes);
            return ::RType::Network::RcvRequest::createFromBuffer(std::string(buffer, readBytes));
        }
    return std::nullopt;
}