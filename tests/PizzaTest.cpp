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
        EXPECT_EQ(margarita._time, 1);
        EXPECT_EQ(margarita._ingredients.size(), 3);
    }

    TEST(PizzaTest, prepare)
    {
        Stock stock(5);
        PizzaMargarita margarita(L);

        ASSERT_TRUE(margarita.prepare(stock));
        ASSERT_EQ(stock.count(DOE), 4);
        ASSERT_EQ(stock.count(TOMATOE), 4);
        ASSERT_EQ(stock.count(GRUYERE), 4);
        ASSERT_EQ(stock.count(CHIEF_LOVE), 5);
    }
}
