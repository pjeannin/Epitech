/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Tcp.cpp
*/

#include <iostream>
#include "Tcp.hpp"

Babel::Client::Network::Tcp::Tcp(QObject *parent, int port, const std::string &ip) : QObject(parent), port(port), ip(ip), status(false)
{
}

void Babel::Client::Network::Tcp::Connect()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    socket->connectToHost(QString::fromStdString(ip), port);
    if (!socket->waitForConnected(3000))
        std::cout << "[TCP] : Can't connect to server\n" << std::endl;
}

void Babel::Client::Network::Tcp::WriteBytes(QByteArray datas) const
{
    socket->write(datas);
    socket->waitForBytesWritten();
}

char *Babel::Client::Network::Tcp::ReadSomething() const
{
    socket->waitForReadyRead(3000);

    return (socket->readAll().data());
}

bool Babel::Client::Network::Tcp::getStatus() const { return status; }

#include "include.hpp"

void Babel::Client::Network::Tcp::readyRead() {
    socket->waitForReadyRead(250);
    datas = socket->readAll();
    emit dataAvailable();
}

void Babel::Client::Network::Tcp::bytesWritten(qint64 bytes) {

}

void Babel::Client::Network::Tcp::disconnected() {
    std::cout << "[TCP] : Disconnected" << std::endl;
    status = false;
}

void Babel::Client::Network::Tcp::connected() {
    status = true;
    std::cout << "[TCP] : Connected" << std::endl;
}

QByteArray const &Babel::Client::Network::Tcp::getData() const {
    return datas;
}
