/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** IComponent
*/

#ifndef RTYPE_ICOMPONENT_HPP
#define RTYPE_ICOMPONENT_HPP
#include <memory>

namespace RType::ECS {
    class IComponent {
        public:
            virtual ~IComponent() noexcept = default;
    };
}

#endif //RTYPE_ICOMPONENT_HPP
