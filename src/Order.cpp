/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Order.cpp
*/

#include <iostream>
#include "PizzaException.hpp"
#include "PizzaFactory.hpp"
#include "Order.hpp"

void plazza::Order::addPizza(const std::string &type, const std::string &size, int number)
{
    for (int i = 0; i < number; ++i) {
        try {
            _pizzas.emplace_back(_factory.create(type, size));
        } catch (const plazza::PizzaException &e) {
            if (i == 0)
                std::cerr << e.what() << std::endl;
        }
    }
}