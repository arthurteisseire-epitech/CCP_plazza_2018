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
        KitchenManager();
        void sendOrder(const Order &order);
    private:
        void createKitchen();

        Process _process;
        std::vector<int> _kitchensFd;
        FRIEND_TEST(KitchenManagerTest, create);
    };
}

#endif
