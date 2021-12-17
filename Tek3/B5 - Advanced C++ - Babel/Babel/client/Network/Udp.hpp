/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Udp.hpp
*/

#ifndef BABEL_UDP_HPP
#define BABEL_UDP_HPP

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <string>
#include <vector>
#include <queue>
#include "IUdp.hpp"

namespace Babel::Client::Network {
            class Udp : public QObject, public IUdp {
                Q_OBJECT
                public:
                    explicit Udp(qint16 port, QObject *parent = nullptr);
                    void sendMessage(const std::string &msg) ;
                    void sendMessage(char *buffer) ;
                    void sendMessage(QByteArray buffer);
                    IUdp::Datas getData() ;
                signals:
                    void dataAvailable();
                public slots:
                    void readyRead();
                protected:
                private:
                    QUdpSocket *_socket;
                    std::queue<QNetworkDatagram> readedDatagrams;
                    qint16 _port;
            };
        }


#endif //BABEL_UDP_HPP
