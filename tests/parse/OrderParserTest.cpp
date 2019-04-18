/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** OrderParserTest.cpp
*/

#include <gtest/gtest.h>
#include "OrderParser.hpp"

static const std::string commandLine = "regina XXL x2; fantasia M x23";

namespace plazza {
    TEST(OrderParserTest, type)
    {
        auto orders = OrderParser::parseLine(commandLine);

        EXPECT_STREQ(orders[0].type.c_str(), "regina");
        EXPECT_STREQ(orders[1].type.c_str(), "fantasia");
    }

    TEST(OrderParserTest, size)
    {
        auto orders = OrderParser::parseLine(commandLine);

        EXPECT_STREQ(orders[0].size.c_str(), "XXL");
        EXPECT_STREQ(orders[1].size.c_str(), "M");
    }

    TEST(OrderParserTest, number)
    {
        auto orders = OrderParser::parseLine(commandLine);

        EXPECT_EQ(orders[0].number, 2);
        EXPECT_EQ(orders[1].number, 23);
    }
}
