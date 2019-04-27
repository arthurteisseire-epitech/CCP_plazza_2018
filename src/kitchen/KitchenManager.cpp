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
    while (!order.isEmpty())
        sendPizza(order.takePizza());
}

void plazza::KitchenManager::sendPizza(const SerializedPizza &serializedPizza)
{
    std::string s;
    bool isSpace = false;

    for (auto &p : _processes) {
        p->send("isSpace");
        s = p->read();
        if (s == "yes" || s == "in stock") {
            std::cout << "is space : ok, send pizza..." << std::endl;
            p->send(serializedPizza, sizeof(plazza::SerializedPizza));
            p->read();
            isSpace = true;
            break;
        }
    }
    if (!isSpace) {
        std::cout << "no space : kitchen creation..." << std::endl;
        _processes.emplace_back(std::make_unique<plazza::Process<plazza::Kitchen>>());
        _processes.back()->create(_nbCooks);
        _processes.back()->send(serializedPizza, sizeof(plazza::SerializedPizza));
        _processes.back()->read();
    }
}

void plazza::KitchenManager::handleEvents(fd_set *set)
{
    std::cout << "nb kitchens : " << _processes.size() << std::endl;
    for (auto &p : _processes)
        if (FD_ISSET(p->getReadFd(), set)) {
            execActionFromInput(p);
            handleEvents(set);
            return;
        }
}

void plazza::KitchenManager::execActionFromInput(std::unique_ptr<Process<Kitchen>> &p)
{
    std::string input = p->read();
    auto it = _actions.find(input);

    (this->*it->second)(p);
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
