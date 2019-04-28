/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Kitchen.cpp
*/

#include <unistd.h>
#include <chrono>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "Kitchen.hpp"
#include "SerializedPizza.hpp"
#include "Cook.hpp"

plazza::Kitchen::Kitchen(const Ipc &ipc, double cookingTimeMultiplier, size_t nbCooks, size_t timeToReplaceIngredients)
    :
    _stock(5),
    _ipc(ipc),
    _cookingTimeMultiplier(cookingTimeMultiplier),
    _timeToReplaceIngredients(timeToReplaceIngredients),
    _pizzasMutex(std::make_unique<std::mutex>()),
    _ingredientsMutex(std::make_unique<std::mutex>())
{
    _cooks.reserve(nbCooks);
    for (size_t i = 0; i < nbCooks; ++i) {
        _cooks.emplace_back(_cookingTimeMultiplier, _stock, _pizzas, _pizzasMutex, _ingredientsMutex);
    }

    _actions = {
        {"kill",    &plazza::Kitchen::kill},
        {"isSpace", &plazza::Kitchen::isSpaceForPizza},
        {"status",  &plazza::Kitchen::sendStatus},
    };
}

void plazza::Kitchen::launch()
{
    char buffer[4096];

    while (true) {
        _ipc.readParentInput(buffer, sizeof(buffer));
        execCommand(buffer);
    }
}

bool plazza::Kitchen::isTimeout() const
{
    struct timeval time = {5, 0};
    fd_set set;

    FD_ZERO(&set);
    FD_SET(_ipc.getChildFd(), &set);
    select(_ipc.getChildFd() + 1, &set, nullptr, nullptr, &time);
    if (!FD_ISSET(_ipc.getChildFd(), &set)) {
        _ipc.sendToParent("timeout");
        return true;
    }
    return false;
}

void plazza::Kitchen::execCommand(const char *buff)
{
    std::string input(buff);
    auto it = std::find_if(_actions.begin(), _actions.end(),
                           [&input](const std::pair<std::string, void (plazza::Kitchen::*)()> &pair) {
                               return std::equal(pair.first.begin(), pair.first.end(), input.begin());
                           });

    if (it != _actions.end())
        (this->*it->second)();
    else
        managePizza(plazza::SerializedPizza((unsigned char *)buff).unpack());
}

void plazza::Kitchen::managePizza(IPizza *pizza)
{
    _pizzas.push(pizza);
#ifdef PLAZZADEBUG
    std::cout << "Kitchen Added pizza to queue" << std::endl;
#endif
    _ipc.sendToParent("add pizza ok");
}

void plazza::Kitchen::kill()
{
#ifdef PLAZZADEBUG
    std::cout << "kicthen receive kill" << std::endl;
#endif
    exit(0);
}

void plazza::Kitchen::isSpaceForPizza()
{
    if (_pizzas.size() < _cooks.size())
        _ipc.sendToParent("yes");
    else
        _ipc.sendToParent("no");
}

void plazza::Kitchen::sendStatus()
{
    std::string status;
    std::string cookStatus = "busy";

    for (size_t i = 0; i < _cooks.size(); ++i) {
        if (_cooks[i].getStatus() == Cook::WAITING)
            cookStatus = "waiting";
        status += "\tCook " + std::to_string(i) + ": " + cookStatus + "\n";
    }
    _ipc.sendToParent(status.c_str());
}

plazza::IPizza *plazza::Kitchen::getPizza()
{
    IPizza *res = this->_pizzas.front();

    if (res == nullptr)
        return (nullptr);
    this->_pizzas.pop();
    return (res);
}
