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
    auto p = findAvailableKitchen();

    if (p == nullptr) {
        std::cout << "no space : kitchen creation..." << std::endl;
        _processes.emplace_back(std::make_unique<plazza::Process<plazza::Kitchen>>());
        _processes.back()->create(_nbCooks);
        p = _processes.back().get();
    }
    p->send(serializedPizza, sizeof(plazza::SerializedPizza));
    p->read();
}

plazza::Process<plazza::Kitchen> *plazza::KitchenManager::findAvailableKitchen() const
{
    std::string s;

    for (auto &p : this->_processes) {
        p->send("isSpace");
        s = p->read();
        if (s == "yes" || s == "in stock") {
            std::cout << "is space : ok, send pizza..." << std::endl;
            return p.get();
        }
    }
    return nullptr;
}

void plazza::KitchenManager::handleEvents(fd_set *set)
{
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

void plazza::KitchenManager::printKitchensStatus()
{
    std::string kitchenStatus;

    for (size_t i = 0; i < _processes.size(); ++i) {
        _processes[i]->send("status");
        kitchenStatus = _processes[i]->read();
        std::cout << "Kitchen " << i << ":" << std::endl;
        std::cout << kitchenStatus << std::flush;
    }
}
