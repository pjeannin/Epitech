/*
** EPITECH PROJECT, 2021
** SQLiteClass
** File description:
** Project File
*/

#include <include.hpp>
#include "Database.hpp"

int Babel::Server::callback(void *data, int argc, char **argv, char **azColName)
{
    Babel::Server::Database::RequestT *tuple = reinterpret_cast<Babel::Server::Database::RequestT *>(data);

    std::get<0>(*tuple) = argc;
    std::vector<std::string> &row = std::get<1>(*tuple);
    std::vector<std::string> &col = std::get<2>(*tuple);
    for (char const * const *i = argv; *i; ++i)
        row.emplace_back(std::string(*i));
    for (char const * const *i = azColName; *i; ++i)
        col.emplace_back(std::string(*i));
    return 0;
}

Babel::Server::DatabaseException::DatabaseException(std::string const &msg) : _msg("DatabaseError: " + msg)
{}

Babel::Server::Database::RequestT Babel::Server::Database::exec(std::string const &request)
{
    char *errMsg = nullptr;
    std::vector<std::string> argv;
    std::vector<std::string> azColName;
    RequestT res = std::make_tuple(0, argv, azColName);

    if (sqlite3_exec(_db, request.c_str(), &callback, &res, &errMsg) != SQLITE_OK) {
        std::string errMsg_ (errMsg);
        sqlite3_free(errMsg);
        throw DatabaseException("Failed to exec sql instruction -> \"" + request + "\": " + errMsg_);
    } else {
        std::cout << "Request " << request << " executed successfully" << std::endl;
        return (res);
    }
}

char const *Babel::Server::DatabaseException::what() const noexcept
{
    return _msg.c_str();
}

Babel::Server::Database::Database(const std::string &dbName)
{
    if (sqlite3_open((dbName + ".db").c_str(), &this->_db) != SQLITE_OK)
        throw DatabaseException("Can't open Database");
    else
        std::cout << "Opened database successfully" << std::endl;
}

Babel::Server::Database::~Database()
{
    sqlite3_close(_db);
    std::cout << "Database Closed" << std::endl;
}

char Babel::Server::Database::checkIfAccountAlreadyExist(std::string const &username, std::string const &email)
{
    RequestT res1 = exec("SELECT * FROM USERS WHERE email = \"" + email + "\" LIMIT 1;");
    RequestT res2 = exec("SELECT * FROM USERS WHERE username = \"" + username + "\" LIMIT 1;");
    return !std::get<1>(res1).empty() ? 1 : !std::get<1>(res2).empty() ? 2 : 0;
}

void Babel::Server::Database::addUser(std::string const &username, std::string const &password, std::string const &email)
{
    exec("INSERT INTO USERS (USERNAME,PASSWORD,EMAIL) VALUES ('" + username + "', '" + password + "', '" + email + "');");
}

void Babel::Server::Database::addMessage(std::size_t const from_id, std::size_t const to_id, std::string const &time_created, std::string const &message)
{
    exec("INSERT INTO MESSAGES (FROM_ID,TO_ID,TIME_CREATED,MESSAGE) VALUES (\"" + std::to_string(from_id) + "\", \"" + std::to_string(to_id) + "\", \"" + time_created + "\", \"" + message + "\");");
}

void Babel::Server::Database::addFriendRequest(std::size_t const from_id, std::size_t const to_id)
{
    exec("INSERT INTO FRIENDS_REQUESTS (FROM_ID,TO_ID) VALUES (" + std::to_string(from_id) + ", " + std::to_string(to_id) + ");");
}

void Babel::Server::Database::addFriend(std::size_t const from_id, std::size_t const to_id)
{
    exec("INSERT INTO FRIENDS (FIRST_ID,SECOND_ID) VALUES (" + std::to_string(from_id) + ", " + std::to_string(to_id) + ");");
}

bool Babel::Server::Database::isFriend(std::size_t const first_id, std::size_t const second_id)
{
    RequestT res = exec("SELECT * FROM friends WHERE first_id = \"" + std::to_string(first_id) + "\" AND second_id = \"" + std::to_string(second_id) + "\" OR first_id = \"" + std::to_string(second_id) + "\" AND second_id = \"" + std::to_string(first_id) + "\" LIMIT 1;");
    return !std::get<1>(res).empty();
}

std::vector<std::string> *Babel::Server::Database::getFriends(size_t const user_id)
{
    std::string user_id_ = std::to_string(user_id);
    RequestT res = exec("SELECT username from USERS WHERE id IN (SELECT second_id FROM friends WHERE first_id = " + user_id_ + " UNION SELECT first_id FROM friends WHERE second_id = " + user_id_ + ")");
    std::vector<std::string> *final = new std::vector<std::string>;
    auto friends = std::get<1>(res);
    for (std::string const &username : friends)
        final->emplace_back(username);
    return (final);
}

