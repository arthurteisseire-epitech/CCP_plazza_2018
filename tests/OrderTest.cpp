/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** OrderTest.cpp
*/

#include <gtest/gtest.h>
#include "OrderParser.hpp"
#include "Order.hpp"

namespace plazza {
    TEST(Order, addPizza)
    {
        Order order;

        order.addPizza("regina", "XL", 4);
        EXPECT_EQ(order._pizzas.size(), 4);
    }

    TEST(Order, parseOrder)
    {
        Order order = OrderParser::parseLine("margarita S x3; americana L x12");

        EXPECT_EQ(order._pizzas.size(), 15);
    }
}
