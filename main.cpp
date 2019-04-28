/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** main.cpp
*/

#include <cstdlib>
#include "ArgParser.hpp"
#include "Reception.hpp"

static plazza::ArgParser parseArgs(int ac, const char *av[])
{
    plazza::ArgParser parser(ac, av);

    if (parser.failed())
        exit(84);
    return parser;
}

int main(int ac, const char *av[])
{
    plazza::ArgParser parser = parseArgs(ac, av);
    plazza::Reception reception(parser.getCookingTimeMultiplier(), parser.getNbCooks(), parser.getTimeToReplaceIngredient());

    try {
        reception.open();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
