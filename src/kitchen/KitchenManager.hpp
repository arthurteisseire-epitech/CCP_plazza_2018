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

namespace plazza {
    class KitchenManager {
    public:
        KitchenManager() = default;
    private:
        void createKitchen();

        std::vector<int> _kitchensFd;
        FRIEND_TEST(KitchenManagerTest, create);
    };
}

#endif
