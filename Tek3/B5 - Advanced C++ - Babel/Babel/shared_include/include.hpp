/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_INCLUDE_HPP__
#define __ASIO_INCLUDE_HPP__

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define OK_PRINT "[" << GREEN << "OK"  << RESET << "] "
#define ERROR_PRINT "[" << RED << "ERROR"  << RESET << "] "

#define MAGIC_CODE (int)4444//0x326843CA
#define MAGIC_CODE_SIZE sizeof(int32_t)
#define INS_CODE_SIZE sizeof(unsigned char)
#define HEADER_SIZE (sizeof(Babel::Header))
#define BODY_POS MAGIC_CODE_SIZE + INS_CODE_SIZE + sizeof(int32_t)

#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <cstring>

#include <iostream>

std::string IntToHexString (uint32_t const v);
std::string const newTimeStamp();

template <typename T>
using ArraySharedPtrT = std::vector<std::shared_ptr<T>>;

namespace InsCode {
    enum Client : unsigned char {
        /* initialize Connection */ INIT_CONNECTION = 200,
        /* register */ REGISTER = 100,
        /* login */ LOGIN = 110,
        /* send friend request */ SEND_FRIEND_REQUEST = 120,
        /* accept friend request */ RECEIVE_FRIEND_REQUEST_ACCEPT = 131, RECEIVE_FRIEND_REQUEST_REFUSE = 132,
        /* call friend */ ASK_FRIEND_CALLING = 140, ACCEPT_CALL = 144, REFUSE_CALL = 145, TERMINATE_CALL = 146,
        /* send message */ SEND_MESSAGE = 150,
        /* message history */ ASK_MESSAGE_HISTORY = 160,
        /* friend list */ ASK_FRIEND_LIST = 170,
        /* friend list */ ASK_FRIEND_REQUEST_LIST = 180,
    };

    enum Server : unsigned char {
        /* initialize Connection */ ACCEPT_CONNECTION = 201,
        /* register */ REGISTER_DONE = 101, REGISTER_EMAIL_ALREADY_USED = 102, REGISTER_USERNAME_ALREADY_USED = 103,
        /* login */ LOGIN_SUCCESS = 111, LOGIN_FAILED = 112,
        /* send friend request */ SEND_FRIEND_REQUEST_SUCCESS = 121, SEND_FRIEND_REQUEST_PSEUDO_UNKNOWN = 122, SEND_FRIEND_REQUEST_ALREADY_FRIEND = 123, SEND_ACCEPT_FIREND_REQUEST = 124, SEND_REFUSE_FRIEND_REQUEST = 125,
        /* accept friend request */ TRANSMIT_FRIEND_REQUEST = 130,
        /* call friend */ FRIEND_CALLING_SUCCESS = 141, FRIEND_CALLING_FAILED = 142, INCOMMING_CALL = 143, SEND_END_CALL = 147,
        /* send message */ SEND_MESSAGE_SUCCESS = 152, SEND_MESSAGE_FAILED = 153,
        /* receive message */ RECEIVE_MESSAGE = 151,
        /* message history */ SEND_MESSAGE_HISTORY = 161,
        /* friend list */ SEND_FRIEND_LIST = 171,
        /* friend list */ SEND_FRIEND_REQUEST_LIST = 181,
    };

    enum Special {
        FAILED = 0x32,
    };
};

namespace Babel {

    /**
     * @breif Use it at the begenning of each request
     * @param magicCode MagiCode define in the project
     * @param ins Code used to identify request
     */
    struct Header {
        explicit Header(unsigned char const ins_ = 0) noexcept : magicCode(MAGIC_CODE), ins(ins_) {}
        int32_t const magicCode;
        unsigned char ins;
    };

    struct Message {
        std::string *request;
        std::size_t size;
    };

    using Email = char [64];
    using Pseudo = char [32];
    using Password = char [32];
    using Ip = char [15];
    using Body = char [512];

    /**
     * @brief Use it with 100 code
     * @param email Email of the user
     * @param pseudo Pseudo of the user
     * @param password Password of the user
     */
    struct ClientRegister{
        Email email;
        Pseudo pseudo;
        Password password;
    };

    /**
     * @brief Use it with 110 code
     * @param email Email of the user
     * @param password Password of the user
     */
    struct ClientConnect {
        Email email;
        Password password;
    };

    /**
     * @brief Use it wit 140 or 144 codes
     * @param pseudo Pseudo of the target user
     * @param port Port of the sender user
     */
    struct ClientCall {
        Pseudo pseudo;
        unsigned short port;
    };

    /**
     * @breif use it with 141 or 143 codes
     * @param ip IP of the other member of the call
     * @param port Port of the other member of the call
     * @param pseudo Pseudo of the other member of the call
     */
    struct ServerCall {
        explicit ServerCall(Ip const ip_, unsigned short const port_, Pseudo const pseudo_) : port(port_) {
            std::memcpy(ip, ip_, sizeof(ip));
            std::memcpy(pseudo, pseudo_, sizeof(pseudo));
        }
        Ip ip;
        unsigned short port;
        Pseudo pseudo;
    };

    /**
     * @breif Use it with 111 code
     * @param pseudo Pseudo of the use
     * @param id Id of the user
     */
    struct ServerSucessfullyConnected {
        Pseudo pseudo;
        unsigned int id;
    };

    /**
     * @breif Use it with 151 code and 161
     * @param pseudo Pseudo of the message's sender
     * @param body Content of the message
     */
    struct MessageDatas {
        Body body;
        Pseudo pseudo;
        unsigned int id;
    };

    /**
     * @breief Use if with 150 code
     * @param pseudo Pseudo of the person who will recieve the message
     * @param body Content of the message
     */
    struct OneMessage {
        Pseudo pseudo;
        Body body;
    };

    /**
     * @breif Use it with 161 code
     * @param nbMessage Number of messages that will follow the struct
     * @param pseudo Pseudo of the other member of the conversation
     */
    struct MessagesHistory {
        unsigned int nbMessage;
        Pseudo pseudo;
    };

    /**
     * @breif Use it with 120,121,122,123,124,125,130,131,132,142,146,160 codes
     */
    using Pseudo = char [32];

    struct Pseudo_t {
        explicit Pseudo_t(char const *pseudo) noexcept {
            std::strncpy(val, pseudo, sizeof(Pseudo));
        }
        explicit Pseudo_t(std::string const &pseudo) noexcept {
            std::strncpy(val, pseudo.c_str(), sizeof(Pseudo));
        }
        Pseudo val;
    };

    /**
     * @breif Use if with 171 and 181 codes
     */
    using NbFriend = unsigned int;

    struct Request : public Header {
        char *body;
        template<typename T>
        T getStructArgs() const noexcept {
            T *data = new T;
            std::memcpy(data, body, sizeof(T));
            return *data;
        }

        void dump() const noexcept {
            std::cout << magicCode << (int)ins << "[" << (body ? body : "") << "]" <<  std::endl;
        }
    };
}

#endif //__ASIO_INCLUDE_HPP__
