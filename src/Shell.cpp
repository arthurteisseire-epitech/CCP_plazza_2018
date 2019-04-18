/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Shell.cpp
*/

#include <string>
#include <iostream>
#include <vector>
#include "OrderParser.hpp"
#include "Shell.hpp"
#include "Order.hpp"

void plazza::Shell::exec()
{
    std::string line;
    std::vector<Order> orders;

    std::cout << "orders> ";
    while (getline(std::cin, line)) {
        orders = OrderParser::parseLine(line);
        std::cout << "orders> ";
    }
}
