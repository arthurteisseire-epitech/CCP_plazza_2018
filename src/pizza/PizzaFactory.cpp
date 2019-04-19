/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaFactory.cpp
*/

#include "PizzaMargarita.hpp"
#include "PizzaFactory.hpp"

const plazza::PizzaFactory::pizzaMap plazza::PizzaFactory::_pizzas = {
    {Margarita, [](PizzaSize size) { return std::make_unique<PizzaMargarita>(size); }},
};

std::unique_ptr<plazza::IPizza> plazza::PizzaFactory::create(PizzaType type, PizzaSize size) const
{
    return _pizzas.at(type)(size);
}
