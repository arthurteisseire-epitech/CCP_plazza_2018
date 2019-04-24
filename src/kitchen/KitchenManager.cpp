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

plazza::KitchenManager::KitchenManager(size_t nbCooks) :
    _nbCooks(nbCooks)
{
}

void plazza::KitchenManager::sendOrder(const Order &)
{
    createKitchen();
    _processes[0].send("hey");
}

void plazza::KitchenManager::createKitchen()
{
    _processes.emplace_back(1);
    _processes[0].exec(_nbCooks);
}
