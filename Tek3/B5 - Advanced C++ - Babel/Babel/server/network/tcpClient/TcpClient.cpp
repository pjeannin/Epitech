/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/

#include "TcpClient.hpp"

#include <iostream>
#include <functional>

TcpClient::TcpClient(asio::ip::tcp::socket *socket_) : _socket(socket_), _listener(nullptr)
{
    _request.body = nullptr;
    startToReceive();
}

void TcpClient::setSocketEvent(ITcpClient::SocketEvent *listener_)
{
    _listener = listener_;
}

void TcpClient::startToReceive()
{
    char _readBuffer[BUFFER_SIZE] = {0};
    _socket->async_receive(asio::buffer(_readBuffer, BUFFER_SIZE), [&](std::error_code const &err, std::size_t const bytesTransfered) {
        if (!err) {
            if (bytesTransfered > 0) {
                std::string const buffer(_readBuffer, bytesTransfered);
                memcpy(&_request, buffer.c_str(), HEADER_SIZE);
                if (bytesTransfered - HEADER_SIZE > 0) {
                    _request.body = new char[bytesTransfered - HEADER_SIZE];
                    std::memcpy(_request.body, buffer.c_str() + HEADER_SIZE, buffer.length() - HEADER_SIZE);
                } else
                    _request.body = nullptr;
                if (_listener) {
                    _request.dump();
                    _listener->handleRcvBuffer();
                    delete _request.body;
                }
            }
            startToReceive();
        } else {
            std::cout << ERROR_PRINT << "tcpClient failed to async receive: " << err.message() << std::endl;
            close();
        }
    });
}

void TcpClient::close() noexcept
{
    std::cout << OK_PRINT << "stop a tcpClient" << std::endl;
    if (_socket) {
        _socket->close();
        delete _socket;
    }
    delete this;
}

TcpClient::~TcpClient()
{
    _listener->close();
}

Babel::Request const &TcpClient::getRequest()
{
    return _request;
}

void TcpClient::addToMessageQueue(Babel::Message const &msg)
{
    std::scoped_lock lock(_m); {
        if (msg.size <= 0)
            return;
        _msgs.push(msg);
        if (!_msgs.empty()) {
            //std::bind(&TcpClient::sendMessageInQueue, this, std::placeholders::_1, std::placeholders::_2)
            asio::async_write(*_socket, asio::buffer(*msg.request, msg.size), [&](std::error_code const &err, std::size_t const bytesTransfered){
                sendMessageInQueue(err, bytesTransfered);
            });
        }
    }
}

std::string const TcpClient::getIp() const
{
    std::cout << "client ip: " << _socket->remote_endpoint().address().to_string() << std::endl;
    return _socket->remote_endpoint().address().to_string();
}

void TcpClient::sendMessageInQueue(std::error_code const &err, std::size_t const bytesTransfered)
{
    if (err) {
        std::cout << ERROR_PRINT << "async_write failed: " << err.message() << std::endl;
        return;
    }
    std::scoped_lock lock(_m); {
        Babel::Message &msg = _msgs.front();
        if (bytesTransfered >= msg.size) {
            _msgs.pop();
            msg = _msgs.front();
        } else {
            msg.size -= bytesTransfered;
            msg.request->erase(0, bytesTransfered);
        }
        if (!_msgs.empty()) {
            asio::async_write(*_socket, asio::buffer(msg.request, msg.size), [&](std::error_code const &err, std::size_t const bytesTransfered){
                sendMessageInQueue(err, bytesTransfered);
            });
        }
    }
}
