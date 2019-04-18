/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** OrderParser.cpp
*/

#include <regex>
#include <iostream>
#include "OrderParser.hpp"

std::vector<plazza::Order> plazza::OrderParser::parseLine(const std::string &commandLine)
{
    std::vector<Order> orders;
    std::string end = commandLine;
    std::string command;
    size_t semiColon;

    do {
        semiColon = end.find(';');
        command = end.substr(0, semiColon);
        addOrder(orders, command);
        end = end.substr(semiColon + 1);
    } while (semiColon != std::string::npos);
    return orders;
}

void plazza::OrderParser::addOrder(std::vector<Order> &orders, const std::string &command)
{
    std::regex e("^[ ]*([a-zA-Z]+) (S|M|L|XL|XXL) x([1-9][0-9]*)[ ]*$");
    std::smatch m;
    std::string res;

    if (std::regex_search(command, m, e))
        orders.emplace_back(m[1], m[2], std::stoi(m[3]));
    else
        std::cerr << command << ": not a valid command" << std::endl;
}
