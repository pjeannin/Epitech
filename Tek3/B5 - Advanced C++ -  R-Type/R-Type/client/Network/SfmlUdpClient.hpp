/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SFMLUDPCLIENT_HPP
#define RTYPE_SFMLUDPCLIENT_HPP

#include <SFML/Network.hpp>
#include "IUdp.hpp"

namespace RType::Client::Network {
    class SfmlUdpClient : public IUdp {
        public:
            SfmlUdpClient(unsigned int port);
            ~SfmlUdpClient() override = default;
            SfmlUdpClient(const SfmlUdpClient &other) noexcept = delete;
            SfmlUdpClient(SfmlUdpClient &&other) noexcept = delete;
            SfmlUdpClient &operator=(const SfmlUdpClient &other) noexcept = delete;
            SfmlUdpClient &operator=(SfmlUdpClient &&other) noexcept = delete;
            [[nodiscard]] bool send(void *toSend, size_t size, const std::string &ip, unsigned short port) noexcept override;
            [[nodiscard]] bool sendText(const std::string &toSend, const std::string &ip, unsigned short port) noexcept override;
            [[nodiscard]] std::optional<::RType::Network::RcvRequest> tryReceive() noexcept override;
        private:
            sf::UdpSocket _socket;
    };
}

#endif //RTYPE_SFMLUDPCLIENT_HPP
