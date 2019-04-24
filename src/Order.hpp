/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Order.hpp
*/

#ifndef PLAZZA_ORDER_HPP
#define PLAZZA_ORDER_HPP

#include <gtest/gtest_prod.h>
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

        FRIEND_TEST(Order, addPizza);
        FRIEND_TEST(Order, parseOrder);
    };
}

#endif
