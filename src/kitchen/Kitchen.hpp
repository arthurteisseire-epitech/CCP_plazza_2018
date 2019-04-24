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
#include "Stock.hpp"

namespace plazza {
    class Kitchen {
    public:
        explicit Kitchen(int readFd, int writeFd, size_t nbCooks);

        void exec();
    private:
        std::vector<Cook> _cooks;
        Stock _stock;
        int _readFd;
        int _writeFd;

        FRIEND_TEST(KitchenTest, create);
    };
}

#endif
