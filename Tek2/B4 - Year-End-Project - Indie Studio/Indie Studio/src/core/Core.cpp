/*
** EPITECH PROJECT, 2021
** Core
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(unsigned int const width, unsigned int const height, std::string const &title) noexcept :
    raylib::Window(width, height ,title),
    screenSize(width, height),
    mainFont("resources/fonts/HelveticaLTStd-Bold.otf", 32, 0, 250),
    cursor("resources/images/cursor.png"),
    currentScene(nullptr),
    isRunning(true),
    fxHover("resources/sounds/hover.ogg"),
    fxSelect("resources/sounds/select.ogg"),
    musicVolVal("80"),
    effectVolVal("80"),
    textures{{"Singleplayer", new raylib::Texture()},
              {"Multiplayer", new raylib::Texture()},
              {"Settings", new raylib::Texture()},
              {"MainMenu", new raylib::Texture()},
              {"SingleplayerMenu", new raylib::Texture()},
              {"MultiplayerMenu", new raylib::Texture()},
              {"SettingsMenu", new raylib::Texture()},
              {"MusicVol", new raylib::Texture()},
              {"EffectVol", new raylib::Texture()},
              {"ScreenSize", new raylib::Texture()},
              {"Save", new raylib::Texture()},
              {"Load", new raylib::Texture()},
              {"Resume", new raylib::Texture()},
              {"LeftArrow", new raylib::Texture("resources/buttons/left arrow.png")},
              {"RightArrow", new raylib::Texture("resources/buttons/right arrow.png")},
              {"Return", new raylib::Texture("resources/buttons/return.png")},
              {"Enter", new raylib::Texture("resources/buttons/enter.png")},
              {"Shutdown", new raylib::Texture("resources/buttons/shutdown.png")},
              {"En_l", new raylib::Texture("resources/buttons/english flag.png")},
              {"Fr_l", new raylib::Texture("resources/buttons/french flag.png")},
              {"De_l", new raylib::Texture("resources/buttons/german flag.png")},
              {"Sp_l", new raylib::Texture("resources/buttons/spanish flag.png")}
    }
{
    ::SetExitKey(0);
    ::SetTargetFPS(60);
    changeLanguage(FRENCH);
}

void Core::loop() noexcept
{
    while (isOpen()) {
        if (nextScene)
            switchScene();
        currentScene->loop(*this);
    }
}

Core::~Core() noexcept
{
    for (auto texture__ : textures)
        delete texture__.second;
    textures.clear();
    delete currentScene;
}

void Core::changeLanguage(Language const language_) noexcept
{
    language = language_;
    std::string const& languageFolder = Languages[language];

    textures["Singleplayer"]->Load("resources/buttons/" + languageFolder + "/singleplayer.png");
    textures["Multiplayer"]->Load("resources/buttons/" + languageFolder + "/multiplayer.png");
    textures["Settings"]->Load("resources/buttons/" + languageFolder + "/settings.png");
    textures["MainMenu"]->Load("resources/images/" + languageFolder + "/main_menu.png");
    textures["SingleplayerMenu"]->Load("resources/images/" + languageFolder + "/singleplayer_menu.png");
    textures["MultiplayerMenu"]->Load("resources/images/" + languageFolder + "/multiplayer_menu.png");
    textures["SettingsMenu"]->Load("resources/images/" + languageFolder + "/settings_menu.png");
    textures["MusicVol"]->Load("resources/images/" + languageFolder + "/music_volume.png");
    textures["EffectVol"]->Load("resources/images/" + languageFolder + "/effect_volume.png");
    textures["ScreenSize"]->Load("resources/images/" + languageFolder + "/screen_size.png");
    textures["Save"]->Load("resources/buttons/" + languageFolder + "/save.png");
    textures["Load"]->Load("resources/buttons/" + languageFolder + "/load.png");
    textures["Resume"]->Load("resources/buttons/" + languageFolder + "/resume.png");

    _mainMenu.load(textures["MainMenu"], raylib::Vector2(0, 40), 0, 1, raylib::Color::RayWhite());
    _singleplayerMenu.load(textures["SingleplayerMenu"], raylib::Vector2(0, 40), 0, 1, raylib::Color::RayWhite());
    _multiplayerMenu.load(textures["MultiplayerMenu"], raylib::Vector2(0, 40), 0, 1, raylib::Color::RayWhite());
    _settingsMenu.load(textures["SettingsMenu"], raylib::Vector2(0, 40), 0, 1, raylib::Color::RayWhite());
    _musicVol.load(textures["MusicVol"], raylib::Vector2(382.5, 400), 0, 0.7, raylib::Color::RayWhite());
    _effectVol.load(textures["EffectVol"], raylib::Vector2(382.5, 550), 0, 0.7, raylib::Color::RayWhite());
    _screenSize.load(textures["ScreenSize"], raylib::Vector2(382.5, 700), 0, 0.7, raylib::Color::RayWhite());
}
