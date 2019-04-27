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
#include "Ipc.hpp"

namespace plazza {
    class Kitchen {
    public:
        explicit Kitchen(const Ipc &ipc, double cookingTimeMultiplier, size_t nbCooks, size_t timeToReplaceIngredients);

        void launch();
    private:
        void waitCommand();
        void execCommand(const char *buff);
        void checkTimeout() const;

        void kill();
        void isSpaceForPizza();
        void sendStatus();
        void managePizza(IPizza *pizza);
        bool isACookWaiting();

        std::vector<Cook> _cooks;
        std::vector<IPizza *> _pizzas;
        Stock _stock;
        const Ipc &_ipc;
        const double _cookingTimeMultiplier;
        const size_t _timeToReplaceIngredients;
        std::map<std::string, void (plazza::Kitchen::*)()> _actions;

        FRIEND_TEST(KitchenTest, create);
    };
}

#endif
