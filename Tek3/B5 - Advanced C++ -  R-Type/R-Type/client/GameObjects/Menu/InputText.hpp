/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_INPUTTEXT_HPP
#define RTYPE_INPUTTEXT_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlText.hpp"
#include <iostream>
#include <vector>
#include "client/ECS/SfmlSound.hpp"

namespace RType::Client::GameObjects {
    class InputText : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::SfmlText, RType::ECS::SfmlSound>  {
    public:
        explicit InputText(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::SfmlText text, RType::ECS::SfmlSound modif) noexcept;
        ~InputText() override = default;
        InputText(const InputText &other) noexcept = delete;
        explicit InputText(InputText &&other) noexcept = delete;
        InputText &operator=(const InputText &other) const noexcept = delete;
        InputText &operator=(InputText &&other) const noexcept = delete;
        std::string getInputText();
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        void checkKeyboard(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::Scene::IScene *scene) noexcept;
    private:
        std::string _tmpText;
        std::string _ascii;
    };
}

#endif //RTYPE_INPUTTEXT_HPP
