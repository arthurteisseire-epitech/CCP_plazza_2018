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
    _process(nullptr),
    _nbCooks(nbCooks)
{
}

void plazza::KitchenManager::sendOrder(Order &order)
{
    IPizza *pizza = order.takePizza();

    if (pizza == nullptr)
        return;
    if (_process == nullptr) {
        _process = std::make_unique<Process<Kitchen>>();
        _process->create(_nbCooks);
        _process->send(pizza->pack(), sizeof(SerializedPizza));
    }
    waitAnyInput();
}

void plazza::KitchenManager::waitAnyInput()
{
    std::string input = _process->read();

    if (input == "timeout")
        _process = nullptr;
    std::cout << "receive : " << input << std::endl;
}

