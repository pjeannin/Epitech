/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** ClientSocket.hpp
*/
#ifndef BABEL_CLIENTSOCKET_HPP
#define BABEL_CLIENTSOCKET_HPP

#include <string>
#include <map>
#include <iostream>
#include <exception>
#include <algorithm>
#include "client/Utils/Utils.hpp"
#include "../shared_include/include.hpp"
#include "client/Network/Tcp.hpp"
#include "UI/ui_mainwindow.h"
#include "UI/IMainWindow.hpp"
#include "../shared_files/commandManager/CommandManager.hpp"
#include "client/Encrypt/Encrypt.hpp"
#include "client/Thread/Thread.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[96m"
#define RESET "\033[0m"
#define CLIENT_EVENT "[" << GREEN << "CLIENT SENT"  << RESET << "] : (" << (int)header.ins << ")"
#define SERVER_EVENT "[" << BLUE << "SERVER SENT"  << RESET << "] : (" << (int)((unsigned char)header.ins) << ")"
#define UNKNOWN_EVENT "[" << RED << "UNKNOWN EVENT"  << RESET << "] : supposed code : (" << (int)((unsigned char)cmd[0]) << ") all request :(" << cmd.toStdString() << ")"

namespace Babel::Client {

        struct callMember {
            std::string pseudo;
            std::string ip;
            unsigned short port;
        };

        class Client : public QObject {
            Q_OBJECT
            public:
                explicit Client(Ui_MainWindow *ui, IMainWindow *window, int port = 3001, const std::string &ip = *new std::string("10.14.47.227"));

                void sendConnect() const;
                void sendSubscribe(const std::string &email, const std::string &pseudo, const std::string &password) const;
                void sendConnection(const std::string &mail, const std::string &password) const;
                void sendFriendRequest(const std::string &pseudo) const;
                void sendAcceptFriendRequest(const std::string &pseudo);
                void sendRefuseFriendRequest(const std::string &pseudo);
                void sendCall(const std::string &pseudo);
                void sendAcceptCall(const std::string &pseudo);
                void sendRefuseCall(const std::string &pseudo) const;
                void sendEndCall();
                void sendMessage(const std::string &pseudo, const std::string &msg) const;
                void sendAskFriendsList() const;
                void sendAskFriendsRequestList() const;
                void sendAskMessagesHistory(const std::string &pseudo) const;
                void initCall();
            protected:
            private:
                using serverFunctions = void (Client::*)(const char *);
                std::string _pseudo;
                unsigned int _id;
                Network::Tcp _tcpSocket;
                std::map<unsigned char, serverFunctions> _functionsTab;
                bool _connectedToServer;
                bool _inCall;
                bool _connected;
                Ui_MainWindow *_ui;
                IMainWindow *_window;
                callMember _callMember;
                Thread *_thread;
                Thread *_thread2;
                std::vector<std::string> _pendingFriendsRequests;

                void successfullyConnectedtoServer(const char *args);
                void successfullyRegisterd(const char *args);
                void emailAlreadyUsed(const char *args);
                void pseudoAlreadyUsed(const char *args);
                void successfullyConnected(const char *args);
                void incorrectConnexionInformations(const char *args);
                void friendRequestSucessfullySent(const char *args);
                void unknownUser(const char *args);
                void alreadyFriends(const char *args);
                void friendsRequestRecieved(const char *args);
                void incomingCall(const char *args);
                void getUserInfos(const char *args);
                void cantCallUser(const char *args);
                void endCall(const char *args);
                void messageRecieved(const char *args);
                void messageSendingSucced(const char *args);
                void messageSendingFailed(const char *args);
                void messagesHistory(const char *args);
                void allFriends(const char *args);
                void allFriendsRequests(const char *args);
                void acceptedFriendRequest(const char *args);
                void refusedFriendRequest(const char *args);
            private slots:
                void onDataAvailable();
        };
    }


#endif //BABEL_CLIENTSOCKET_HPP
