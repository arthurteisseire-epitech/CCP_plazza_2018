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
        Stock stock;

        ASSERT_EQ(stock.count(DOE), 5);
    }
}
