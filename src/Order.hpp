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
#include <queue>
#include "IPizza.hpp"
#include "PizzaFactory.hpp"

namespace plazza {
    class Order {
    public:
        Order() = default;
        void addPizza(const std::string &type, const std::string &size, int number);
        SerializedPizza takePizza();
        bool isEmpty();
    private:
        std::queue<SerializedPizza> _pizzas;

        FRIEND_TEST(Order, addPizza);
        FRIEND_TEST(Order, takePizza);
        FRIEND_TEST(Order, parseOrder);
    };
}

#endif
