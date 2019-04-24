/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** SerializedPizzaTest.cpp
*/

#include <gtest/gtest.h>
#include "PizzaAmericana.hpp"
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

    TEST(SerializedPizzaTest, pack)
    {
        PizzaAmericana americana(XL);
        SerializedPizza serializedPizza = americana.pack();

        EXPECT_EQ(serializedPizza._type, Americana);
        EXPECT_EQ(serializedPizza._size, XL);
    }

    TEST(SerializedPizzaTest, unpack)
    {
        SerializedPizza serializedPizza(Fantasia, XXL);
        IPizza *pizza = serializedPizza.unpack();
    }
}
