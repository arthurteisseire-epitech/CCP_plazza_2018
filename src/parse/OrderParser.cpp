/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** OrderParser.cpp
*/

#include <regex>
#include <iostream>
#include "OrderParser.hpp"

plazza::Order plazza::OrderParser::parseLine(const std::string &commandLine)
{
    Order order;
    std::string end = commandLine;
    std::string command;
    size_t semiColon;

    do {
        semiColon = end.find(';');
        command = end.substr(0, semiColon);
        addPizza(order, command);
        end = end.substr(semiColon + 1);
    } while (semiColon != std::string::npos);
    return order;
}

void plazza::OrderParser::addPizza(Order &order, const std::string &command)
{
    std::regex e("^[ ]*([a-zA-Z]+) ([a-zA-Z]+) x([1-9][0-9]*)[ ]*$");
    std::smatch m;
    std::string res;

    if (std::regex_search(command, m, e))
        order.addPizza(m[1], m[2], std::stoi(m[3]));
    else
        std::cerr << command << ": invalid command" << std::endl;
}
