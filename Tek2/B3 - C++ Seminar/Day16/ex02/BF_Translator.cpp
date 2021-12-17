/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** BF_Translator
*/

#include "BF_Translator.hpp"

BF_Translator::BF_Translator()
{
    _instructions['+'] = &BF_Translator::increments;
    _instructions['-'] = &BF_Translator::decrements;
    _instructions['>'] = &BF_Translator::moveForward;
    _instructions['<'] = &BF_Translator::moveBackward;
    _instructions['.'] = &BF_Translator::print;
    _instructions[','] = &BF_Translator::read;
    _instructions['['] = &BF_Translator::jumpOpen;
    _instructions[']'] = &BF_Translator::jumpClose;
}

BF_Translator::~BF_Translator()
{
}

int BF_Translator::translate(const std::string &in, const std::string &out)
{
    try {
        _in.open(in, std::ios::in);
        _out.open(out, std::ios::trunc | std::ios::out);
        if (!_in.is_open() | !_out.is_open())
            throw (std::exception());
        functionPointer currentCommand;
        char readChar;
        begin();
        while ((readChar = _in.get()) != -1) {
            currentCommand = _instructions[readChar];
            if (currentCommand)
                (this->*currentCommand)();
        }
        end();
        _out.close();
        _in.close();
    } catch (std::exception &error) {
        _in.close();
        _out.close();
        return (27012001);
    }

    return (0);
}

void BF_Translator::begin()
{
    _out << "#include <stdlib.h>" << std::endl << "#include <string.h>" << std::endl << "#include <unistd.h>" << std::endl << std::endl << "int main(void)" << std::endl << "{" << std::endl << "    char mem[60 * 1024];" << std::endl << "    unsigned int pos = 0;" << std::endl << "    memset(mem, 0, 60 * 1024);" << std::endl;
}

void BF_Translator::increments() { _out << "    ++mem[pos];" << std::endl; }

void BF_Translator::decrements() { _out << "    --mem[pos];" << std::endl; }

void BF_Translator::moveForward() { _out << "    ++pos;" << std::endl; }

void BF_Translator::moveBackward() { _out << "    --pos;" << std::endl; }

void BF_Translator::print() { _out << "    write(1, &mem[pos], 1);" << std::endl; }

void BF_Translator::read() { _out << "    read(0, &mem[pos], 1);" << std::endl; }

void BF_Translator::jumpOpen() { _out << "    while (mem[pos])" << std::endl << "{" << std::endl; }

void BF_Translator::jumpClose() { _out << "}" << std::endl; }

void BF_Translator::end() { _out << std::endl << "    return (0);" << std::endl << "}"; }