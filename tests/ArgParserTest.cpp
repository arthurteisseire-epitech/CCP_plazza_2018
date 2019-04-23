/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** ArgParserTest.cpp
*/

#include <gtest/gtest.h>
#include "ArgParser.hpp"

namespace plazza {
    TEST(ArgParserTest, parseArgs)
    {
        int ac = 4;
        const char *av[] = {"./plazza", "2", "5", "2000"};
        ArgParser parser(ac, av);

        EXPECT_FALSE(parser.failed());
        EXPECT_EQ(parser.getCookingTimeMultiplier(), 2);
        EXPECT_EQ(parser.getNbCooks(), 5);
        EXPECT_EQ(parser.getTimeToReplaceIngredient(), 2000000);
    }

    TEST(ArgParser, invalidNbArgs)
    {
        int ac = 3;
        const char *av[] = {"./plazza", "2", "5"};
        ArgParser parser(ac, av);

        EXPECT_TRUE(parser.failed());
    }

    TEST(ArgParser, invalidArg)
    {
        int ac = 3;
        const char *av[] = {"./plazza", "hello", "5", "2000"};
        ArgParser parser(ac, av);

        EXPECT_TRUE(parser.failed());
    }
}
