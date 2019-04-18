/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** CommandParserTest.cpp
*/

#include "gtest/gtest.h"
#include "CommandParser.hpp"

namespace plazza {
    class CommandParserTest : public ::testing::Test, public CommandParser {
    public:
        explicit CommandParserTest() :
            CommandParser("regina XXL x2; fantasia L x23") {}
    };

    TEST_F(CommandParserTest, type)
    {
        EXPECT_STREQ(commands[0].type.c_str(), "regina");
        EXPECT_STREQ(commands[1].type.c_str(), "fantasia");
    }

    TEST_F(CommandParserTest, size)
    {
        EXPECT_STREQ(commands[0].size.c_str(), "XXL");
        EXPECT_STREQ(commands[1].size.c_str(), "L");
    }

    TEST_F(CommandParserTest, number)
    {
        EXPECT_EQ(commands[0].number, 2);
        EXPECT_EQ(commands[1].number, 23);
    }
}
