/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Core
*/

#include "Core.hpp"




void findGrapic(std::string folder, std::vector<std::filesystem::path>&libList)
{
    std::filesystem::path temp;
    int i = 0;

    for (auto it : std::filesystem::directory_iterator(folder)) {
        temp = it;
        if (temp.extension() == ".so") {
            if (temp.string().compare("./lib/arcade_sdl2.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_ncurses.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_ndk++.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_aalib.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_libcaca.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_allegro5.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_xlib.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_gtk+.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_sfml.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_irrlicht.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_opengl.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_vulkan.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_qt5.so") == 0) {
                libList.push_back(temp);
                i++;
            }
        }
    }
}

void findGame(std::string folder, std::vector<std::filesystem::path>&libList)
{
    std::filesystem::path temp;
    int i = 0;

    for (auto it : std::filesystem::directory_iterator(folder)) {
        temp = it;
        if (temp.extension() == ".so") {
            if (temp.string().compare("./lib/arcade_nibbler.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_pacman.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_qix.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_centipede.so") == 0) {
                libList.push_back(temp);
                i++;
            }
            if (temp.string().compare("./lib/arcade_solarfox.so") == 0) {
                libList.push_back(temp);
                i++;
            }
        }
    }
}


Core::Core()
{
    findGrapic("./lib", _graphic);
    findGame("./lib", _game);
    _name = "aaaa";
}

Core::~Core()
{
}

int Core::run(std::string graphicPath)
{
    std::vector<std::filesystem::path>::iterator it = _graphic.begin();

    if (graphicPath.substr(0, 6).compare("./lib/") != 0 && graphicPath.substr(0, 4).compare("lib/") != 0 )
        exit(84);
    if (graphicPath.substr(0, 4).compare("lib/") == 0)
        graphicPath = "./" + graphicPath;

    for(; it != _graphic.end(); it++) {
        if ((*it).string() == graphicPath) {
            _current_graphic.load(graphicPath);
            break;
        }
    }
    if (it == _graphic.end())
        throw(Error("This lib isn't a graphical librairie"));
    if (_current_graphic.instance->isOperational() == false)
        throw(Error("Graphic Librairies threw an Error"));
    try {
        createMenu(it);
    } catch (Error &e) {
        throw(e);
    }
    return (0);
}

void Core::loadGraphic(std::vector<std::filesystem::path>::iterator it)
{
    try {
        _current_graphic.reset();
        _current_graphic.load((*it).string());
    } catch (Error &e) {
        throw(e);
    }
    if (_current_graphic.instance->isOperational() == false)
        throw(Error("Graphic Librairies threw an Error"));
}

Text createText(std::string str, Position pos, Size size, Color color) {
    Text text(str);

    text.pos = pos;
    text.size = size;
    text.color = color;
    return text;
}

std::string getScore(auto it)
{
    std::string score;

    std::filesystem::path file = it;
    int value = 0;
    std::string gameName = "";
    std::string name = "";
    std::string temp = "";
    if (file.extension() == ".txt") {
        gameName = file.string().substr(file.string().find_last_of('_') + 1);
        gameName.erase(gameName.find('.'));
        gameName.append("-> ");
        std::ifstream scoreGetter;
        scoreGetter.open(file.string());
        while (getline(scoreGetter, temp)) {
            std::string name2 = "";
            name2 = temp.substr(0, temp.find(':'));
            temp.erase(0, temp.find(':') + 2);
            if (value < std::stoi(temp)) {
                name = name2;
                value = std::stoi(temp);
            }
        }
        score = gameName;
        score.append(name + " = ");
        score.append(std::to_string(value));
    }
    return (score);
}

