/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <string>

class Arms
{
    public:
        Arms(std::string serial = "A-01", bool funcitional = true);
        ~Arms();
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Legs
{
    public:
        Legs(std::string serial = "L-01", bool funcitional = true);
        ~Legs();
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Head
{
    public:
        Head(std::string serial = "H-01", bool funcitional = true);
        ~Head();
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    protected:
    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
