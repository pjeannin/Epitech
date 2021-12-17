/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_ID_HPP
#define RTYPE_ID_HPP

#include "IComponent.hpp"

namespace RType::ECS {
    class ID : public IComponent {
    public:
        explicit ID(unsigned short id) noexcept;
        ~ID() noexcept override = default;
        ID(const ID &pos) noexcept;
        explicit ID(ID &&pos) noexcept = delete;
        ID &operator=(const ID &pos) const noexcept = delete;
        ID &operator=(ID &&pos) const noexcept = delete;

        [[nodiscard]] unsigned short getId() const noexcept;

    private:
        unsigned short _id;
    };
}


#endif //RTYPE_ID_HPP
