/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Reception.cpp
*/

#include <string>
#include <iostream>
#include <vector>
#include "OrderParser.hpp"
#include "Reception.hpp"
#include "Order.hpp"

plazza::Reception::Reception(double cookingTime, size_t nbCooks, size_t timeToReplaceIngredient) :
    _kitchenManager(cookingTime, nbCooks, timeToReplaceIngredient),
    _cookingTimeMultiplier(cookingTime),
    _nbCooks(nbCooks),
    _timeToReplaceIngredient(timeToReplaceIngredient)
{
}

void plazza::Reception::open()
{
    std::cout << "orders> " << std::flush;
    while (true)
        handleEvent();
}

void plazza::Reception::handleEvent()
{
    fd_set set;

    FD_ZERO(&set);
    _kitchenManager.addFdsToSet(&set);
    FD_SET(0, &set);
    select(_kitchenManager.findMaxFd() + 1, &set, nullptr, nullptr, nullptr);
    if (FD_ISSET(0, &set)) {
        sendOrderFromUserInput();
        std::cout << "orders> " << std::flush;
    }
    if (_kitchenManager.isFdSet(&set))
        _kitchenManager.handleEvents(&set);
}

void plazza::Reception::sendOrderFromUserInput()
{
    std::string line;
    Order order;

    if (!getline(std::cin, line)) {
        std::cout << "bye" << std::endl;
        _kitchenManager.destroyKitchensProcesses();
        exit(0);
    }
    if (line == "status") {
        _kitchenManager.printKitchensStatus();
    } else {
        order = plazza::OrderParser::parseLine(line);
        _kitchenManager.sendOrder(order);
    }
}
