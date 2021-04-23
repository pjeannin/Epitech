/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Minishell
*/

#include "../include/Minishell.hpp"
#include "../include/AComponent.hpp"

namespace nts {
    Minishell::Minishell(Circuit &circuit) : _circuit(circuit), _tick(-1)
    {
    }

    Minishell::~Minishell()
    {
    }

    void Minishell::run()
    {
        std::string currentLine;

        simulate();
        std::cout << prompt << ' ';
        while (getline(std::cin, currentLine)) {
            if (checkIfCommdnExist(currentLine) || (charIsPresent(currentLine, '=') && currentLine.length() >= 3)) {
                if (currentLine == "exit") {
                    return;
                } else if (currentLine == "display") {
                    display();
                } else if (currentLine == "simulate") {
                    simulate();
                } else if (currentLine == "loop") {
                    loop();
                } else if (currentLine == "dump") {
                    _circuit.dump();
                } else {
                    setInput(currentLine);
                }
            } else {
                std::cout << "Unknown Command." << std::endl;
            }
            std::cout << prompt << ' ';
        }
    }

    void Minishell::loop()
    {
        while (1) {
            simulate();
            display();
        }
    }

    void Minishell::simulate()
    {
        std::vector<IComponent *> outputs = _circuit.getOutputs();

        ++_tick;
        for (int i = 0; i < outputs.size(); ++i)
            outputs[i]->simulate(_tick);
    }

    bool sort_list(IComponent *i, IComponent *j) {
        return (dynamic_cast<AComponent *>(i)->getName() < dynamic_cast<AComponent *>(j)->getName());
    }

    void Minishell::setInput(std::string command)
    {
        std::string targetName;

        if (command[command.size() - 1] != '1' && command[command.size() - 1] != '0' && command[command.size() - 1] != 'U')
            std::cout << "Bad parameters." << std::endl;
        nts::Tristate state;
        switch (command[command.size() - 1])
        {
        case '0':
            state = nts::Tristate::FALSE;
            break;
        case '1':
            state = nts::Tristate::TRUE;
            break;
        default:
            state = nts::Tristate::UNDEFINED;
            break;
        }
        targetName = getCommand(command, '=');
        std::vector<IComponent *> vec = _circuit.getInputs();
        for (int i = 0; i < vec.size(); ++i) {
            AComponent *tmp = dynamic_cast<AComponent *>(vec[i]);
            if (tmp->getName() == targetName) {
                tmp->setNewPinValue(state);
                return;
            }
        }
        std::cout << "Bad parameters." << std::endl;
    }

    void Minishell::display()
    {
        std::cout << "tick: " << _tick << std::endl << "input(s):" << std::endl;
        std::vector<IComponent *> inputs = _circuit.getInputs();
        std::vector<IComponent *> outputs = _circuit.getOutputs();
        std::sort(inputs.begin(), inputs.end(), sort_list);
        for (int i = 0; i < inputs.size(); ++i) {
            AComponent *tmp = dynamic_cast<AComponent *>(inputs[i]);
            std::cout << "  " << tmp->getName() << ": ";
            switch (tmp->getPins()[0].getState())
            {
            case Tristate::TRUE:
                std::cout << "1" << std::endl;
                break;
            case Tristate::FALSE:
                std::cout << "0" << std::endl;
                break;
            default:
                std::cout << "U" << std::endl;
                break;
            }
        }
        std::cout << "output(s):" << std::endl;
        for (int i = 0; i < outputs.size(); ++i) {
            AComponent *tmp = dynamic_cast<AComponent *>(outputs[i]);
            std::cout << "  " << tmp->getName() << ": ";
            switch (tmp->getPins()[0].getState())
            {
            case Tristate::TRUE:
                std::cout << "1" << std::endl;
                break;
            case Tristate::FALSE:
                std::cout << "0" << std::endl;
                break;
            default:
                std::cout << "U" << std::endl;
                break;
            }
        }
    }

    bool Minishell::checkIfCommdnExist(std::string commandLine)
    {
        if (commandLine == "exit" || commandLine == "display"
        || commandLine == "simulate" || commandLine == "loop"
        || commandLine == "dump")
            return (true);

        return (false);
    }

    std::string Minishell::getCommand(std::string commandLine, char sep)
    {
        std::string *newLine = new std::string("");

        for (int i = 0; i < commandLine.length() && commandLine[i] != sep; ++i)
            *newLine += commandLine[i];

        return (*newLine);
    }

    bool Minishell::charIsPresent(std::string commandLine, char toFind)
    {
        int count = 0;

        for (int i = 0; i < commandLine.size(); ++i)
            if (commandLine[i] == '=')
                ++count;
        if (count == 1)
            return (true);
        return (false);
    }
}