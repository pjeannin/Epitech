/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#include "TcpServer.hpp"
#include "include.hpp"

TcpServer::TcpServer(int const port_) : _running(false), _sig(_service, SIGTERM, SIGINT), _acceptor(nullptr), _listener(nullptr), _port(port_)
{}

TcpServer::~TcpServer()
{
    _running = false;
    stop();
}

void TcpServer::stop()
{
    _running = false;
    _service.stop();
}

void TcpServer::listen()
{
    asio::ip::tcp::endpoint endPoint(asio::ip::tcp::v4(), _port);
    _acceptor = new asio::ip::tcp::acceptor(_service, endPoint);
    std::cout << OK_PRINT << "Listening on port: " << endPoint .address().to_string() << ":" << _port << std::endl;
    std::cout <<"Waiting for connection ..." << std::endl;
    _running = true;
    accept();
    _service.run();
}

void TcpServer::accept()
{
    if (!_running)
        return;
    _sockets.push_back(new asio::ip::tcp::socket(_service));
    _acceptor->async_accept(*_sockets.back(), [&](const asio::error_code &error) {
        if (!_running)
            return;
        if (error)
            std::cout << "Failed to accept connection: " << error.message() << std::endl;
        else
            _listener->handleNewConnection();
        accept();
    });
}

void TcpServer::setSocketEvent(ITcpServer::SocketEvent *listener_)
{
    _listener = listener_;
}

TcpClient *TcpServer::createNewClient()
{
    TcpClient *client = new TcpClient(_sockets.front());
    _sockets.pop_front();
    return client;
}

void TcpServer::deleteClient()
{

}
