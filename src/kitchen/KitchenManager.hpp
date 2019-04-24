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
        void sendOrder(const Order &order);
    private:
        void createKitchen();

        std::vector<Process<Kitchen>> _processes;
        int _nbCooks;
        int _sockets[2];

        FRIEND_TEST(KitchenManagerTest, create);
    };
}

#endif
