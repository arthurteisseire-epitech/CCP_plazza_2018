/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** KitchenManager.hpp
*/

#ifndef PLAZZA_KITCHENMANAGER_HPP
#define PLAZZA_KITCHENMANAGER_HPP

#include <gtest/gtest_prod.h>
#include "Order.hpp"
#include "Process.hpp"

namespace plazza {
    class KitchenManager {
    public:
        KitchenManager(double cookingTimeMultiplier, size_t nbCooks, size_t timeToReplaceIngredients);
        void sendOrder(Order &order);
        void addFdsToSet(fd_set *set) const;
        int findMaxFd();
        void handleEvents(fd_set *set);
        bool isFdSet(fd_set *set);
        void destroyKitchensProcesses();
        void printKitchensStatus();
    private:
        void sendPizza(const SerializedPizza &serializedPizza);
        void execActionFromInput(std::unique_ptr<Process<Kitchen>> &p);
        void removeKitchen(std::unique_ptr<Process<Kitchen>> &p);
        Process<Kitchen> *findAvailableKitchen() const;

        std::vector<std::unique_ptr<Process<Kitchen>>> _processes;
        std::map<std::string, void (plazza::KitchenManager::*)(std::unique_ptr<Process<Kitchen>> &)> _actions;
        const double _cookingTimeMultiplier;
        const int _nbCooks;
        const size_t _timeToReplaceIngredients;

        FRIEND_TEST(KitchenManagerTest, create);
    };
}

#endif
