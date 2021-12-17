/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Tcp.hpp
*/

#ifndef BABEL_TCP_HPP
#define BABEL_TCP_HPP

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <string>
#include "ITcp.hpp"

namespace Babel::Client::Network {
            class Tcp : public QObject, public ITcp {
                Q_OBJECT
                public:
                    explicit Tcp(QObject *parent = nullptr, int port = 4242, const std::string &ip = *new std::string("127.0.0.1"));
                    void Connect() override ;
                    void WriteBytes(QByteArray datas) const override ;
                    char *ReadSomething() const override ;
                    bool getStatus() const override ;
                    QByteArray const &getData() const final;
                signals:
                    void dataAvailable();
                public slots:
                    void connected();
                    void disconnected();
                    void bytesWritten(qint64 bytes);
                    void readyRead();
                private:
                    QTcpSocket *socket{};
                    int port;
                    const std::string &ip;
                    bool status;
                    QByteArray datas;
            };
        }


#endif //BABEL_TCP_HPP
