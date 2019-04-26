/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** KitchenManager.cpp
*/

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include "KitchenManager.hpp"
#include "Kitchen.hpp"

plazza::KitchenManager::KitchenManager(size_t nbCooks) :
    _nbCooks(nbCooks)
{
}

void plazza::KitchenManager::sendOrder(Order &order)
{
    IPizza *pizza = order.takePizza();

    if (pizza == nullptr)
        return;
    if (_processes.empty()) {
        _processes.emplace_back();
        _processes[0].create(_nbCooks);
        _processes[0].send(pizza->pack(), sizeof(SerializedPizza));
    }
}

void plazza::KitchenManager::handleEvents()
{
    std::string input = _processes[0].read();

    if (input == "timeout")
        _processes.pop_back();
    std::cout << "receive : " << input << std::endl;
}

void plazza::KitchenManager::addFdsToSet(fd_set *set) const
{
    for (const auto &p : _processes)
        FD_SET(p.getReadFd(), set);
}

int plazza::KitchenManager::findMaxFd()
{
    int maxFd = 0;

    for (const auto &p : _processes)
        maxFd = std::max(p.getReadFd(), maxFd);
    return maxFd;
}

bool plazza::KitchenManager::isFdSet(fd_set *set)
{
    for (const auto &p : _processes)
        if (FD_ISSET(p.getReadFd(), set))
            return true;
    return false;
}

void plazza::KitchenManager::destroyKitchens()
{
    for (const auto &p : _processes)
        p.send("kill");
}
