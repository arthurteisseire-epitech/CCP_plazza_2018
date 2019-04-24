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
        IPizza *unpack() const;
    private:
        PizzaType _type;
        PizzaSize _size;

        FRIEND_TEST(SerializedPizzaTest, create);
        FRIEND_TEST(SerializedPizzaTest, pack);
    };
}

#endif
