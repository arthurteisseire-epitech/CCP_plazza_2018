/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** StockTest.cpp
*/

#include <gtest/gtest.h>
#include "Stock.hpp"

namespace plazza {
    TEST(StockTest, create)
    {
        Stock stock(5);

        ASSERT_EQ(stock.count(DOE), 5);
        ASSERT_EQ(stock.count(TOMATOE), 5);
        ASSERT_EQ(stock.count(GRUYERE), 5);
        ASSERT_EQ(stock.count(HAM), 5);
        ASSERT_EQ(stock.count(MUSHROOMS), 5);
        ASSERT_EQ(stock.count(STEAK), 5);
        ASSERT_EQ(stock.count(EGGPLANT), 5);
        ASSERT_EQ(stock.count(GOAT_CHEESE), 5);
        ASSERT_EQ(stock.count(CHIEF_LOVE), 5);
    }

    TEST(StockTest, contains)
    {
        Stock stock(5);

        ASSERT_TRUE(stock.contains(DOE));
        ASSERT_TRUE(stock.contains(5, DOE));
        ASSERT_FALSE(stock.contains(6, DOE));
    }

    TEST(StockTest, containsEach)
    {
        Stock stock(1);
        std::vector<Ingredient> ingredients = {DOE, TOMATOE, GRUYERE};

        ASSERT_TRUE(stock.containsEach(ingredients));
    }

    TEST(StockTest, take)
    {
        Stock stock(5);

        ASSERT_TRUE(stock.take(3, DOE));
        ASSERT_EQ(stock.count(DOE), 2);
        ASSERT_FALSE(stock.take(3, DOE));
        ASSERT_EQ(stock.count(DOE), 2);
        ASSERT_TRUE(stock.take(DOE));
        ASSERT_EQ(stock.count(DOE), 1);
    }
}
