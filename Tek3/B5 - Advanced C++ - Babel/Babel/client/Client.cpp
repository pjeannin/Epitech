/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** ClientSocket.cpp
*/

#include "Client.hpp"

std::vector<std::string> &splitString(std::string string, const std::string& delim) {
    auto *result = new std::vector<std::string>();
    size_t pos = 0;

    while ((pos = string.find(delim)) != std::string::npos) {
        result->push_back(string.substr(0, pos));
        string.erase(0, pos + delim.length());
    }
    result->push_back(string);
    return *result;
}

Babel::Client::Client::Client(Ui_MainWindow *ui, IMainWindow *window, int port, const std::string &ip) : _tcpSocket(nullptr, port, ip), _functionsTab({
           {InsCode::ACCEPT_CONNECTION, &Client::successfullyConnectedtoServer},
           {InsCode::REGISTER_DONE, &Client::successfullyRegisterd},
           {InsCode::REGISTER_EMAIL_ALREADY_USED, &Client::emailAlreadyUsed},
           {InsCode::REGISTER_USERNAME_ALREADY_USED, &Client::pseudoAlreadyUsed},
           {InsCode::LOGIN_SUCCESS, &Client::successfullyConnected},
           {InsCode::LOGIN_FAILED, &Client::incorrectConnexionInformations},
           {InsCode::SEND_FRIEND_REQUEST_SUCCESS, &Client::friendRequestSucessfullySent},
           {InsCode::SEND_FRIEND_REQUEST_PSEUDO_UNKNOWN, &Client::unknownUser},
           {InsCode::SEND_FRIEND_REQUEST_ALREADY_FRIEND, &Client::alreadyFriends},
           {InsCode::TRANSMIT_FRIEND_REQUEST, &Client::friendsRequestRecieved},
           {InsCode::FRIEND_CALLING_SUCCESS, &Client::getUserInfos},
           {InsCode::FRIEND_CALLING_FAILED, &Client::cantCallUser},
           {InsCode::INCOMMING_CALL, &Client::incomingCall},
           {InsCode::SEND_END_CALL, &Client::endCall},
           {InsCode::RECEIVE_MESSAGE, &Client::messageRecieved},
           {InsCode::SEND_MESSAGE_SUCCESS, &Client::messageSendingSucced},
           {InsCode::SEND_MESSAGE_FAILED, &Client::messageSendingFailed},
           {InsCode::SEND_MESSAGE_HISTORY, &Client::messagesHistory},
           {InsCode::SEND_FRIEND_LIST, &Client::allFriends},
           {InsCode::SEND_FRIEND_REQUEST_LIST, &Client::allFriendsRequests},
           {InsCode::SEND_ACCEPT_FIREND_REQUEST, &Client::acceptedFriendRequest},
           {InsCode::SEND_REFUSE_FRIEND_REQUEST, &Client::refusedFriendRequest}}), _connectedToServer(false), _connected(false), _ui(ui), _window(window), _inCall(false)
{
    _tcpSocket.Connect();
    connect(dynamic_cast<QObject *>(&_tcpSocket), SIGNAL(dataAvailable()), this, SLOT(onDataAvailable()));
    sendConnect();
}

void Babel::Client::Client::sendConnect() const
{
    Babel::Header header(InsCode::INIT_CONNECTION);
    char toSend[sizeof(header)];

    memcpy(toSend, &header, sizeof(header));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header)));
    std::cout << CLIENT_EVENT << std::endl;
}

void  Babel::Client::Client::sendSubscribe(const std::string &email, const std::string &pseudo, const std::string &password) const
{
    Header header(InsCode::REGISTER);
    ClientRegister datas{};
    strcpy(datas.email, email.c_str());
    strcpy(datas.pseudo, pseudo.c_str());
    strcpy(datas.password, Encryption::encrypt(password, email).c_str());
    char toSend[sizeof(header) + sizeof(datas)];

    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas.pseudo << "] email : [" << datas.email << "] password : [" << datas.password << "]" << std::endl;
}

void  Babel::Client::Client::sendConnection(const std::string &mail, const std::string &password) const
{
    Header header(InsCode::Client::LOGIN);
    ClientConnect datas{};
    strcpy(datas.email, mail.c_str());
    strcpy(datas.password, Encryption::encrypt(password, mail).c_str());
    char toSend[sizeof(header) + sizeof(datas)];

    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " email : [" << datas.email << "] password : [" << datas.password << "]" << std::endl;
}

