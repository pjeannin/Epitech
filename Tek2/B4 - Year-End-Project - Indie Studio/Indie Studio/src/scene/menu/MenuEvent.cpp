/*
** EPITECH PROJECT, 2021
** MenuEvent
** File description:
** MenuEvent
*/

#include "Menu.hpp"
#include "../game/Game.hpp"

#include <iostream>

void Menu::eventMenuScStart() noexcept
{
    ++animBoat.framesCounter;
    ++animTitleStart.framesCounter;
    ++animTitleLoop.framesCounter;

    if (animBoat.framesCounter >= (60 / 12) && _ellapsedTime >= 4 && _ellapsedTime <= 5.2)
        animBoat.nextFrame();
    if (animTitleStart.framesCounter >= (60 / 12) && _ellapsedTime >= 7 && _ellapsedTime <= 8.1)
        animTitleStart.nextFrame();
    if (animTitleLoop.framesCounter >= (60 / 12) && _ellapsedTime >= 8.1)
        animTitleLoop.nextFrame();
    _ellapsedTime = GetTime();
    if (_ellapsedTime >= 9)
        messageCounter += 2;
    if (startBlink && fadeValContinue <= 0)
        blinkSwitch = true;
    if (startBlink && fadeValContinue >= 1)
        blinkSwitch = false;
    fadeValContinue += (startBlink && !blinkSwitch) ? -0.04 : 0.04;
    if (_ellapsedTime >= 11.5)
        startBlink = true;
}

void Menu::eventScStart(Core &core) noexcept
{

}

void Menu::eventScChoose(Core &core) noexcept
{
    _buttons[ButtonsList::Singleplayer]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            loadScene(Scene::SC_SINGLEPLAYER);
            core.loadScene<Game>(new Game::Config(Game::GameType::Singleplayer, Game::GameLoad::New));
            isSceneRunning = false;
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
            _bomb.rotation = -15;
            _bomb.pos.x = -120;
            _bomb.pos.y = 290;
        });
    _buttons[ButtonsList::Multiplayer]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            loadScene(Scene::SC_MULTIPLAYER);
            std::cout << "------------" << (int)Game::GameType::Multiplayer << (int)Game::GameType::Singleplayer << std::endl;
            core.loadScene<Game>(new Game::Config(Game::GameType::Multiplayer, Game::GameLoad::New));
            isSceneRunning = false;
        }, [&](Bomberman::Button &button){
            _bomb.rotation = 0;
            _bomb.pos.x = -80;
            core.fxHover.Play();
            _bomb.pos.y = 290;
        });
    _buttons[ButtonsList::Load]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            core.loadScene<Game>(new Game::Config(Game::GameType::Multiplayer, Game::GameLoad::Load, "last.save"));
            isSceneRunning = false;
        }, [&](Bomberman::Button &button){
        core.fxHover.Play();
        _bomb.rotation = 10;
        _bomb.pos.x = -30;
        _bomb.pos.y = 290;
        }, [&](Bomberman::Button &button) {
            return saves;
        }
    );
    _buttons[ButtonsList::Settings]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            loadScene(Scene::SC_SETTINGS);
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
            _bomb.rotation = 15;
            _bomb.pos.x = -35;
            _bomb.pos.y = 290;
        });
}

void Menu::eventScSingleplayer(Core &core) noexcept
{

}

void Menu::eventScMultiplayer(Core &core) noexcept
{

}

void Menu::eventScSettings(Core &core) noexcept
{
    _buttons[ButtonsList::MusicVolMore]->check(
        [&](Bomberman::Button &button){
            if ((stoi(core.musicVolVal) + 10) <= 100) {
                core.fxSelect.Play();
                core.musicVolVal = std::to_string(std::stoi(core.musicVolVal) + 10);
                ::SetMusicVolume(music, std::stof(core.musicVolVal) * 0.01);
            }
        }, [&](Bomberman::Button &button){
        core.fxHover.Play();
    });

    _buttons[ButtonsList::MusicVolLess]->check(
        [&](Bomberman::Button &button){
            if ((stoi(core.musicVolVal) - 10) <= 100) {
                core.fxSelect.Play();
                core.musicVolVal = std::to_string(std::stoi(core.musicVolVal) - 10);
                ::SetMusicVolume(music, std::stof(core.musicVolVal) * 0.01);
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

void Menu::eventBtnCollision(Core &core) noexcept
{
    (this->*(eventSc[_currentScene]))(core);
    _buttons[ButtonsList::Shutdown]->check(
        [&](Bomberman::Button &button){
            core.fxSelect.Play();
            loadScene(Scene::SC_CHOOSE);
            CloseWindow();
            exit(0);
        }, [&](Bomberman::Button &button){
            core.fxHover.Play();
        });
    _buttons[ButtonsList::Enter]->check(
        [&](Bomberman::Button &button){},
        [&](Bomberman::Button &button){
            core.fxHover.Play();
        });
}

void Menu::event(Core &core) noexcept
{
    if (_currentScene == Scene::SC_START)
        eventMenuScStart();
    if (fade.val <= 0.1)
        eventBtnCollision(core);
}
