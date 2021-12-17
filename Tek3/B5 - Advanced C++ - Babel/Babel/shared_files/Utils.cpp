/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Babel
*/

#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>

std::string IntToHexString (uint32_t const v) {
    std::stringstream stream;

    stream << static_cast<unsigned char>(v >> 24);
    stream << static_cast<unsigned char>(v >> 16);
    stream << static_cast<unsigned char>(v >> 8);
    stream << static_cast<unsigned char>(v);
    return stream.str();
}

std::string const newTimeStamp()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::stringstream ss;
    ss << std::put_time(std::gmtime(&in_time_t), "%Y-%m-%d-%H:%M:%S");
    ss << '.' << std::setfill('0') << std::setw(3) << now_milliseconds.count();
    return ss.str();
}