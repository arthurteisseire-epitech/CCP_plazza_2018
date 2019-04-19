/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Order.hpp
*/

#ifndef PLAZZA_ORDER_HPP
#define PLAZZA_ORDER_HPP

#include <string>
#include <vector>
#include "IPizza.hpp"
#include "PizzaFactory.hpp"

namespace plazza {
    class Order {
    public:
        Order() = default;
        void addPizza(const std::string &type, const std::string &size, int number);
    private:
        std::vector<std::unique_ptr<IPizza>> _pizzas;
        PizzaFactory _factory;
    };
}

#endif
