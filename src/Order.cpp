/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Order.cpp
*/

#include <iostream>
#include "Resolver.hpp"
#include "PizzaException.hpp"
#include "PizzaFactory.hpp"
#include "Order.hpp"

void plazza::Order::addPizza(const std::string &type, const std::string &size, int number)
{
    for (int i = 0; i < number; ++i) {
        try {
            _pizzas.emplace(Resolver::findType(type), Resolver::findSize(size));
        } catch (const plazza::PizzaException &e) {
            if (i == 0)
                std::cerr << e.what() << std::endl;
        }
    }
}

plazza::SerializedPizza plazza::Order::takePizza()
{
    SerializedPizza pizza = _pizzas.front();

    _pizzas.pop();
    return pizza;
}

bool plazza::Order::isEmpty()
{
    return _pizzas.empty();
}
