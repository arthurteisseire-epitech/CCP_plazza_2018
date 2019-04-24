/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** KitchenManager.cpp
*/

#include <sys/socket.h>
#include <unistd.h>
#include "KitchenManager.hpp"
#include "Kitchen.hpp"

plazza::KitchenManager::KitchenManager() :
    _process(1)
{
}

void plazza::KitchenManager::sendOrder(const Order &)
{
    createKitchen();
    _process.send("hey");
}

void plazza::KitchenManager::createKitchen()
{
    _process.exec();
}
