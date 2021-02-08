/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** BF_Translator
*/

#ifndef BF_TRANSLATOR_HPP_
#define BF_TRANSLATOR_HPP_

#include <string>
#include <fstream>
#include <map>

class BF_Translator {
    public:
        BF_Translator();
        ~BF_Translator();

        typedef void (BF_Translator::*functionPointer)();

        int translate(const std::string &in, const std::string &out);

    protected:
    private:
        std::map<char, functionPointer> _instructions;
        std::ifstream _in;
        std::ofstream _out;
        void begin();
        void increments();
        void decrements();
        void moveForward();
        void moveBackward();
        void print();
        void read();
        void jumpOpen();
        void jumpClose();
        void end();
};

#endif /* !BF_TRANSLATOR_HPP_ */
