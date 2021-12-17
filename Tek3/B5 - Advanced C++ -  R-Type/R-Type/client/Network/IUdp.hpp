/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_IUDP_HPP
#define RTYPE_IUDP_HPP

#include "shared/Network/Requests.hpp"

namespace RType::Client::Network {
    class IUdp {
    public:
        virtual ~IUdp() noexcept = default;
        [[nodiscard]] virtual bool send(void *toSend, size_t size, const std::string &ip, unsigned short port) noexcept = 0;
        [[nodiscard]] virtual bool sendText(const std::string &toSend, const std::string &ip, unsigned short port) noexcept = 0;
        [[nodiscard]] virtual std::optional<::RType::Network::RcvRequest> tryReceive() noexcept = 0;
    };
}

#endif //RTYPE_IUDP_HPP
