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
            CommandParser("regina XXL x2") {}
    };

    TEST_F(CommandParserTest, type)
    {
        EXPECT_STREQ(command.type.c_str(), "regina");
    }

    TEST_F(CommandParserTest, size)
    {
        EXPECT_STREQ(command.size.c_str(), "XXL");
    }

    TEST_F(CommandParserTest, number)
    {
        EXPECT_EQ(command.number, 2);
    }
}