void  Babel::Client::Client::sendFriendRequest(const std::string &pseudo) const
{
    Header header(InsCode::SEND_FRIEND_REQUEST);
    Pseudo datas;
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas, pseudo.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    if (pseudo == _pseudo)
        return;
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas << "]" << std::endl;
}

void  Babel::Client::Client::sendAcceptFriendRequest(const std::string &pseudo)
{
    Header header(InsCode::RECEIVE_FRIEND_REQUEST_ACCEPT);
    Pseudo datas;
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas, pseudo.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    if (pseudo == _pseudo)
        return;
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas << "]" << std::endl;
    _window->addContactToList(const_cast<std::string &>(pseudo));

    if (!_pendingFriendsRequests.empty()) {
        _ui->label_name_friend_request->setText(QString::fromStdString(_pendingFriendsRequests.back()));
        _ui->frame_deco_friend_request->show();
        _pendingFriendsRequests.pop_back();
    }
}

void  Babel::Client::Client::sendRefuseFriendRequest(const std::string &pseudo)
{
    Header header(InsCode::RECEIVE_FRIEND_REQUEST_REFUSE);
    Pseudo datas;
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas, pseudo.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    if (pseudo == _pseudo)
        return;
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas << "]" << std::endl;

    if (!_pendingFriendsRequests.empty()) {
        _ui->label_name_friend_request->setText(QString::fromStdString(_pendingFriendsRequests.back()));
        _ui->frame_deco_friend_request->show();
        _pendingFriendsRequests.pop_back();
    }
}

void  Babel::Client::Client::sendCall(const std::string &pseudo)
{
    Header header(InsCode::ASK_FRIEND_CALLING);
    ClientCall datas{.port = 4001};
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas.pseudo, pseudo.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas.pseudo << "] port : [" << datas.port << "]" << std::endl;
    _callMember.pseudo = *new std::string(pseudo);
}

void Babel::Client::Client::sendAcceptCall(const std::string &pseudo)
{
    Header header(InsCode::ACCEPT_CALL);
    Pseudo datas;
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas, pseudo.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas << "]" << std::endl;
    initCall();
    _ui->message_box->setGeometry(0, 200, 1471, 621);
    _ui->icon_contact_select->setGeometry(40, 20, 51, 51);
    _ui->label_nom_contact_select->setGeometry(100, 20, 250, 51);
    _ui->call_box->show();
    _ui->btn_appel->hide();
    _ui->caller_2->setIcon(_ui->icon_contact_select->icon());
}

void Babel::Client::Client::sendRefuseCall(const std::string &pseudo) const
{
    Header header(InsCode::REFUSE_CALL);
    Pseudo datas;
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas, pseudo.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas << "]" << std::endl;
}

void Babel::Client::Client::sendEndCall()
{
    Header header(InsCode::TERMINATE_CALL);
    Pseudo datas;
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas, _callMember.pseudo.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas << "]" << std::endl;
}

void Babel::Client::Client::sendMessage(const std::string &pseudo, const std::string &msg) const
{
    Header header(InsCode::SEND_MESSAGE);
    OneMessage datas{};
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas.pseudo, pseudo.c_str());
    strcpy(datas.body, msg.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    std::cout << datas.pseudo << " " << datas.body << std::endl;
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas.pseudo << "] message body : [" << datas.body << "]" << std::endl;
}

void Babel::Client::Client::sendAskFriendsList() const {
    Header header(InsCode::ASK_FRIEND_LIST);
    char toSend[sizeof(header)];

    memcpy(toSend, &header, sizeof(header));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) ));
    std::cout << CLIENT_EVENT << std::endl;
}

void Babel::Client::Client::sendAskFriendsRequestList() const {
    Header header(InsCode::ASK_FRIEND_REQUEST_LIST);
    char toSend[sizeof(header)];

    memcpy(toSend, &header, sizeof(header));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header)));
    std::cout << CLIENT_EVENT << std::endl;
}

void Babel::Client::Client::sendAskMessagesHistory(const std::string &pseudo) const {
    Header header(InsCode::ASK_MESSAGE_HISTORY);
    Pseudo datas;
    char toSend[sizeof(header) + sizeof(datas)];

    strcpy(datas, pseudo.c_str());
    memcpy(toSend, &header, sizeof(header));
    memcpy(&toSend[sizeof(header)], &datas, sizeof(datas));
    _tcpSocket.WriteBytes(QByteArray::fromRawData(toSend, sizeof(header) + sizeof(datas)));
    std::cout << CLIENT_EVENT << " pseudo : [" << datas << "]" << std::endl;
}

