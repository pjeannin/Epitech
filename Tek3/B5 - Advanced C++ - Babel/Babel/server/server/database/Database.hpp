/*
** EPITECH PROJECT, 2021
** SQLiteClass
** File description:
** Project File
*/

#include <iostream>
#include <sqlite3.h>

#ifndef SQLITECLASS_DATABASE_HPP
#define SQLITECLASS_DATABASE_HPP

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <tuple>

namespace Babel::Server {
    int callback(void *data, int argc, char **argv, char **azColName);

    typedef struct message_s {
        int from_id;
        int to_id;
        std::string timestamp;
        std::string message;
    } message_t;

    typedef struct user_s {
        int id;
        std::string username;
        std::string password;
        std::string email;
    } user_t;

    class DatabaseException : std::exception {
        public:
            explicit DatabaseException(std::string const &msg);
            char const *what() const noexcept;
        private:
            std::string const _msg;
    };

    class Database {
        public:
            explicit Database(std::string const &dbName);
            ~Database();

            using RequestT = std::tuple<int, std::vector<std::string>, std::vector<std::string>>;

            void addUser(std::string const &username, std::string const &password, std::string const &email);
            void addMessage(std::size_t const from_id, std::size_t const to_id, std::string const &time_created, std::string const &message);
            void addFriendRequest(std::size_t const from_id, std::size_t const to_id);
            void removeFriendRequest(std::size_t const from_id, std::size_t const to_id);
            void addFriend(std::size_t const from_id, std::size_t const to_id);
            char checkIfAccountAlreadyExist(std::string const &username, std::string const &email = "");
            bool isAccountExistByUsername(std::string const &username);
            bool isAccountExistById(size_t const id);
            bool isFriend(std::size_t const first_id, std::size_t const second_id);
            bool isFriendRequestAlreadySend(std::size_t const first_id, std::size_t const second_id);
            user_t *getUserinfosByUsername(std::string const &username);
            user_t *getUserinfosByEmail(std::string const &email);
            user_t *getUserInfos(size_t const user_id);
            std::vector<std::string> *getFriends(size_t const user);
            std::vector<std::string> *getFriendsRequests(size_t const user);
            std::vector<message_t *> *getMessage(size_t const firstUser_id, size_t const secondUser_id);

        private:
            void init(const std::string &dbName);
            RequestT exec(std::string const &request);

            sqlite3 *_db;
    };
}

#endif //SQLITECLASS_DATABASE_HPP
