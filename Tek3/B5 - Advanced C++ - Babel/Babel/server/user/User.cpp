/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/

#include "User.hpp"
#include "commandManager/CommandManager.hpp"

#include <cstring>
#include <algorithm>

User::User(ITcpClient *tcpClient_, std::shared_ptr<Babel::CommandManager> commandManager_, std::shared_ptr<Babel::Server::Database> database_, std::shared_ptr<ArraySharedPtrT<IUser>> users_) :
    _id(0), _socket(tcpClient_), _commandManager(commandManager_), _database(database_), _users(users_)
{
    _socket->setSocketEvent(this);
}

void User::handleRcvBuffer()
{
    try {
        Babel::Request const &r = _socket->getRequest();
        if (r.magicCode == MAGIC_CODE)
            _commandManager->handle(this, r);
    } catch (Babel::CommandManager::Exception const &e) {
        std::cout << e.what() << std::endl;
    }
}

void User::initializeConnection(Babel::Request const &)
{
    send(InsCode::Server::ACCEPT_CONNECTION);
}

void User::signUp(Babel::Request const &r)
{
    Babel::ClientRegister const rdata = r.getStructArgs<Babel::ClientRegister>();

    try {
        char res = _database->checkIfAccountAlreadyExist(rdata.pseudo, rdata.email);
        if (res == 1)
            send(InsCode::Server::REGISTER_EMAIL_ALREADY_USED);
        else if (res == 2)
            send(InsCode::Server::REGISTER_USERNAME_ALREADY_USED);
        else {
            _database->addUser(rdata.pseudo, rdata.password, rdata.email);
            send(InsCode::Server::REGISTER_DONE);
            Babel::Server::user_t *userInfos = _database->getUserinfosByUsername(rdata.pseudo);
            _id = userInfos->id;
        }
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::signIn(Babel::Request const &r)
{
    Babel::ClientConnect const rdata = r.getStructArgs<Babel::ClientConnect>();

    try {
       Babel::Server::user_t *user = _database->getUserinfosByEmail(rdata.email);
       if (!user) {
           send(InsCode::Server::LOGIN_FAILED);
           return;
       }
       if (rdata.password == user->password && rdata.email == user->email) {
           Babel::ServerSucessfullyConnected data{.id = static_cast<unsigned int>(user->id)};
           std::memcpy(data.pseudo, user->username.c_str(), user->username.length());
           send(InsCode::Server::LOGIN_SUCCESS, &data, sizeof(data));
           _id = user->id;
       } else
           send(InsCode::Server::LOGIN_FAILED);
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::sendFriendRequest(Babel::Request const &r)
{
    try {
        Babel::Pseudo_t friendUsername(r.body);
        Babel::Server::user_t *friendInfos =_database->getUserinfosByUsername(friendUsername.val);
        Babel::Server::user_t *me =_database->getUserInfos(_id);

        if (!friendInfos || friendInfos->id == _id)
            return;
        if (_database->checkIfAccountAlreadyExist(friendInfos->username, friendInfos->email)) {
            if (_database->isFriend(friendInfos->id, _id)) {
                send(InsCode::SEND_FRIEND_REQUEST_ALREADY_FRIEND);
            } else if (_database->isFriendRequestAlreadySend(_id, friendInfos->id)) {
                return;
            } else {
                _database->addFriendRequest(me->id, friendInfos->id);
                Babel::Pseudo_t myUsername(me->username);
                sendToAnother(friendInfos->id, InsCode::TRANSMIT_FRIEND_REQUEST, &myUsername, sizeof(myUsername));
                send(InsCode::SEND_FRIEND_REQUEST_SUCCESS);
            }
        } else
            send(InsCode::SEND_FRIEND_REQUEST_PSEUDO_UNKNOWN);
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::handleFriendRequestResponse(Babel::Request const &r)
{
    try {
        Babel::Pseudo_t friendUsername(r.body);
        Babel::Server::user_t *friendInfos =_database->getUserinfosByUsername(std::string(friendUsername.val));
        Babel::Server::user_t *me =_database->getUserInfos(_id);

        _database->removeFriendRequest(friendInfos->id, me->id);
        Babel::Pseudo_t myPseudo(me->username);
        if (r.ins == InsCode::Client::RECEIVE_FRIEND_REQUEST_ACCEPT) {
            _database->addFriend(friendInfos->id, me->id);
            sendToAnother(friendInfos->id, InsCode::Server::SEND_ACCEPT_FIREND_REQUEST, &myPseudo, sizeof(myPseudo));
        } else
            sendToAnother(friendInfos->id, InsCode::Server::SEND_REFUSE_FRIEND_REQUEST, &myPseudo, sizeof(myPseudo));
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::askFriendCalling(Babel::Request const &r)
{
    try {
        Babel::ClientCall rdata = r.getStructArgs<Babel::ClientCall>();

        if (_database->isAccountExistByUsername(rdata.pseudo)) {
            Babel::Server::user_t *friendInfos = _database->getUserinfosByUsername(rdata.pseudo);
            Babel::Server::user_t *me = _database->getUserInfos(_id);
            if (_database->isFriend(_id, friendInfos->id)) {
                if (std::find_if(_users->begin(), _users->end(), [&](std::shared_ptr<IUser> const &user){ return user->getId() == friendInfos->id; }) == _users->end())
                    send(InsCode::FRIEND_CALLING_FAILED);
                Babel::ServerCall data(getIp().c_str(), 4001, me->username.c_str());
                sendToAnother(friendInfos->id, InsCode::Server::INCOMMING_CALL, &data, sizeof(data));
            } else
                send(InsCode::FRIEND_CALLING_FAILED);
        } else
            send(InsCode::FRIEND_CALLING_FAILED);
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::handleCallResponse(Babel::Request const &r)
{
    try {
        Babel::ClientCall rdata = r.getStructArgs<Babel::ClientCall>();
        Babel::Server::user_t *target = _database->getUserinfosByUsername(rdata.pseudo);
        Babel::Server::user_t *me = _database->getUserInfos(_id);

        if (!target) {
            send(InsCode::Special::FAILED);
            return;
        }
        if (r.ins == InsCode::ACCEPT_CALL) {
            Babel::ServerCall data(getIp().c_str(), 4001, rdata.pseudo);
            sendToAnother(target->id, InsCode::FRIEND_CALLING_SUCCESS, &data, sizeof(data));
        } else {
            sendToAnother(target->id, InsCode::FRIEND_CALLING_FAILED, rdata.pseudo, sizeof(rdata.pseudo));
        }
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::terminateCall(Babel::Request const &r)
{
    try {
        Babel::Pseudo_t pseudo(r.body);
        Babel::Server::user_t *target = _database->getUserinfosByUsername(pseudo.val);
        Babel::Server::user_t *me = _database->getUserInfos(_id);

        if (!target) {
            send(InsCode::Special::FAILED);
            return;
        }
        sendToAnother(target->id, InsCode::Server::SEND_END_CALL, &pseudo, sizeof(pseudo));
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::sendMessage(Babel::Request const &r)
{
    try {
        Babel::OneMessage rdata = r.getStructArgs<Babel::OneMessage>();
        Babel::Server::user_t *friendInfos = _database->getUserinfosByUsername(rdata.pseudo);
        Babel::Server::user_t *me = _database->getUserInfos(_id);

        if (!friendInfos) {
            send(InsCode::Server::SEND_MESSAGE_FAILED);
        } else {
            if (friendInfos->id == me->id)
                return;
            _database->addMessage(_id, friendInfos->id, newTimeStamp(), std::string(rdata.body));
            std::strncpy(rdata.pseudo, me->username.c_str(), sizeof(rdata.pseudo));
            sendToAnother(friendInfos->id, InsCode::Server::RECEIVE_MESSAGE, &rdata, sizeof(rdata));
            send(InsCode::Server::SEND_MESSAGE_SUCCESS);
        }
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::askMessageHistory(Babel::Request const &r)
{
    try {
        Babel::Pseudo_t friendUsermane(r.body);
        Babel::Server::user_t *friendInfos = _database->getUserinfosByUsername(friendUsermane.val);

        if (friendInfos) {
            std::vector<Babel::Server::message_t *> *messages = _database->getMessage(_id, friendInfos->id);
            Babel::MessagesHistory msgHeader;
            msgHeader.nbMessage = messages->size();
            std::strncpy(msgHeader.pseudo, friendInfos->username.c_str(), sizeof(msgHeader.pseudo));

            size_t size = sizeof(msgHeader) + (messages->size() * sizeof(Babel::MessageDatas));
            char *data = new char[size];
//            char data[100000];
            memset(data, 0, size);
            std::memcpy(data, &msgHeader, sizeof(msgHeader));
            Babel::MessageDatas msg;
            char *i = data + sizeof(msgHeader);
            for (Babel::Server::message_t const *msg_ : *messages) {
                std::memset(&msg, 0, sizeof(Babel::MessageDatas));
                msg.id = msg_->from_id;
                std::strcpy(msg.body, msg_->message.c_str());
                std::memcpy(i, &msg, sizeof(msg));
                i += sizeof(Babel::MessageDatas);
            }
            send(InsCode::Server::SEND_MESSAGE_HISTORY, data, size);
            delete[] data;
        }
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::askFriendList(Babel::Request const &r)
{
    try {
        std::vector<std::string> *friends = _database->getFriends(_id);
        std::size_t const size = sizeof(int) + friends->size() * sizeof(Babel::Pseudo);
        char *data = new char[size];
        uint32_t nbFriends = friends->size();
        std::memcpy(data, &nbFriends, sizeof(uint32_t));
        char *i = data + sizeof(int);
        for (std::string const &pseudo : *friends) {
            std::strncpy(i, pseudo.c_str(), sizeof(Babel::Pseudo));
            i += sizeof(Babel::Pseudo);
        }
        send(InsCode::Server::SEND_FRIEND_LIST, data, size);
        delete[] data;
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::askFriendRequest(Babel::Request const &)
{
    try {
        std::vector<std::string> *friendsRequests = _database->getFriendsRequests(_id);
        std::size_t const size = sizeof(int) + friendsRequests->size() * sizeof(Babel::Pseudo);
        char *data = new char[size];
        uint32_t nbFriends = friendsRequests->size();
        std::memcpy(data, &nbFriends, sizeof(uint32_t));
        char *i = data + sizeof(int);
        for (std::string const &pseudo : *friendsRequests) {
            std::strncpy(i, pseudo.c_str(), sizeof(Babel::Pseudo));
            i += sizeof(Babel::Pseudo);
        }
        send(InsCode::Server::SEND_FRIEND_REQUEST_LIST, data, size);
        delete[] data;
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}


void User::sendToAnotherWithUsername(std::string const &username, unsigned char const ins, void *body, std::size_t const bodySize)
{
    try {
        Babel::Server::user_t *friendInfos = _database->getUserinfosByUsername(username);

        auto const it = std::find_if(_users->begin(), _users->end(), [&](std::shared_ptr<IUser> const &user){
            return user->getId() == friendInfos->id;
        });
        if (it != _users->end()) {
            (*it)->send(ins, body, bodySize);
        }
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

void User::send(uint8_t const ins, void *body, std::size_t const bodySize)
{
    Babel::Header header(ins);
    std::size_t const size = HEADER_SIZE + bodySize;
    char *toSend = new char[size];
    std::memcpy(toSend, &header, HEADER_SIZE);
    if (bodySize)
        std::memcpy(&toSend[HEADER_SIZE], static_cast<char *>(body), bodySize);
    _socket->addToMessageQueue(Babel::Message{.request = new std::string(toSend, size), .size = size});
    delete[] toSend;
}

void User::sendToAnother(size_t const id, unsigned char const ins, void *body, std::size_t const bodySize)
{
    try {
        auto const it = std::find_if(_users->begin(), _users->end(), [&](std::shared_ptr<IUser> const &user){
            return user->getId() == id;
        });
        if (it != _users->end()) {
            (*it)->send(ins, body, bodySize);
        }
    } catch (Babel::Server::DatabaseException const &e) {
        std::cout << e.what() << std::endl;
        send(InsCode::Special::FAILED);
    }
}

std::size_t User::getId() const
{
    return _id;
}

void User::setId(std::size_t const id)
{
    _id = id;
}

std::string User::getIp() const
{
    return _socket->getIp();
}

void User::close()
{
    std::cout << "close user" << std::endl;
    std::vector<std::shared_ptr<IUser>>::iterator it = _users->begin();
    for (; it != _users->end(); ++it) {
        if (it->get() == this)
            break;
    }
    if (it != _users->end())
        _users->erase(it);
}

User::~User()
{
    close();
}
