/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Udp.cpp
*/

#include <iostream>
#include "Udp.hpp"

Babel::Client::Network::Udp::Udp(qint16 port, QObject *parent) : QObject(parent), _port(port)
{
    _socket = new QUdpSocket(this);
    _socket->bind(QHostAddress::LocalHost, _port);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Babel::Client::Network::Udp::readyRead() {
    while (_socket->hasPendingDatagrams()) {
        this->readedDatagrams.push(_socket->receiveDatagram());
        emit this->dataAvailable();
    }
}

void Babel::Client::Network::Udp::sendMessage(const std::string &msg) {
    QByteArray buf;
    buf.append(msg.c_str());

    _socket->writeDatagram(buf, QHostAddress::LocalHost, 4343);
}

void Babel::Client::Network::Udp::sendMessage(char *buffer) {
    _socket->writeDatagram(buffer, QHostAddress::LocalHost, 4343);
}

void Babel::Client::Network::Udp::sendMessage(QByteArray buffer) {
    _socket->writeDatagram(buffer, QHostAddress::LocalHost, 4343);
}

Babel::Client::Network::IUdp::Datas Babel::Client::Network::Udp::getData() {
    QNetworkDatagram &datagram = readedDatagrams.front();
    QByteArray byteArray = datagram.data();
    IUdp::Datas dataPacket;

    dataPacket.host = datagram.senderAddress().toString().toStdString();
    dataPacket.port = datagram.senderPort();
    dataPacket.datas = byteArray;
    this->readedDatagrams.pop();
    return dataPacket;
}
