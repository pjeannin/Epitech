/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#include "Server.hpp"
#include "../network/tcpServer/TcpServer.hpp"
#include "../user/User.hpp"

Server::Server(int const port_) : _tcpServer(new TcpServer(port_)), _users(std::make_shared<ArraySharedPtrT<IUser>>()), _commandManager(std::make_shared<Babel::CommandManager>()), _database(std::make_shared<Babel::Server::Database>("babel"))
{
    _tcpServer->setSocketEvent(this);
}

bool Server::run()
{
    _tcpServer->listen();
    return false;
}

void Server::handleNewConnection()
{
    std::cout << "New tcpClient connected" << std::endl;
    _users->push_back(std::make_shared<User>(_tcpServer->createNewClient(), _commandManager, _database, _users));
}

