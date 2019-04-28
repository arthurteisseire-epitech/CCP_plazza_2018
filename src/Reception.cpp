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
    Status status = CONTINUE;

    std::cout << "orders> " << std::flush;
    while (status == CONTINUE) {
        waitAnyEvent(&set);
        status = handleEvents(&set);
    }
}

void plazza::Reception::waitAnyEvent(fd_set *set)
{
    FD_ZERO(set);
    FD_SET(0, set);
    _kitchenManager.addFdsToSet(set);
    select(_kitchenManager.findMaxFd() + 1, set, nullptr, nullptr, nullptr);
}

plazza::Reception::Status plazza::Reception::handleEvents(fd_set *set)
{
    Status status = CONTINUE;

    if (FD_ISSET(0, set))
        status = handleUserInput();
    if (status == CONTINUE)
        _kitchenManager.handleEvents(set);
    return status;
}

plazza::Reception::Status plazza::Reception::handleUserInput()
{
    std::string line;

    if (!getline(std::cin, line))
        return END;
    execCommand(line);
    std::cout << "orders> " << std::flush;
    return CONTINUE;
}

void plazza::Reception::execCommand(const std::string &line)
{
    Order order;

    if (line == "status") {
        _kitchenManager.printKitchensStatus();
    } else {
        order = plazza::OrderParser::parseLine(line);
        _kitchenManager.sendOrder(order);
    }
}
