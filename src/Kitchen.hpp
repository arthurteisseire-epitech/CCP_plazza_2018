/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Kitchen.hpp
*/

#ifndef PLAZZA_KITCHEN_HPP
#define PLAZZA_KITCHEN_HPP

#include <gtest/gtest_prod.h>
#include <vector>
#include "Cook.hpp"

namespace plazza {
    class Kitchen {
    public:
        explicit Kitchen(size_t nbCooks);
    private:
        std::vector<Cook> _cooks;

        FRIEND_TEST(KitchenTest, create);
    };
}

#endif