void Babel::Client::Client::successfullyConnectedtoServer(const char *args)
{
    std::cout << std::endl;
    _connectedToServer = true;
}

void Babel::Client::Client::successfullyRegisterd(const char *args)
{
    std::cout << std::endl;
    _ui->stackedWidget->setCurrentIndex(0);
}

void Babel::Client::Client::emailAlreadyUsed(const char *args)
{
    std::cout << std::endl;
    _ui->erreur_inscription->setText("Erreur : email déjà utilisé !");
    _ui->erreur_inscription->show();
}

void Babel::Client::Client::pseudoAlreadyUsed(const char *args)
{
    std::cout << std::endl;
    _ui->erreur_inscription->setText("Erreur : Pseudo déjà utilisé !");
    _ui->erreur_inscription->show();
}

void Babel::Client::Client::successfullyConnected(const char *args)
{
    Babel::ServerSucessfullyConnected data{};

    memcpy(&data, args, sizeof(data));

    std::cout << " pseudo : [" << data.pseudo << "] id : " << data.id << "]" << std::endl;
    _pseudo = *new std::string(data.pseudo);
    _id = data.id;
    _connected = true;
    _ui->label_user->setText(QString::fromStdString(_pseudo));
    _ui->stackedWidget->setCurrentIndex(3);
    sendAskFriendsList();
}

void Babel::Client::Client::incorrectConnexionInformations(const char *args)
{
    std::cout << std::endl;
    _ui->erreur_connexion->show();
}

void Babel::Client::Client::friendRequestSucessfullySent(const char *args)
{
    std::cout << std::endl;
    _ui->label_msg_add_contact->setText("Demande d'ami envoyée !");
    _ui->label_msg_add_contact->show();
}

void Babel::Client::Client::unknownUser(const char *args)
{
    std::cout << std::endl;
    _ui->label_msg_add_contact->setText("Utilusateur inconnu !");

    _ui->label_msg_add_contact->show();
}

void Babel::Client::Client::alreadyFriends(const char *args)
{
    std::cout << std::endl;
    _ui->label_msg_add_contact->setText("C'est déjà ton pote lui mec !");
    _ui->label_msg_add_contact->show();
}

void Babel::Client::Client::friendsRequestRecieved(const char *args)
{
    std::cout << " pseudo : [" << args << "]" << std::endl;
    _ui->label_name_friend_request->setText(args);
    _ui->frame_deco_friend_request->show();
}

void Babel::Client::Client::incomingCall(const char *args)
{
    Babel::ServerCall data("", 0, "");

    memcpy(&data, args, sizeof(data));
    std::cout <<  " pseudo : [" << data.pseudo << "] ip : [" << data.ip << "] port : [" << data.port << "]" << std::endl;
    if (_inCall) {
        sendRefuseCall(data.pseudo);
        return;
    }
    _callMember.pseudo = *new std::string(data.pseudo);
    _callMember.ip = *new std::string(data.ip);
    _callMember.port = data.port;
    _ui->label_notif_appel_nom->setText(_callMember.pseudo.c_str());
    _ui->frame_deco_appel->show();
}

void Babel::Client::Client::getUserInfos(const char *args)
{
    Babel::ServerCall data("", 0, "");

    memcpy(&data, args, sizeof(data));
    std::cout << " ip : [" << data.ip << "] port : [" << data.port << "]" << std::endl;
    _callMember.ip = *new std::string(data.ip);
    _callMember.port = data.port;
    initCall();
    _ui->message_box->setGeometry(0, 200, 1471, 621);
    _ui->icon_contact_select->setGeometry(40, 20, 51, 51);
    _ui->label_nom_contact_select->setGeometry(100, 20, 250, 51);
    _ui->call_box->show();
    _ui->btn_appel->hide();
    _ui->caller_2->setIcon(_ui->icon_contact_select->icon());
}

void Babel::Client::Client::cantCallUser(const char *args)
{
    std::cout << std::endl;
}

void Babel::Client::Client::endCall(const char *args)
{
    _inCall = false;
    _ui->message_box->setGeometry(0, 0, 1471, 821);
    _ui->icon_contact_select->setGeometry(100, 20, 51, 51);
    _ui->label_nom_contact_select->setGeometry(160, 20, 250, 51);
    _ui->call_box->hide();
    _ui->btn_appel->show();
    std::cout << std::endl;
}

