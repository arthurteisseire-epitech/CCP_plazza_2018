/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaFactory.cpp
*/

#include "PizzaFactory.hpp"
#include "PizzaMargarita.hpp"
#include "PizzaRegina.hpp"
#include "PizzaAmericana.hpp"
#include "PizzaFantasia.hpp"
#include "PizzaException.hpp"

const std::map<std::string, plazza::PizzaType> plazza::PizzaFactory::_types = {
    {"regina",    Regina},
    {"margarita", Margarita},
    {"americana", Americana},
    {"fantasia",  Fantasia},
};

const std::map<std::string, plazza::PizzaSize> plazza::PizzaFactory::_sizes = {
    {"S",   S},
    {"M",   M},
    {"L",   L},
    {"XL",  XL},
    {"XXL", XXL},
};

const plazza::PizzaFactory::pizzaMap plazza::PizzaFactory::_pizzas = {
    {Regina,    [](PizzaSize size) { return new PizzaRegina(size); }},
    {Margarita, [](PizzaSize size) { return new PizzaMargarita(size); }},
    {Americana, [](PizzaSize size) { return new PizzaAmericana(size); }},
    {Fantasia,  [](PizzaSize size) { return new PizzaFantasia(size); }},
};

plazza::IPizza *plazza::PizzaFactory::create(const std::string &type, const std::string &size)
{
    auto itType = _types.find(type);
    auto itSize = _sizes.find(size);

    if (itType == _types.end())
        throw PizzaException(type + " isn't a valid type");
    if (itSize == _sizes.end())
        throw PizzaException(size + " isn't a valid size");
    return create(itType->second, itSize->second);
}

plazza::IPizza *plazza::PizzaFactory::create(PizzaType type, PizzaSize size)
{
    return _pizzas.at(type)(size);
}
