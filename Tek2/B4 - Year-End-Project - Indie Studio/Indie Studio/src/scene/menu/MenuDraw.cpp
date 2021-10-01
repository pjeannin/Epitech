/*
** EPITECH PROJECT, 2021
** MenuDraw
** File description:
** MenuDraw
*/

#include "Menu.hpp"


#include <iostream>

void Menu::drawScStart(Core &core) noexcept
{
    if (_ellapsedTime >= 7 && _ellapsedTime <= 8.1)
        animTitleStart.drawRect();
    else if (_ellapsedTime >= 8.1)
        animTitleLoop.drawRect();
    raylib::Color orange = raylib::Color::Orange();

    raylib::Text::DrawEx(std::string(TextSubtext(message.c_str(), 0, messageCounter / 10)), core.mainFont, raylib::Vector2(815.0f, 750.0f), 35, 2, orange.Fade(fadeValContinue));
}

void Menu::drawScChoose(Core &core) noexcept
{
    _buttons[ButtonsList::Singleplayer]->draw();
    _buttons[ButtonsList::Multiplayer]->draw();
    _buttons[ButtonsList::Settings]->draw();
    _buttons[ButtonsList::Load]->draw();
    _bomb.draw();
    core._mainMenu.draw();
    _buttons[ButtonsList::Enter]->draw(raylib::Color::White());
}

void Menu::drawScSingleplayer(Core &core) noexcept
{
    core._singleplayerMenu.draw();
    _buttons[ButtonsList::Return]->draw();
    _buttons[ButtonsList::Enter]->draw();
}

void Menu::drawScMultiplayer(Core &core) noexcept
{
    core._multiplayerMenu.draw();
    _buttons[ButtonsList::Return]->draw();
    _buttons[ButtonsList::Enter]->draw();
}

void Menu::drawScSettings(Core &core) noexcept
{
    _buttons[ButtonsList::De_l]->draw();
    _buttons[ButtonsList::En_l]->draw();
    _buttons[ButtonsList::Fr_l]->draw();
    _buttons[ButtonsList::Sp_l]->draw();
    core._settingsMenu.draw();
    core._musicVol.draw();
    core._effectVol.draw();
    core._screenSize.draw();
    _buttons[ButtonsList::MusicVolMore]->draw();
    _buttons[ButtonsList::MusicVolLess]->draw();
    _buttons[ButtonsList::EffectVolLess]->draw();
    _buttons[ButtonsList::EffectVolMore]->draw();
    _buttons[ButtonsList::ScreenSizeLess]->draw();
    _buttons[ButtonsList::ScreenSizeMore]->draw();
    _buttons[ButtonsList::MusicVolLess]->draw();
    raylib::Text::DrawEx(core.musicVolVal + "%", core.mainFont, raylib::Vector2(1150, 458), 35, 2);
    raylib::Text::DrawEx(core.effectVolVal + "%", core.mainFont, raylib::Vector2(1150, 608), 35, 2);
    screenSize.draw(std::to_string(core.getWidth()) + "x" + std::to_string(core.getHeight()));
    _buttons[ButtonsList::MusicVolMore]->draw();
    _buttons[ButtonsList::Return]->draw();
}

void Menu::drawBackground() noexcept
{
    float const off[] = {0.2, 0.4, 0.8, 1, 1.2, 1.2};
    unsigned char i = 0;

    for (auto background : _backgrounds) {
        background->pos.x -= off[i];
        if (background->pos.x <= static_cast<double>(-background->val->width * 2))
            background->pos.x = 0;
        background->draw();
        background->val->Draw(raylib::Vector2(background->val->width * 2 + background->pos.x, 0), 0, 2);
        ++i;
    }
}

void Menu::draw(Core &core) noexcept
{
    raylib::Color black = raylib::Color::Black();
    core.beginDrawing();
    core.clearBackground(BLACK);
    drawBackground();
    if (_currentScene != Menu::Scene::SC_START)
        black.Fade(0.5).DrawRectangle(raylib::Vector2(0, 0), core.screenSize);
    (this->*(drawSc[_currentScene]))(core);
    _buttons[ButtonsList::Shutdown]->draw();
    fade.draw(core);
    if (_ellapsedTime >= 4 && _ellapsedTime <= 5.2)
        animBoat.drawRect();
    core.mouse.draw();
    core.endDrawing();
}