void Babel::Client::Client::messageRecieved(const char *args)
{
    Babel::OneMessage data{};

    memcpy(&data, args, sizeof(data));
    if (_ui->label_nom_contact_select->text().toStdString() == data.pseudo)
        _window->addMessageToCurrentList(data.body, "a");
    else {
        _ui->label_notif_nom->setText(QString::fromStdString(data.pseudo));
        _ui->frame_notif->show();
    }
    std::cout << " pseudo : [" << data.pseudo << "] message body : [" << data.body << "]" << std::endl;
}

void Babel::Client::Client::messageSendingSucced(const char *args)
{
    std::cout << std::endl;
}

void Babel::Client::Client::messageSendingFailed(const char *args)
{
    std::cout << std::endl;
    //TODO : create message in UI to show that the message can't be sent
}

void Babel::Client::Client::messagesHistory(const char *args)
{
    Babel::MessagesHistory data{};
    Babel::MessageDatas tmp{};

    memcpy(&data, args, sizeof(data));
    _window->clearMessagesList();
    std::cout << " pseudo : [" << data.pseudo << "] nbMessage : [" << data.nbMessage << "]";
    for (unsigned int i = 0; i < data.nbMessage; ++i) {
        memcpy(&tmp, &args[sizeof(data) + i * sizeof(tmp)], sizeof(tmp));
        _window->addMessageToCurrentList(tmp.body, tmp.id == _id ? "m" : "a");
        std::cout << "    sender : [" << tmp.pseudo << "] message body : [" << tmp.body << "]";
    }
    std::cout << std::endl;
}

void Babel::Client::Client::allFriends(const char *args)
{
    unsigned int nbFriends;
    char tmp[32];

    memcpy(&nbFriends, args, sizeof(nbFriends));

    std::cout << " nbFriends : [" << nbFriends << "]";
    for (unsigned int i = 0; i < nbFriends; ++i) {
        memcpy(&tmp, &args[sizeof(nbFriends) + i * sizeof(tmp)], sizeof(tmp));
        _window->addContactToList(*new std::string(tmp));
        std::cout <<  " pseudo : [" << tmp << "]";
    }
    std::cout << std::endl;
    sendAskFriendsRequestList();
}

void Babel::Client::Client::allFriendsRequests(const char *args)
{
    unsigned int nbFriends;
    char tmp[32];

    memcpy(&nbFriends, args, sizeof(nbFriends));

    std::cout << " nbFriends : [" << nbFriends << "]";
    for (unsigned int i = 0; i < nbFriends; ++i) {
        memcpy(&tmp, &args[sizeof(nbFriends) + i * sizeof(tmp)], sizeof(tmp));
        _pendingFriendsRequests.emplace_back(tmp);
        std::cout <<  " pseudo : [" << tmp << "]";
    }
    std::cout << std::endl;
    if (!_pendingFriendsRequests.empty()) {
        _ui->label_name_friend_request->setText(QString::fromStdString(_pendingFriendsRequests.back()));
        _ui->frame_deco_friend_request->show();
        _pendingFriendsRequests.pop_back();
    }
}

void Babel::Client::Client::acceptedFriendRequest(const char *args)
{
    std::cout << "pseudo : [" << args << "]" << std::endl;
    _window->addContactToList(* new std::string(args));
}

void Babel::Client::Client::refusedFriendRequest(const char *args)
{
    std::cout << std::endl;
}

void Babel::Client::Client::onDataAvailable() {
    QByteArray cmd = _tcpSocket.getData();
    Babel::Header header;

    if (cmd.size() == 0)
        return;
    std::memcpy(&header, cmd.toStdString().c_str(), 5);
    if (header.magicCode != MAGIC_CODE)
        return;
    try {if (_functionsTab.find(header.ins) != _functionsTab.end()) {
            std::cout << SERVER_EVENT;
            (this->*_functionsTab[header.ins])((cmd.toStdString().substr(HEADER_SIZE).c_str()));
        } else {
            std::cout << UNKNOWN_EVENT << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void Babel::Client::Client::initCall() {
    auto *portAudio = new Babel::Client::Audio::PortAudio();
    auto *opus = new Babel::Client::Audio::Opus(portAudio->getSampleRate(), portAudio->getChannel());
    auto *array = new std::vector<void *>();
    _thread = new Thread();
    _thread2 = new Thread();
    short *port = new short(4001);

    _inCall = true;
    array->push_back((void *)portAudio);
    array->push_back((void *)opus);
    array->push_back((void *)&_inCall);
    array->push_back((void *)port);
    array->push_back((void *)port);
    array->push_back((void *)&_callMember.ip);
    _thread->start(Babel::Client::Thread::routineRead, array);
    _thread2->start(Babel::Client::Thread::routineWrite, array);
}
