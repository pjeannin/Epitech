/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Create
*/

#ifndef CREATE_HPP_
#define CREATE_HPP_

#include <map>
#include <iterator>
#include <functional>
#include <memory>
#include "IComponent.hpp"
#include "Clock.hpp"
#include "Component2716.hpp"
#include "Component4001.hpp"
#include "Component4008.hpp"
#include "Component4011.hpp"
#include "Component4013.hpp"
#include "Component4017.hpp"
#include "Component4030.hpp"
#include "Component4040.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "Component4094.hpp"
#include "Component4512.hpp"
#include "Component4514.hpp"
#include "Component4801.hpp"
#include "False.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"

namespace nts {
    class Create {
        public:
            Create();
            ~Create();
            std::unique_ptr<IComponent> createNewComponent(const std::string &typeName, const std::string &name) const;

        protected:
        private:
            static std::unique_ptr<IComponent> new2716(std::string const &name);
            static std::unique_ptr<IComponent> new4001(std::string const &name);
            static std::unique_ptr<IComponent> new4008(std::string const &name);
            static std::unique_ptr<IComponent> new4011(std::string const &name);
            static std::unique_ptr<IComponent> new4013(std::string const &name);
            static std::unique_ptr<IComponent> new4017(std::string const &name);
            static std::unique_ptr<IComponent> new4030(std::string const &name);
            static std::unique_ptr<IComponent> new4040(std::string const &name);
            static std::unique_ptr<IComponent> new4069(std::string const &name);
            static std::unique_ptr<IComponent> new4071(std::string const &name);
            static std::unique_ptr<IComponent> new4081(std::string const &name);
            static std::unique_ptr<IComponent> new4094(std::string const &name);
            static std::unique_ptr<IComponent> new4512(std::string const &name);
            static std::unique_ptr<IComponent> new4514(std::string const &name);
            static std::unique_ptr<IComponent> new4801(std::string const &name);
            static std::unique_ptr<IComponent> newOutput(std::string const &name);
            static std::unique_ptr<IComponent> newInput(std::string const &name);
            static std::unique_ptr<IComponent> newFalse(std::string const &name);
            static std::unique_ptr<IComponent> newTrue(std::string const &name);
            static std::unique_ptr<IComponent> newClock(std::string const &name);
            std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(std::string const &)> > _components;
    };
}

#endif /* !CREATE_HPP_ */