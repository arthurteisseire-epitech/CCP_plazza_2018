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

const std::map<std::string, plazza::PizzaSize> plazza::PizzaFactory::_sizes = {
    {"S",   S},
    {"M",   M},
    {"L",   L},
    {"XL",  XL},
    {"XXL", XXL},
};

const plazza::PizzaFactory::pizzaMap plazza::PizzaFactory::_pizzas = {
    {"regina",    [](PizzaSize size) { return std::make_unique<PizzaRegina>(size); }},
    {"margarita", [](PizzaSize size) { return std::make_unique<PizzaMargarita>(size); }},
    {"americana", [](PizzaSize size) { return std::make_unique<PizzaAmericana>(size); }},
    {"fantasia",  [](PizzaSize size) { return std::make_unique<PizzaFantasia>(size); }},
};

std::unique_ptr<plazza::IPizza> plazza::PizzaFactory::create(const std::string &type, const std::string &size) const
{
    return _pizzas.at(type)(_sizes.at(size));
}
