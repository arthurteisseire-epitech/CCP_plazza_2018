/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** OrderTest.cpp
*/

#include <gtest/gtest.h>
#include "PizzaRegina.hpp"
#include "PizzaMargarita.hpp"
#include "OrderParser.hpp"
#include "Order.hpp"

namespace plazza {
    TEST(Order, addPizza)
    {
        Order order;

        order.addPizza("regina", "XL", 4);
        EXPECT_EQ(order._pizzas.size(), 1);
    }

    TEST(Order, takePizza)
    {
        Order order;

        order.addPizza("margarita", "M", 2);
        order.addPizza("fantasia", "XL", 1);
        order.addPizza("regina", "L", 3);
        order.addPizza("americana", "XXL", 4);
        for (size_t i = 0; i < 10; ++i)
            order.takePizza();
        EXPECT_TRUE(order.isEmpty());
    }

    TEST(Order, parseOrder)
    {
        Order order = OrderParser::parseLine("margarita S x3; americana L x12");

        EXPECT_EQ(order._pizzas.size(), 2);
    }
}
