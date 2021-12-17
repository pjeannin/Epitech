/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_SERVER_HPP__
#define __ASIO_SERVER_HPP__

#include "../network/tcpServer/ITcpServer.hpp"
#include "../user/IUser.hpp"
#include "commandManager/CommandManager.hpp"
#include "database/Database.hpp"

#include <vector>
#include <memory>

class Server : public ITcpServer::SocketEvent {
    public:
        explicit Server(int const port_);

        bool run();
        void handleNewConnection() final;
    private:
        ITcpServer *_tcpServer;
        std::shared_ptr<ArraySharedPtrT<IUser>> _users;
        std::shared_ptr<Babel::CommandManager> _commandManager;
        std::shared_ptr<Babel::Server::Database> _database;
};

#endif //__ASIO_SERVER_HPP__
