/*
** EPITECH PROJECT, 2021
** Utils
** File description:
** Utils
*/

#include "Utils.hpp"

std::string windowsPath(std::string str)
{
	#ifdef _WIN32
		for (int i = 0; i < str.size(); ++i)
			if (str[i] == '/')
				str[i] = '\\';
	#endif // !_WIN32
	return (str);
}

int roundPosition(float value)
{
    return (value - (int)value) > 0.5 ? (int)value + 1 : (int)value;
}