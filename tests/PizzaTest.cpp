/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaTest.cpp
*/

#include <gtest/gtest.h>
#include <APizza.hpp>

#include "Stock.hpp"
#include "PizzaMargarita.hpp"

namespace plazza {
    TEST(PizzaTest, create)
    {
        PizzaMargarita margarita(XL);

        EXPECT_EQ(margarita._size, XL);
        EXPECT_EQ(margarita._type, Margarita);
        EXPECT_EQ(margarita._time, 1000);
        EXPECT_EQ(margarita._ingredients.size(), 3);
    }
}
