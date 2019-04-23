/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** SerializedPizzaTest.cpp
*/

#include <gtest/gtest.h>
#include "SerializedPizza.hpp"
#include "PizzaType.hpp"
#include "PizzaSize.hpp"

namespace plazza {
    TEST(SerializedPizzaTest, create)
    {
        SerializedPizza serializedPizza(PizzaType::Margarita, PizzaSize::L);

        ASSERT_EQ(serializedPizza._type, PizzaType::Margarita);
        ASSERT_EQ(serializedPizza._size, PizzaSize::L);
    }
}
