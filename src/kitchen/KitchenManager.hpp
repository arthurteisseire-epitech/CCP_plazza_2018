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
        void sendOrder(Order &order);
        void addFdsToSet(fd_set *set) const;
        int findMaxFd();
        void handleEvents();
        bool isFdSet(fd_set *set);
        void destroyKitchens();
    private:

        std::vector<Process<Kitchen>> _processes;
        int _nbCooks;

        FRIEND_TEST(KitchenManagerTest, create);
    };
}

#endif
