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

void plazza::KitchenManager::addFdsToSet(fd_set *set)
{
    if (!_processes.empty())
        FD_SET(_processes[0].getReadFd(), set);
}

int plazza::KitchenManager::findMaxFd()
{
    if (!_processes.empty())
        return _processes[0].getReadFd();
    return 0;
}

bool plazza::KitchenManager::isFdSet(fd_set *set)
{
    return !_processes.empty() && FD_ISSET(_processes[0].getReadFd(), set);
}

void plazza::KitchenManager::destroyKitchens()
{
    if (!_processes.empty())
        _processes[0].send("kill");
}
