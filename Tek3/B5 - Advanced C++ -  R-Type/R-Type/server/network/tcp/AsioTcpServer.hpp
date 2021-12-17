/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Babel
*/


#ifndef __BABEL_ASIOTCPSERVER_HPP__
#define __BABEL_ASIOTCPSERVER_HPP__

#include "ITcpServer.hpp"

#include <asio.hpp>
#include <list>
#include <server/Server.hpp>
#include <server/network/network.hpp>

namespace RType::Server::Network {
    class AsioTcpServer : public RType::Server::Network::ITcpServer {
        public:
            static std::unique_ptr<AsioTcpServer> create(::Port const port, std::shared_ptr<Server> server) noexcept;
            explicit AsioTcpServer(::Port const port, std::shared_ptr<Server> server) noexcept;
            ~AsioTcpServer() noexcept override;
            AsioTcpServer(const AsioTcpServer &other) noexcept = delete;
            AsioTcpServer(AsioTcpServer &&other) noexcept = delete;
            AsioTcpServer &operator=(const AsioTcpServer &other) noexcept = delete;
            AsioTcpServer &operator=(AsioTcpServer &&other) noexcept = delete;

            void stop() noexcept final;
            void acceptNewConnection();
            asio::io_context &getContext() noexcept;
            bool listen() noexcept final;
        private:
            ::Port _port;
            asio::io_context _context;
//            asio::signal_set _signals;
            asio::ip::tcp::endpoint _endpoint;
            asio::ip::tcp::acceptor _acceptor;
            std::shared_ptr<RType::Server::Server> _server;
    };
}
#endif //__BABEL_ASIOTCPSERVER_HPP__
