/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Create
*/

#include "../include/Create.hpp"

namespace nts {
    Create::Create()
    {
        _components["2716"] = &Create::new2716;
        _components["4001"] = &Create::new4001;
        _components["4008"] = &Create::new4008;
        _components["4011"] = &Create::new4011;
        _components["4013"] = &Create::new4013;
        _components["4017"] = &Create::new4017;
        _components["4030"] = &Create::new4030;
        _components["4040"] = &Create::new4030;
        _components["4069"] = &Create::new4069;
        _components["4071"] = &Create::new4071;
        _components["4081"] = &Create::new4081;
        _components["4094"] = &Create::new4094;
        _components["4512"] = &Create::new4512;
        _components["4514"] = &Create::new4514;
        _components["4801"] = &Create::new4801;
        _components["input"] = &Create::newInput;
        _components["output"] = &Create::newOutput;
        _components["true"] = &Create::newTrue;
        _components["false"] = &Create::newFalse;
        _components["clock"] = &Create::newClock;
    }

    Create::~Create()
    {
    }

    std::unique_ptr<IComponent> Create::createNewComponent(const std::string &typeName, const std::string &name) const
    {
        std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(std::string const &)> >::const_iterator typeConstructor = _components.find(typeName);

        if (typeConstructor == _components.end())
            throw Error("Unknow Component type", typeName);

        return (typeConstructor->second(name));
    }

    std::unique_ptr<IComponent> Create::new2716(std::string const &name) { return (std::unique_ptr<Component2716>(new Component2716(name))); }

    std::unique_ptr<IComponent> Create::new4001(std::string const &name) { return (std::unique_ptr<Component4001>(new Component4001(name))); }

    std::unique_ptr<IComponent> Create::new4008(std::string const &name) { return (std::unique_ptr<Component4008>(new Component4008(name))); }

    std::unique_ptr<IComponent> Create::new4011(std::string const &name) { return (std::unique_ptr<Component4011>(new Component4011(name))); }

    std::unique_ptr<IComponent> Create::new4013(std::string const &name) { return (std::unique_ptr<Component4013>(new Component4013(name))); }

    std::unique_ptr<IComponent> Create::new4017(std::string const &name) { return (std::unique_ptr<Component4017>(new Component4017(name))); }

    std::unique_ptr<IComponent> Create::new4030(std::string const &name) { return (std::unique_ptr<Component4030>(new Component4030(name))); }

    std::unique_ptr<IComponent> Create::new4040(std::string const &name) { return (std::unique_ptr<Component4040>(new Component4040(name))); }

    std::unique_ptr<IComponent> Create::new4069(std::string const &name) { return (std::unique_ptr<Component4069>(new Component4069(name))); }

    std::unique_ptr<IComponent> Create::new4071(std::string const &name) { return (std::unique_ptr<Component4071>(new Component4071(name))); }

    std::unique_ptr<IComponent> Create::new4081(std::string const &name) { return (std::unique_ptr<Component4081>(new Component4081(name))); }

    std::unique_ptr<IComponent> Create::new4094(std::string const &name) { return (std::unique_ptr<Component4094>(new Component4094(name))); }

    std::unique_ptr<IComponent> Create::new4512(std::string const &name) { return (std::unique_ptr<Component4512>(new Component4512(name))); }

    std::unique_ptr<IComponent> Create::new4514(std::string const &name) { return (std::unique_ptr<Component4514>(new Component4514(name))); }

    std::unique_ptr<IComponent> Create::new4801(std::string const &name) { return (std::unique_ptr<Component4801>(new Component4801(name))); }

    std::unique_ptr<IComponent> Create::newOutput(std::string const &name) { return (std::unique_ptr<Output>(new Output(name))); }

    std::unique_ptr<IComponent> Create::newInput(std::string const &name) { return (std::unique_ptr<Input>(new Input(name))); }

    std::unique_ptr<IComponent> Create::newFalse(std::string const &name) { return (std::unique_ptr<False>(new False(name))); }

    std::unique_ptr<IComponent> Create::newTrue(std::string const &name) { return (std::unique_ptr<True>(new True(name))); }

    std::unique_ptr<IComponent> Create::newClock(std::string const &name) { return (std::unique_ptr<Clock>(new Clock(name))); }
}