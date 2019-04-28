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
    _kitchenManager(nbCooks),
    _cookingTimeMultiplier(cookingTime),
    _nbCooks(nbCooks),
    _timeToReplaceIngredient(timeToReplaceIngredient)
{
}

void plazza::Reception::open()
{
    fd_set set;

    std::cout << "orders> " << std::flush;
    while (true) {
        waitAnyEvent(&set);
        handleEvents(&set);
    }
}

void plazza::Reception::waitAnyEvent(fd_set *set)
{
    FD_ZERO(set);
    FD_SET(0, set);
    _kitchenManager.addFdsToSet(set);
    select(_kitchenManager.findMaxFd() + 1, set, nullptr, nullptr, nullptr);
}

void plazza::Reception::handleEvents(fd_set *set)
{
    if (FD_ISSET(0, set)) {
        sendOrderFromUserInput();
        std::cout << "orders> " << std::flush;
    }
    _kitchenManager.handleEvents(set);
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
