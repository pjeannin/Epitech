#include <string>
#include <iostream>
#include <fstream>

static bool checkContent(const std::string string, const unsigned int lvl)
{
    if (lvl > 2) return (false);
    if (lvl == 0) {
        if (string != "GiftPaper") return (false);
    } else if (lvl == 1) {
        if (string != "Box") return (false);
    } else if (lvl == 2) {
        if (string != "Little Pony" && string != "Teddy")
            return (false);
    }
    return (true);
}

static bool AnalyseFile(std::string string, unsigned int lvl)
{
    std::string obj_next = string;
    std::string bloc;
    std::string balise;

    while (obj_next.find(">")) {
        std::string content = obj_next.substr(0, obj_next.find(">"));
        content.erase(0, 1);
        if (content == "")
            return (true);
        if (!checkContent(content, lvl))
            return (false);
        bloc = obj_next.erase(0, content.size() + 2);
        balise = std::string("</") + content + ">";
        bloc = bloc.substr(0, bloc.find(balise));
        if (bloc == "")
            return (true);
        if (!AnalyseFile(bloc, lvl + 1))
            return (false);
        obj_next = obj_next.erase(0, bloc.size() + balise.size());
    }
    return (true);
}

int main(int ac, char **av)
{
    std::ifstream file;
    std::string line;
    std::string content = "";

    if (ac == 1) {
        std::cout << "Exemple:\n\t./santa filename.xml filename.xml" << std::endl;
        return (84);
    }
    for (unsigned int i = 1; av[i] != NULL; i++) {
        file.open(av[1]);
        if (file.good()) {
            while (!file.eof()) {
                getline(file, line);
                content += line;
            }
            file.close();
            if (!AnalyseFile(content, 0))
                std::cout << "The list '" << av[i] << "' has been broken." << std::endl;
            else
                std::cout << "useful to know what's inside, Right ?" << std::endl;
        } else {
            std::cout << "File " << av[i] << ", not readable! Please try again" << std::endl;
        }
    }
    return (0);
}
