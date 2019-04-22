/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** ArgParser.cpp
*/

#include <string>
#include "ArgParser.hpp"

plazza::ArgParser::ArgParser(int ac, const char *av[]) :
    _failed(false)
{
    if (ac != 4) {
        _failed = true;
    } else {
        parseArgs(av);
    }
}

void plazza::ArgParser::parseArgs(const char *av[])
{
    try {
        _cookingTime = std::stod(av[1]);
        _nbCooks = std::stoul(av[2]);
        _timeToReplaceIngredient = std::stoul(av[3]);
    } catch (const std::exception &) {
        _failed = true;
    }
}

double plazza::ArgParser::getCookingTime() const
{
    return _cookingTime;
}

size_t plazza::ArgParser::getNbCooks() const
{
    return _nbCooks;
}

size_t plazza::ArgParser::getTimeToReplaceIngredient() const
{
    return _timeToReplaceIngredient;
}

bool plazza::ArgParser::failed()
{
    return _failed;
}
