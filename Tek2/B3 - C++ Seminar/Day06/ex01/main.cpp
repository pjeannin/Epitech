/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** main
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

static std::vector<std::string> get_input()
{
    std::vector<std::string> return_tab;
    std::string tmp;

    while (getline(std::cin, tmp))
        return_tab.push_back(tmp);

    return (return_tab);
}

static void compute_celsius(std::string line)
{
    float value;
    std::stringstream stream_var;

    stream_var << line;
    stream_var >> value;
    value = value / (5.0 / 9.0) + 32;
    std::cout << std::setw(16) << std::fixed << std::setprecision(3) << value
    << std::setw(16) << "Fahrenheit" << std::endl;
}

static void compute_fahrenheit(std::string line)
{
    float value;
    std::stringstream stream_var;

    stream_var << line;
    stream_var >> value;
    value = (5.0 / 9.0) * (value - 32);
    std::cout << std::setw(16) << std::fixed << std::setprecision(3) << value
    << std::setw(16) << "Celsius" << std::endl;
}

int main(void)
{
    std::vector<std::string> input = get_input();

    for (int i = 0; i < input.size(); ++i)
        if (input[i].find("Celsius", 0) != -1) {
            compute_celsius(input[i]);
            return (0);
        } else if (input[i].find("Fahrenheit", 0) != -1) {
            compute_fahrenheit(input[i]);
            return (0);
        }

        return (0);
}