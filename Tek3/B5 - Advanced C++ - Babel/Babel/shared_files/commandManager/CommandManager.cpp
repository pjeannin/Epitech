/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#include "CommandManager.hpp"

#include <string>
#include <cstring>
#include <sstream>

Babel::CommandManager::CommandManager() noexcept : _fct{
    {InsCode::Client::INIT_CONNECTION, &IUser::initializeConnection},
    {InsCode::Client::LOGIN, &IUser::signIn},
    {InsCode::Client::REGISTER, &IUser::signUp},
    {InsCode::Client::ASK_FRIEND_LIST, &IUser::askFriendList},
    {InsCode::Client::ASK_FRIEND_CALLING, &IUser::askFriendCalling},
    {InsCode::Client::ASK_MESSAGE_HISTORY, &IUser::askMessageHistory},
    {InsCode::Client::ASK_FRIEND_REQUEST_LIST, &IUser::askFriendRequest},
    {InsCode::Client::TERMINATE_CALL, &IUser::terminateCall},
    {InsCode::Client::ACCEPT_CALL, &IUser::handleCallResponse},
    {InsCode::Client::REFUSE_CALL, &IUser::handleCallResponse},
    {InsCode::Client::RECEIVE_FRIEND_REQUEST_REFUSE, &IUser::handleFriendRequestResponse},
    {InsCode::Client::RECEIVE_FRIEND_REQUEST_ACCEPT, &IUser::handleFriendRequestResponse},
    {InsCode::Client::SEND_FRIEND_REQUEST, &IUser::sendFriendRequest},
    {InsCode::Client::SEND_MESSAGE, &IUser::sendMessage},
}
{}

void Babel::CommandManager::handle(IUser *user, Babel::Request const &r)
{
    if (_fct.find(r.ins) != _fct.end())
        (user->*_fct[r.ins])(r);
}

Babel::CommandManager::Exception::Exception(std::string const &msg) : _msg("CommandManagerError: " + msg)
{}

char const *Babel::CommandManager::Exception::what() const noexcept
{
    return _msg.c_str();
}