std::vector<Babel::Server::message_t *> *Babel::Server::Database::getMessage(size_t const firstUser_id, size_t const secondUser_id)
{
    RequestT res = exec("SELECT from_id, message FROM messages WHERE (from_id = " + std::to_string(firstUser_id) + " and to_id = " + std::to_string(secondUser_id) + ") OR (to_id = " + std::to_string(firstUser_id) + " and from_id = " + std::to_string(secondUser_id) + ")");
    auto *final = new std::vector<message_t *>;
    std::vector<std::string> &messages = std::get<1>(res);

    int from_id = 0;
    int to_id = 0;
    if (!messages.empty()) {
        size_t i = 0;
        message_t *ref = nullptr;
        while (i < messages.size()) {
            ref = new message_t();
            ref->from_id = std::stoi(messages[i]);
            ref->message = messages[i + 1];
            final->push_back(ref);
            i += 2;
        }
    }
    return (final);
}

std::vector<std::string> *Babel::Server::Database::getFriendsRequests(size_t const user_id)
{
    std::string user_id_ = std::to_string(user_id);
    RequestT res = exec("SELECT username from USERS WHERE id IN (SELECT from_id FROM friends_requests WHERE to_id = " + user_id_ + " UNION SELECT to_id FROM friends_requests WHERE from_id = " + user_id_ + ")");
    std::vector<std::string> *final = new std::vector<std::string>;
    auto friends = std::get<1>(res);
    for(std::string const &username : friends)
        final->emplace_back(username);
    return (final);
}

Babel::Server::user_t *Babel::Server::Database::getUserInfos(size_t const user_id)
{
    RequestT res = exec("SELECT * FROM USERS WHERE id = \"" + std::to_string(user_id) + "\" LIMIT 1;");
    std::vector<std::string> &user_ = std::get<1>(res);

    if (user_.empty())
        return nullptr;
    user_t *user = new user_t;
    if (user_.size() < 4)
        return nullptr;
    user->id = std::stoi(user_[0]);
    user->username = user_[1];
    user->password = user_[2];
    user->email = user_[3];
    return user;
}

Babel::Server::user_t *Babel::Server::Database::getUserinfosByEmail(std::string const &email)
{
    RequestT res = exec("SELECT * FROM USERS WHERE email = \"" + email + "\" LIMIT 1;");
    std::vector<std::string> &user_ = std::get<1>(res);

    if (user_.empty())
        return nullptr;
    user_t *user = new user_t;
    if (user_.size() < 4)
        return nullptr;
    user->id = std::stoi(user_[0]);
    user->username = user_[1];
    user->password = user_[2];
    user->email = user_[3];
    return (user);
}

Babel::Server::user_t *Babel::Server::Database::getUserinfosByUsername(std::string const &username)
{
    RequestT res = exec("SELECT * FROM USERS WHERE username = \"" + username + "\" LIMIT 1;");
    std::vector<std::string> &user_ = std::get<1>(res);

    if (user_.empty())
        return nullptr;
    user_t *user = new user_t;
    if (user_.size() < 4)
        return nullptr;
    user->id = std::stoi(user_[0]);
    user->username = user_[1];
    user->password = user_[2];
    user->email = user_[3];
    return (user);
}

void Babel::Server::Database::removeFriendRequest(std::size_t const from_id, std::size_t const to_id)
{
    exec("DELETE FROM FRIENDS_REQUESTS WHERE to_id = " + std::to_string(to_id) + " AND from_id = " + std::to_string(from_id));
}

bool Babel::Server::Database::isFriendRequestAlreadySend(std::size_t const first_id, std::size_t const second_id)
{
    RequestT res = exec("SELECT * FROM friends_requests WHERE from_id = \"" + std::to_string(first_id) + "\" AND to_id = \"" + std::to_string(second_id) + "\" LIMIT 1;");
    return !std::get<1>(res).empty();
}

bool Babel::Server::Database::isAccountExistByUsername(std::string const &username)
{
    RequestT data = exec("SELECT * FROM USERS WHERE username = \"" + username + "\" LIMIT 1;");
    return !std::get<1>(data).empty();
}

bool Babel::Server::Database::isAccountExistById(size_t const id)
{
    RequestT data = exec("SELECT * FROM USERS WHERE id = \"" + std::to_string(id) + "\" LIMIT 1;");
    return !std::get<1>(data).empty();
}
