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
#include "IPizza.hpp"
#include "Cook.hpp"
#include "Stock.hpp"

namespace plazza {
    class Kitchen {
    public:
        explicit Kitchen(int fd, size_t nbCooks);

        void launch();
    private:
        void handlePizza(IPizza *pizza);
        void waitCommand();
        void checkTimeout() const;

        void kill(const char *buffer);
        std::vector<Cook> _cooks;
        Stock _stock;
        int _fd;

        std::map<std::string, void (plazza::Kitchen::*)(const char *buffer)> _actions;
        FRIEND_TEST(KitchenTest, create);
    };
}

#endif
