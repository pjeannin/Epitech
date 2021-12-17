/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** LoopUdp.cpp
*/

#include <iostream>
#include "LoopUdp.hpp"

Babel::Client::Network::LoopUdp::LoopUdp(qint16 port, QObject *parent) : QObject(parent), _port(port)
{
    _socket = new QUdpSocket(this);
}

Babel::Client::Network::LoopUdp::~LoopUdp()
{
    delete _socket;
}

void Babel::Client::Network::LoopUdp::sendDatas(QByteArray buffer, quint16 targetPort, const std::string& targetIP)
{
    _socket->writeDatagram(buffer, QHostAddress(QString::fromStdString(targetIP)), targetPort);
}

Babel::Client::Network::IUdp::Datas *Babel::Client::Network::LoopUdp::getDatas() {
    if (_readedDatagrams.empty())
        return nullptr;
    QNetworkDatagram &datagram = _readedDatagrams.front();
    QByteArray byteArray = datagram.data();
    auto *dataPacket = new Datas();

    dataPacket->host = datagram.senderAddress().toString().toStdString();
    dataPacket->port = datagram.senderPort();
    dataPacket->datas = byteArray;
    _readedDatagrams.pop();
    return dataPacket;
}

void Babel::Client::Network::LoopUdp::LoopUdp::readDatas() {
    while (_socket->hasPendingDatagrams())
        _readedDatagrams.push(_socket->receiveDatagram());
}

void Babel::Client::Network::LoopUdp::bind() {
    _socket->bind(QHostAddress::AnyIPv4, _port);
}