void Core::createMenu(std::vector<std::filesystem::path>::iterator &currentGraphIt)
{
    std::string score;
    std::ofstream scoreFile;
    std::vector<std::filesystem::path>::iterator itGraph = _graphic.begin();
    std::vector<std::filesystem::path>::iterator itGame = _game.begin();
    int indexName = 0;

    itGraph = currentGraphIt;
    itGame = _game.begin();


    Text graphAvailable = createText("Graphical libraries:", Position((float)1, (float)60), Size((float)15, (float)15), Color(255, 255, 255, 255));

    Text gameAvailable = createText("Game librairies:", Position((float)20, (float)60), Size((float)15, (float)15), Color(255, 255, 255, 255));

    Text Chosen = createText((*itGame).string().substr(6), Position((float)1, (float)1), Size((float)15, (float)15), Color(255, 255, 255, 255));

    Text Name = createText(_name, Position((float)50, (float)50), Size((float)15, (float)15), Color(255, 255, 255, 255));

    while (event != Event::quit && event != Event::menu) {
        if (event == Event::next_game) {
            itGame++;
            if (itGame == _game.end())
                itGame = _game.begin();
            Chosen.setText((*itGame).string().substr(6));
        }
        if (event == Event::prev_game) {
            if (itGame == _game.begin()) {
                itGame = _game.end();
                itGame--;
            } else
                itGame--;
            Chosen.setText((*itGame).string().substr(6));
        }
        if (event == Event::enter) {
            try {
                _current_game.reset();
                _current_game.load((*itGame).string());
            } catch(Error &e) {
                throw(e);
            }
            std::string _score = "score_"+ (*itGame).string().substr(6);
            _score.erase(_score.find('.'));
            _score.append(".txt");
            scoreFile.open("./score/" + _score, std::ios::app);
            try { gameLoop(itGraph, itGame, scoreFile);} catch(Error &e) {throw e;}
            scoreFile.close();
            if (event == Event::quit)
                return;
        }
        if (event == Event::next_graphic) {
            itGraph++;
            if (itGraph == _graphic.end())
                itGraph = _graphic.begin();
            try {
                loadGraphic(itGraph);
            } catch (Error &e) {
                throw(e);
            }
        }
        if (event == Event::prev_graphic) {
            if (itGraph == _graphic.begin()) {
                itGraph = _graphic.end();
            }
            itGraph--;
            try {
                loadGraphic(itGraph);
            } catch (Error &e) {
                throw(e);
            }
        }
        if (event == Event::left) {
            if (indexName == 0)
                indexName = 3;
            else
                indexName--;
        }
        if (event == Event::right) {
            if (indexName == 3)
                indexName = 0;
            else
               indexName++;
        }
        if (event == Event::up) {
            if (_name[indexName] == 'z')
                _name[indexName] = 'a';
            else
                _name[indexName]++;
            Name.setText(_name);
        }
        if (event == Event::down) {
            if (_name[indexName] == 'a')
                _name[indexName] = 'z';
            else
                _name[indexName]--;
            Name.setText(_name);
        }
        _current_graphic.instance->clearScreen();
        _current_graphic.instance->drawText(graphAvailable);
        Text temp(graphAvailable);
        for (auto it = _graphic.begin(); it != _graphic.end(); it++) {
            temp.pos += Vector2f(0, 5);
            temp.setText((*it).string().substr(6));
            _current_graphic.instance->drawText(temp);
        }

        _current_graphic.instance->drawText(gameAvailable);
        Text temp2(gameAvailable);
        for (auto it = _game.begin(); it != _game.end(); it++) {
            temp2.pos += Vector2f(0, 5);
            temp2.setText((*it).string().substr(6));
            _current_graphic.instance->drawText(temp2);
        }

        Text myScore("", Position((float)50, (float)55), Size((float)15, (float)15), Color(255, 255, 255, 255));
       for (auto it : std::filesystem::directory_iterator("./score")) {
           myScore.setText(getScore(it));
           myScore.pos += Vector2f(0, 5);
           _current_graphic.instance->drawText(myScore);
       }
        _current_graphic.instance->drawText(Chosen);
        _current_graphic.instance->drawText(Name);
        _current_graphic.instance->refreshScreen();
        event = _current_graphic.instance->handleEvent();
    }

}

void Core::gameLoop(std::vector<std::filesystem::path>::iterator itGraph, std::vector<std::filesystem::path>::iterator itGame, std::ofstream &scoreFile)
{

    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point other;

    if (_current_graphic.instance->isOperational() == false)
        return;
    bool isOpen = true;

    while (isOpen) {
        event = _current_graphic.instance->handleEvent();
        if (event == Event::quit)
            isOpen = false;
        if (event == Event::menu)
            isOpen = false;
        if (event == Event::restart) {
            try {
                _current_game.reset();
                _current_game.load((*itGame).string());
            }catch (Error &e) {
                throw e;
            }
        }
        if (event == Event::next_graphic) {
            itGraph++;
            if (itGraph == _graphic.end())
                itGraph = _graphic.begin();
           loadGraphic(itGraph);
        }
        if (event == Event::prev_graphic) {
            if (itGraph == _graphic.begin()) {
                itGraph = _graphic.end();
            }
            itGraph--;
            loadGraphic(itGraph);
        }
        _current_game.instance->event(event);
        _current_graphic.instance->clearScreen();
        _current_game.instance->render(*_current_graphic.instance);
        _current_graphic.instance->refreshScreen();
        other = std::chrono::steady_clock::now();
        _current_game.instance->update(std::chrono::duration_cast<std::chrono::milliseconds>(other - now).count());
        now = std::chrono::steady_clock::now();
    }
    scoreFile << _name << ": " << _current_game.instance->getScore() << "\n";
}