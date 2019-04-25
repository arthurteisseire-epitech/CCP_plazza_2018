/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** SerializedPizza.hpp
*/

#ifndef PLAZZA_SERIALIZEDPIZZA_HPP
#define PLAZZA_SERIALIZEDPIZZA_HPP

#include <gtest/gtest_prod.h>
#include "PizzaSize.hpp"
#include "PizzaType.hpp"
#include "SerializedPizza.hpp"

namespace plazza {
    class IPizza;
    class SerializedPizza {
    public:
        SerializedPizza(PizzaType type, PizzaSize size);
        SerializedPizza(const unsigned char *bytes);
        IPizza *unpack() const;
    private:
        unsigned _type;
        unsigned _size;

        FRIEND_TEST(SerializedPizzaTest, create);
        FRIEND_TEST(SerializedPizzaTest, pack);
        FRIEND_TEST(SerializedPizzaTest, constructWithBytes);
    };
}

#endif
