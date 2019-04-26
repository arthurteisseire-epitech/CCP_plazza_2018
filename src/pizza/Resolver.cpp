/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Resolver.cpp
*/

#include "Resolver.hpp"
#include "PizzaException.hpp"

const std::map<std::string, plazza::PizzaType> plazza::Resolver::_types = {
    {"regina",    Regina},
    {"margarita", Margarita},
    {"americana", Americana},
    {"fantasia",  Fantasia},
};

const std::map<std::string, plazza::PizzaSize> plazza::Resolver::_sizes = {
    {"S",   S},
    {"M",   M},
    {"L",   L},
    {"XL",  XL},
    {"XXL", XXL},
};

plazza::PizzaType plazza::Resolver::findType(const std::string &type)
{
    auto it = _types.find(type);

    if (it == _types.end())
        throw PizzaException(type + " isn't a valid type");
    return it->second;
}

plazza::PizzaSize plazza::Resolver::findSize(const std::string &size)
{
    auto it = _sizes.find(size);

    if (it == _sizes.end())
        throw PizzaException(size + " isn't a valid size");
    return it->second;
}
