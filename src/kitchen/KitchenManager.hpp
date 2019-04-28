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
        explicit KitchenManager(size_t nbCooks);
        ~KitchenManager();

        void sendOrder(Order &order);
        void addFdsToSet(fd_set *set) const;
        int findMaxFd() const;
        void handleEvents(fd_set *set);
        void printKitchensStatus() const;
    private:
        void sendPizza(const SerializedPizza &serializedPizza);
        void execActionFromInput(std::unique_ptr<Process<Kitchen>> &p);
        void removeKitchen(std::unique_ptr<Process<Kitchen>> &p);
        Process<Kitchen> *findAvailableKitchen() const;

        std::vector<std::unique_ptr<Process<Kitchen>>> _processes;
        int _nbCooks;

        std::map<std::string, void (plazza::KitchenManager::*)(std::unique_ptr<Process<Kitchen>> &)> _actions;
        FRIEND_TEST(KitchenManagerTest, create);
    };
}

#endif
