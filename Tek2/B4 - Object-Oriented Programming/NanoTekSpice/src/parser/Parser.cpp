/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Parser
*/

#include <iostream>
#include "../../include/Parser.hpp"
#include "../../include/AComponent.hpp"

namespace nts {
    void Parser::parse(std::ifstream &fileStream, Circuit &circuit)
    {
        std::string currentLine;
        std::string chipsetType;
        std::string chipsetName;
        std::string firstComponent;
        std::string targetComponent;
        std::string firstComponentPin;
        std::string targetComponentPin;
        int firstPin;
        int targetPin;
        std::vector<nts::IComponent *> call;
        Create factory;

        while (getline(fileStream, currentLine) && Parser::cleanLine(currentLine, '#').find(".chipset") == std::string::npos);
        while (getline(fileStream, currentLine) && (currentLine = Parser::cleanLine(currentLine, '#')).find(".link") == std::string::npos) {
            chipsetType = Parser::cleanLine(currentLine, ' ');
            if (chipsetType.size() != 0) {
                chipsetName = currentLine.substr(chipsetType.length() + 1, currentLine.length());
                if (chipsetName.length() == 0)
                    throw Error("Parser", "Component must have a name");
                if (doesExist(circuit, chipsetName))
                    throw Error("Parser", "Two component connot have the same name.");
                IComponent *currentComponent = factory.createNewComponent(chipsetType, chipsetName).release();
                circuit.addComponent(currentComponent);
                if (chipsetType == "input")
                    circuit.addInput(currentComponent);
                else if (chipsetType == "output")
                    circuit.addOutput(currentComponent);
            }
        }
        while (getline(fileStream, currentLine)) {
            currentLine = Parser::cleanLine(currentLine, '#');
            firstComponent = Parser::cleanLine(currentLine, ':');
            currentLine = currentLine.substr(firstComponent.length() + 1, currentLine.length());
            firstComponentPin = Parser::cleanLine(currentLine, ' ');
            firstPin = std::stoi(firstComponentPin);
            currentLine = currentLine.substr(firstComponentPin.length() + 1);
            targetComponent = Parser::cleanLine(currentLine, ':');
            currentLine = currentLine.substr(targetComponent.length() + 1);
            targetComponentPin = cleanLine(currentLine, ' ');
            targetPin = std::stoi(targetComponentPin);
            if (!doesExist(circuit, firstComponent) || !doesExist(circuit, targetComponent))
                throw Error("Parser", "Unknow component name");
            circuit.getComponent(firstComponent)->setLink(firstPin, *(circuit.getComponent(targetComponent)), targetPin);
            circuit.getComponent(targetComponent)->setLink(targetPin, *(circuit.getComponent(firstComponent)), firstPin);
        }
        if (circuit.getAllComponent().size() == 0)
            throw Error("Parser", "No component declared in .nts file.");
    }

    std::string &Parser::cleanLine(std::string &line, char sep)
    {
        std::string *newLine = new std::string("");

        for (int i = 0; i < line.length() && line[i] != sep; ++i)
            *newLine += line[i];

        return (*newLine);
    }

    bool Parser::parserErrors(std::ifstream &fileStream)
    {
        if (!Parser::wordInFile(fileStream, ".chipsets:") || !Parser::wordInFile(fileStream, ".links:"))
            return (false);
        return (true);
    }

    bool Parser::isbegeningOfLine(std::string base, std::string toFind)
    {
        if (toFind.length() < base.length())
            return (false);
        for (int i = 0; i < toFind.length() && i < base.length(); ++i)
        {
            if (toFind[i] != base[i])
                return (false);
        }

        return (true);
    }

    bool Parser::wordInFile(std::ifstream &fileStream, std::string word)
    {
        std::string line;

        while (getline(fileStream,line)) {
            if (isbegeningOfLine(line, word))
                return (true);
        }
        return (false);
    }

    bool Parser::doesExist(Circuit &circuit, std::string toTest)
    {
        bool returnValue = false;
        std::vector<IComponent *> vec = circuit.getAllComponent();

        for (int i = 0; i < vec.size(); ++i) {
            AComponent *tmp = dynamic_cast<AComponent *>(vec[i]);
            if (tmp->getName() == toTest)
                returnValue = true;
        }

        return (returnValue);
    }
}