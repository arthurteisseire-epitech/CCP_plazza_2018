/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** KitchenManager.cpp
*/

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include "KitchenManager.hpp"
#include "Kitchen.hpp"

plazza::KitchenManager::KitchenManager(size_t nbCooks) :
    _nbCooks(nbCooks)
{
    _actions = {
        {"timeout", &plazza::KitchenManager::removeKitchen},
    };
}

void plazza::KitchenManager::sendOrder(Order &order)
{
    std::string s;

    if (order.isEmpty())
        return;
    if (_processes.empty()) {
        _processes.emplace_back(std::make_unique<Process<Kitchen>>());
        _processes[0]->create(_nbCooks);
    }
    _processes[0]->send("isSpace");
    s = _processes[0]->read();
    if (s == "yes")
        _processes[0]->send(order.takePizza(), sizeof(SerializedPizza));
    else if (s == "in stock") {
        _processes[0]->send(order.takePizza(), sizeof(SerializedPizza));
        std::cout << "pizza in stock" << std::endl;
    }
}

void plazza::KitchenManager::handleEvents(fd_set *set)
{
    for (const auto &p : _processes)
        if (FD_ISSET(p->getReadFd(), set))
            execActionFromInput();
}

void plazza::KitchenManager::execActionFromInput()
{
    std::string input = _processes[0]->read();
    auto it = _actions.find(input);

    (this->*it->second)(_processes[0]);
}

void plazza::KitchenManager::addFdsToSet(fd_set *set) const
{
    for (const auto &p : _processes)
        FD_SET(p->getReadFd(), set);
}

int plazza::KitchenManager::findMaxFd()
{
    int maxFd = 0;

    for (const auto &p : _processes)
        maxFd = std::max(p->getReadFd(), maxFd);
    return maxFd;
}

bool plazza::KitchenManager::isFdSet(fd_set *set)
{
    for (const auto &p : _processes)
        if (FD_ISSET(p->getReadFd(), set))
            return true;
    return false;
}

void plazza::KitchenManager::destroyKitchensProcesses()
{
    for (const auto &p : _processes)
        p->send("kill");
}

void plazza::KitchenManager::removeKitchen(std::unique_ptr<Process<Kitchen>> &p)
{
    _processes.erase(std::find(_processes.begin(), _processes.end(), p));
    std::cout << "kitchen destroyed..." << std::endl;
}
