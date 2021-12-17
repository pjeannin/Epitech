/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_ITCPSERVER_HPP__
#define __RTYPE_ITCPSERVER_HPP__

#include <cstdint>

namespace RType::Server::Network {
    class ITcpServer {
        public:
            virtual bool listen() noexcept = 0;
            virtual void stop() noexcept = 0;

            virtual ~ITcpServer() noexcept = default;
    };
}
#endif //__RTYPE_ITCPSERVER_HPP__
