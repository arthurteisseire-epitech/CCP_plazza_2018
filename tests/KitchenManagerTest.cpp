/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** KitchenManagerTest.cpp
*/

#include <gtest/gtest.h>
#include "Order.hpp"
#include "KitchenManager.hpp"

namespace plazza {
    TEST(KitchenManagerTest, create)
    {
        Order order;
        KitchenManager manager(1);

        order.addPizza("regina", "XL", 1);
        manager.createKitchen();
        EXPECT_EQ(manager._processes.size(), 1);
    }
}
