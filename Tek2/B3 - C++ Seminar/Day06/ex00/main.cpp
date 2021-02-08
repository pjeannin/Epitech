/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** main
*/

#include <iostream>
#include <string>
#include <fstream>

static void read_and_print(char *filepath)
{
    std::ifstream file(filepath, std::ios::in);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "my_cat: " << filepath << ": No such file or directory"
        << std::endl;
        return;
    }
    while (getline(file, line))
        std::cout << line << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; ++i)
        read_and_print(argv[i]);

    return (0);
}