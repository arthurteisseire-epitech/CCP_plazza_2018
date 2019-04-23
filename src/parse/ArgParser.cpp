/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** ArgParser.cpp
*/

#include <string>
#include "ArgParser.hpp"

plazza::ArgParser::ArgParser(int ac, const char *av[]) :
    _cookingTimeMultiplier(0),
    _nbCooks(0),
    _timeToReplaceIngredient(0),
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
        _cookingTimeMultiplier = std::stod(av[1]);
        _nbCooks = std::stoul(av[2]);
        _timeToReplaceIngredient = std::stoul(av[3]) * 1000;
    } catch (const std::exception &) {
        _failed = true;
    }
}

double plazza::ArgParser::getCookingTimeMultiplier() const
{
    return _cookingTimeMultiplier;
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
