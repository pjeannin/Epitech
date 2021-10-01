/*
** EPITECH PROJECT, 2021
** PauseMenu
** File description:
** PauseMenu
*/

#include "Game.hpp"

#include <ctime>

void Game::PauseMenu::changeLanguage(Language const language_, Core &core) noexcept
{
    core.changeLanguage(language_);
    _buttons[ButtonsList::Settings]->loadTexture(core.textures["Settings"], 3);
    _buttons[ButtonsList::Save]->loadTexture(core.textures["Save"], 3);
    _buttons[ButtonsList::Resume]->loadTexture(core.textures["Resume"], 3);
}

Game::PauseMenu::PauseMenu(Core &core, GameType const gameType_) noexcept :
    _active(false),
    _buttons{
        {ButtonsList::Shutdown, new Bomberman::Button("resources/buttons/shutdown.png")},
        {ButtonsList::Save, new Bomberman::Button()},
        {ButtonsList::Settings, new Bomberman::Button()},
        {ButtonsList::Resume, new Bomberman::Button()},
        {ButtonsList::Return, new Bomberman::Button("resources/buttons/return.png")},
        {ButtonsList::De_l, new Bomberman::Button(core.textures["De_l"])},
        {ButtonsList::Fr_l, new Bomberman::Button(core.textures["Fr_l"])},
        {ButtonsList::Sp_l, new Bomberman::Button(core.textures["Sp_l"])},
        {ButtonsList::En_l, new Bomberman::Button(core.textures["En_l"])},
        {ButtonsList::MusicVolMore, new Bomberman::Button(core.textures["RightArrow"])},
        {ButtonsList::MusicVolLess, new Bomberman::Button(core.textures["LeftArrow"])},
        {ButtonsList::EffectVolMore, new Bomberman::Button(core.textures["RightArrow"])},
        {ButtonsList::EffectVolLess, new Bomberman::Button(core.textures["LeftArrow"])},
        {ButtonsList::ScreenSizeMore, new Bomberman::Button(core.textures["RightArrow"])},
        {ButtonsList::ScreenSizeLess, new Bomberman::Button(core.textures["LeftArrow"])},
    },
    _background(raylib::Color::Black().Fade(0.8)),
    _currentScene(Scene::SC_CHOOSE),
    _loadScene(Scene::SC_NO_SCENE),
    drawSc{{Scene::SC_CHOOSE, &Game::PauseMenu::drawScChoose}, {Scene::SC_SETTINGS, &Game::PauseMenu::drawScSettings}},
    eventSc{{Scene::SC_CHOOSE, &Game::PauseMenu::eventScChoose}, {Scene::SC_SETTINGS, &Game::PauseMenu::eventScSettings}},
    screenSize(raylib::Vector2(1080, 758), &core.mainFont, 35, 2),
    _gameType(gameType_)
{
    changeLanguage(core.language, core);
    Bomberman::Button *button = nullptr;
    SET_BUTTONS_BOUNDS(Resume, +0, -200);
    SET_BUTTONS_BOUNDS(Save, +0, -20);
    SET_BUTTONS_BOUNDS(Settings, +0, +160);
    SET_BUTTONS_BOUNDS(Shutdown, -880, +460);
    SET_BUTTONS_BOUNDS(Return, -780, +460);
    SET_BUTTONS_BOUNDS(En_l, -248, -250);
    SET_BUTTONS_BOUNDS(Fr_l, -82, -250);
    SET_BUTTONS_BOUNDS(De_l, +82, -250);
    SET_BUTTONS_BOUNDS(Sp_l, +248, -250);
    SET_BUTTONS_BOUNDS(MusicVolMore, +370, -74);
    SET_BUTTONS_BOUNDS(MusicVolLess, +65, -74);
    SET_BUTTONS_BOUNDS(EffectVolMore, +370, +76);
    SET_BUTTONS_BOUNDS(EffectVolLess, +65, +76);
    SET_BUTTONS_BOUNDS(ScreenSizeMore, +370, +226);
    SET_BUTTONS_BOUNDS(ScreenSizeLess, +65, +226);}


Game::PauseMenu::~PauseMenu() noexcept
{
    _buttons.clear();
}

void Game::PauseMenu::draw(Core &core) noexcept
{
    _background.DrawRectangle(raylib::Vector2(0, 0), core.screenSize);
    (this->*(drawSc[_currentScene]))(core);
    _buttons[ButtonsList::Shutdown]->draw();
    core.mouse.draw();
}

