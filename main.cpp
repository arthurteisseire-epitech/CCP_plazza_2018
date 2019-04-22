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
    plazza::Reception reception(parser.getCookingTime(), parser.getNbCooks(), parser.getTimeToReplaceIngredient());

    reception.open();
    return 0;
}
