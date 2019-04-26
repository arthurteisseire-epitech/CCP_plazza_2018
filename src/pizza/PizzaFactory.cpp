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
#include "Resolver.hpp"

const plazza::PizzaFactory::pizzaMap plazza::PizzaFactory::_pizzas = {
    {Regina,    [](PizzaSize size) { return new PizzaRegina(size); }},
    {Margarita, [](PizzaSize size) { return new PizzaMargarita(size); }},
    {Americana, [](PizzaSize size) { return new PizzaAmericana(size); }},
    {Fantasia,  [](PizzaSize size) { return new PizzaFantasia(size); }},
};

plazza::IPizza *plazza::PizzaFactory::create(const std::string &type, const std::string &size)
{
    return create(Resolver::findType(type), Resolver::findSize(size));
}

plazza::IPizza *plazza::PizzaFactory::create(PizzaType type, PizzaSize size)
{
    return _pizzas.at(type)(size);
}
