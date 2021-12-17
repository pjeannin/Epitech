/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Buy Airpods
*/

#ifndef BABEL_SFMLTCPCLIENT_HPP
#define BABEL_SFMLTCPCLIENT_HPP

#include <SFML/Network.hpp>
#include "ITcp.hpp"

namespace RType::Client::Network {
    class SfmlTcpClient : public ITcp {
        public:
            explicit SfmlTcpClient() noexcept;
            ~SfmlTcpClient() override = default;
            SfmlTcpClient(const SfmlTcpClient &other) noexcept = delete;
            SfmlTcpClient(SfmlTcpClient &&other) noexcept = delete;
            SfmlTcpClient &operator=(const SfmlTcpClient &other) noexcept = delete;
            SfmlTcpClient &operator=(SfmlTcpClient &&other) noexcept = delete;
            [[nodiscard]] bool connect(const std::string &ipAddress, unsigned short port) noexcept override;
            void disconnect() noexcept override;
            [[nodiscard]] bool send(void *toSend, size_t size) noexcept override;
            [[nodiscard]] bool sendText(const std::string &message) noexcept override;
            [[nodiscard]] std::optional<::RType::Network::RcvRequest> tryReceive() noexcept override;
            [[nodiscard]] Status getStatus() const noexcept override;
            [[nodiscard]] uint16_t getPort() const noexcept final;
        private:
            sf::TcpSocket _socket;
            Status _status;
            sf::SocketSelector _selector;
            std::string _ipAddress;
            unsigned short _port;
        };
}

#endif //BABEL_SFMLTCPCLIENT_HPP
