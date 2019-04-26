/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** KitchenTest.cpp
*/

#include <gtest/gtest.h>
#include "Kitchen.hpp"

namespace plazza {
    TEST(KitchenTest, create)
    {
        Kitchen kitchen(0, 2);

        ASSERT_EQ(kitchen._cooks.size(), 2);
    }
}
