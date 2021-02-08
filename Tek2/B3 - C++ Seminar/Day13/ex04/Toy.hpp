/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType { BASIC_TOY, ALIEN, BUZZ, WOODY };
        Toy();
        Toy(const ToyType type, const std::string &name, const std::string &pictureFileName);
        Toy(const Toy &toy);
        virtual ~Toy();
        void setName(const std::string &name);
        bool setAscii(const std::string &fileName);
        const std::string &getName() const;
        const ToyType &getType() const;
        const std::string &getAscii() const;
        virtual bool speak(const std::string talk);
        Toy &operator=(const Toy &toy);
        Toy &operator<<(const std::string &ascii);

    protected:
        std::string _name;
        ToyType _type;
        Picture _picture;
    private:
};

std::ostream& operator<<(std::ostream &stream, Toy const &toy);

#endif /* !TOY_HPP_ */
