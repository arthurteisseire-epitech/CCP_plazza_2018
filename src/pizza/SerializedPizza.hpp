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

namespace plazza {
    class SerializedPizza {
    public:
        SerializedPizza(PizzaType type, PizzaSize size);
    private:
        PizzaType _type;
        PizzaSize _size;

        FRIEND_TEST(SerializedPizzaTest, create);
    };
}

#endif
