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
    try {
        _pizzas.emplace(SerializedPizza(Resolver::findType(type), Resolver::findSize(size)), number);
    } catch (const plazza::PizzaException &e) {
        std::cerr << e.what() << std::endl;
    }
}

plazza::SerializedPizza plazza::Order::takePizza()
{
    auto &pair = _pizzas.front();
    SerializedPizza pizza = pair.first;

    if (pair.second > 0)
        --pair.second;
    if (pair.second == 0)
        _pizzas.pop();
    return pizza;
}

bool plazza::Order::isEmpty() const
{
    return _pizzas.empty();
}
