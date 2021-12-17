/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_IUDPSERVER_HPP__
#define __RTYPE_IUDPSERVER_HPP__

#include <cstdint>
#include <server/network/clientSession/IClientSession.hpp>

namespace RType::Server::Network {
    class IUdpServer {
        public:
            virtual bool listen() noexcept = 0;
            virtual void stop() noexcept = 0;
            virtual void send(void const *data, uint32_t size, EndPoint const &endpoint) noexcept = 0;

            virtual ~IUdpServer() noexcept = default;
        private:
    };
}

#endif //__RTYPE_IUDPSERVER_HPP__
