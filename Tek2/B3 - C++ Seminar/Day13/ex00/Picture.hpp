/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>
#include <iostream>
#include <fstream>

class Picture {
    public:
        Picture(const std::string &file);
        Picture();
        ~Picture();
        bool getPictureFromFile(const std::string &file);
        std::string data;

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
