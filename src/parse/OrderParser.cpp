/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** OrderParser.cpp
*/

#include <regex>
#include <iostream>
#include "OrderParser.hpp"

plazza::OrderParser::OrderParser(const std::string &commandLine)
{
    std::string end = commandLine;
    std::string command;
    size_t semiColon;

    do {
        semiColon = end.find(';');
        command = end.substr(0, semiColon);
        parseCommand(command);
        end = end.substr(semiColon + 1);
    } while (semiColon != std::string::npos);
}

void plazza::OrderParser::parseCommand(const std::string &command)
{
    std::regex e("^[ ]*([a-zA-Z]+) (S|M|L|XL|XXL) x([1-9][0-9]*)[ ]*$");
    std::smatch m;
    std::string res;

    if (std::regex_search(command, m, e))
        orders.emplace_back(m[1], m[2], std::stoi(m[3]));
    else
        std::cerr << command << ": not a valid command" << std::endl;
}
