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

void plazza::Reception::exec()
{
    std::string line;
    std::vector<Order> orders;

    std::cout << "orders> ";
    while (getline(std::cin, line)) {
        orders = OrderParser::parseLine(line);
        std::cout << "orders> ";
    }
}
