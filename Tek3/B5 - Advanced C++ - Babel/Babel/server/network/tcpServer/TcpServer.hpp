/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_TCPSERVER_HPP__
#define __ASIO_TCPSERVER_HPP__

#include <iostream>
#include <exception>
#include <asio.hpp>
#include <memory>
#include <list>

#include "../tcpClient/TcpClient.hpp"
#include "ITcpServer.hpp"

class TcpServer : public ITcpServer {
    public:
        explicit TcpServer(int const port_);
        ~TcpServer();

        void listen() final;
        void stop();
        void accept();
        void setSocketEvent(ITcpServer::SocketEvent *listener) final;
        TcpClient *createNewClient() final;
        void deleteClient() final;
    private:
        bool _running;
        asio::io_service _service;
        asio::signal_set _sig;
        asio::ip::tcp::acceptor *_acceptor;
        std::list<asio::ip::tcp::socket *> _sockets;
        ITcpServer::SocketEvent *_listener;
        uint16_t _port;
};

#endif //__ASIO_TCPSERVER_HPP__
