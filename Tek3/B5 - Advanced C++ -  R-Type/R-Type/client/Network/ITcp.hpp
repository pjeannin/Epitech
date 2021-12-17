/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Buy Airpods
*/

#ifndef BABEL_ITCP_HPP
#define BABEL_ITCP_HPP

#include <string>
#include "shared/Network/Requests.hpp"
#include "shared/utils/print.hpp"

namespace RType::Client::Network {
    class ITcp {
        public:
            enum Status {
                DISCONNECTED,
                CONNECTED
            };

            virtual ~ITcp() noexcept = default;
            [[nodiscard]] virtual bool connect(const std::string &ipAddress, unsigned short port) noexcept = 0;
            virtual void disconnect() noexcept = 0;
            [[nodiscard]] virtual bool send(void *toSend, size_t size) noexcept = 0;
            [[nodiscard]] virtual bool sendText(const std::string &toSend) noexcept = 0;
            [[nodiscard]] virtual std::optional<::RType::Network::RcvRequest> tryReceive() noexcept = 0;
            [[nodiscard]] virtual  Status getStatus() const noexcept = 0;
            [[nodiscard]] virtual uint16_t getPort() const noexcept = 0;
    };
}

#endif //BABEL_ITCP_HPP
