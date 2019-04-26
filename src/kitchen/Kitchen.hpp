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
        void waitCommand();
        void execCommand(const unsigned char *buff);
        void checkTimeout() const;

        void kill();
        void isSpaceForPizza();
        void managePizza(IPizza *pizza);
        std::vector<Cook> _cooks;
        std::vector<IPizza *> _pizzas;
        Stock _stock;
        int _fd;

        std::map<std::string, void (plazza::Kitchen::*)()> _actions;
        FRIEND_TEST(KitchenTest, create);

        bool isACookWaiting();
    };
}

#endif
