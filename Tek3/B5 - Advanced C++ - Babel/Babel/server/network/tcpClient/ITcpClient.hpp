/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_ITCPCLIENT_HPP__
#define __ASIO_ITCPCLIENT_HPP__

#include "include.hpp"

class ITcpClient {
    public:
        class SocketEvent {
            public:
                explicit SocketEvent() = default;
                ~SocketEvent() = default;
                virtual void handleRcvBuffer() = 0;
                virtual void close() = 0;
        };
        virtual ~ITcpClient() {};
        virtual void setSocketEvent(ITcpClient::SocketEvent *listener) = 0;
        virtual Babel::Request const &getRequest() = 0;
        virtual void addToMessageQueue(Babel::Message const &msg) = 0;
        virtual std::string const getIp() const = 0;
};

#endif //__ASIO_ITCPCLIENT_HPP__
