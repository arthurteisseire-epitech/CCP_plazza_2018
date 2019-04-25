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
        EXPECT_EQ(order._pizzas.size(), 4);
    }

    TEST(Order, takePizza)
    {
        Order order;
        PizzaMargarita *margarita;
        PizzaRegina *regina;

        order.addPizza("margarita", "M", 1);
        order.addPizza("regina", "L", 1);
        margarita = dynamic_cast<PizzaMargarita *>(order.takePizza());
        EXPECT_EQ(order._pizzas.size(), 1);
        regina = dynamic_cast<PizzaRegina *>(order.takePizza());
        EXPECT_EQ(order._pizzas.size(), 0);

        EXPECT_EQ(margarita->_type, Margarita);
        EXPECT_EQ(regina->_type, Regina);
    }

    TEST(Order, parseOrder)
    {
        Order order = OrderParser::parseLine("margarita S x3; americana L x12");

        EXPECT_EQ(order._pizzas.size(), 15);
    }
}