void Game::PauseMenu::set(bool const val) noexcept
{
    _active = val;
}

bool Game::PauseMenu::isActive() const noexcept
{
    return _active;
}
void Game::PauseMenu::drawScChoose(Core &core) noexcept
{
    _buttons[ButtonsList::Resume]->draw();
    _buttons[ButtonsList::Settings]->draw();
    _buttons[ButtonsList::Save]->draw();
}

void Game::PauseMenu::eventScChoose(Core &core, Game &game) noexcept
{
    _buttons[ButtonsList::Resume]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            _active = false;
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        }
    );

    _buttons[ButtonsList::Save]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();

            game.exportToFile("last.save");

        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        }
    );

    _buttons[ButtonsList::Settings]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            loadScene(Scene::SC_SETTINGS);
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        }
    );
}

void Game::PauseMenu::drawScSettings(Core &core) noexcept
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

void Game::PauseMenu::eventScSettings(Core &core, Game &game) noexcept
{
    _buttons[ButtonsList::MusicVolMore]->check(
        [&](Bomberman::Button &button){
            if ((stoi(core.musicVolVal) + 10) <= 100) {
                core.fxSelect.Play();
                core.musicVolVal = std::to_string(std::stoi(core.musicVolVal) + 10);
                ::SetMusicVolume(game.music, std::stof(core.musicVolVal) * 0.01);
            }
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        });

    _buttons[ButtonsList::MusicVolLess]->check(
        [&](Bomberman::Button &button){
            if ((stoi(core.musicVolVal) - 10) <= 100) {
                core.fxSelect.Play();
                core.musicVolVal = std::to_string(std::stoi(core.musicVolVal) - 10);
                ::SetMusicVolume(game.music, std::stof(core.musicVolVal) * 0.01);
            }
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        });

    _buttons[ButtonsList::EffectVolMore]->check(
        [&](Bomberman::Button &button){
            if ((stoi(core.effectVolVal) + 10) <= 100) {
                core.fxSelect.Play();
                core.effectVolVal = std::to_string(std::stoi(core.effectVolVal) + 10);
                core.fxSelect.SetVolume(std::stof(core.effectVolVal) * 0.01);
                core.fxHover.SetVolume(std::stof(core.effectVolVal) * 0.01);
            }
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        });

    _buttons[ButtonsList::EffectVolLess]->check(
        [&](Bomberman::Button &button){
            if ((stoi(core.effectVolVal) - 10) <= 100) {
                core.fxSelect.Play();
                core.effectVolVal = std::to_string(std::stoi(core.effectVolVal) - 10);
                core.fxSelect.SetVolume(std::stof(core.effectVolVal) * 0.01);
                core.fxHover.SetVolume(std::stof(core.effectVolVal) * 0.01);
            }
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        });

    _buttons[ButtonsList::ScreenSizeMore]->check(
        [&](Bomberman::Button &button){},
        [&](Bomberman::Button &button){
            core.fxHover.Play();
        });

    _buttons[ButtonsList::ScreenSizeLess]->check(
        [&](Bomberman::Button &button){},
        [&](Bomberman::Button &button){
            core.fxHover.Play();
        });

    _buttons[ButtonsList::En_l]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            changeLanguage(ENGLISH, core);
        }, [&](Bomberman::Button &button){},
        [&](Bomberman::Button &button){ return core.language != ENGLISH; });

    _buttons[ButtonsList::Fr_l]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            changeLanguage(FRENCH, core);
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        }, [&](Bomberman::Button &button){ return core.language != FRENCH; });

    _buttons[ButtonsList::Sp_l]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            changeLanguage(SPANISH, core);
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        }, [&](Bomberman::Button &button){ return core.language != SPANISH ; });

    _buttons[ButtonsList::De_l]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            changeLanguage(GERMAN, core);
        },
        [&](Bomberman::Button &button){
            core.fxHover.Play();
        }, [&](Bomberman::Button &button){ return core.language != GERMAN  ; });

    _buttons[ButtonsList::Return]->check(
        [&](Bomberman::Button &button) {
            loadScene(Scene::SC_CHOOSE);
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        });
}


void Game::PauseMenu::event(Core &core, Game &game) noexcept
{
    (this->*(eventSc[_currentScene]))(core, game);

    _buttons[ButtonsList::Shutdown]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            loadScene(Scene::SC_CHOOSE);
            CloseWindow();
            exit(0);
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        }
    );
    if (_loadScene != Scene::SC_NO_SCENE)
        switchScene();
}