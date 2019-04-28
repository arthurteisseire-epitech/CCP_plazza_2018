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
#include <condition_variable>
#include <queue>
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
        void execCommand(const char *buff);
        bool isTimeout() const;

        bool isACookBusy() const;
        void kill();
        void isSpaceForPizza();
        void sendStatus();
        void managePizza(IPizza *pizza);

        std::vector<Cook> _cooks;
        std::queue<IPizza *> _pizzas;
        Stock _stock;
        const Ipc &_ipc;
        const double _cookingTimeMultiplier;
        const size_t _timeToReplaceIngredients;
        std::map<std::string, void (plazza::Kitchen::*)()> _actions;

        std::unique_ptr<std::thread> _stockThread;

        std::shared_ptr<std::mutex> _pizzasMutex;
        std::shared_ptr<std::mutex> _ingredientsMutex;

        FRIEND_TEST(KitchenTest, create);
    };
}

#endif
