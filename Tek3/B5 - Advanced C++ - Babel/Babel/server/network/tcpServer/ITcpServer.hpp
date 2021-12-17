/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_ITCPSERVER_HPP__
#define __ASIO_ITCPSERVER_HPP__

#include "../tcpClient/ITcpClient.hpp"

class ITcpServer {
    public:
        class SocketEvent {
            public:
                virtual void handleNewConnection() = 0;
        };

        virtual ITcpClient *createNewClient() = 0;
        virtual void setSocketEvent(ITcpServer::SocketEvent *listener) = 0;
        virtual void listen() = 0;
        virtual void deleteClient() = 0;

};

#endif //__ASIO_ITCPSERVER_HPP__
