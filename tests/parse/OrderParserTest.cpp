/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** OrderParserTest.cpp
*/

#include <gtest/gtest.h>
#include "OrderParser.hpp"

namespace plazza {
    class OrderParserTest : public ::testing::Test, public OrderParser {
    public:
        explicit OrderParserTest() :
            OrderParser("regina XXL x2; fantasia L x23") {}
    };

    TEST_F(OrderParserTest, type)
    {
        EXPECT_STREQ(orders[0].type.c_str(), "regina");
        EXPECT_STREQ(orders[1].type.c_str(), "fantasia");
    }

    TEST_F(OrderParserTest, size)
    {
        EXPECT_STREQ(orders[0].size.c_str(), "XXL");
        EXPECT_STREQ(orders[1].size.c_str(), "L");
    }

    TEST_F(OrderParserTest, number)
    {
        EXPECT_EQ(orders[0].number, 2);
        EXPECT_EQ(orders[1].number, 23);
    }
}
