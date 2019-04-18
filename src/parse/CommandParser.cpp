/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** CommandParser.cpp
*/

#include <regex>
#include <iostream>
#include "CommandParser.hpp"

plazza::CommandParser::CommandParser(const std::string &commandLine)
{
    std::regex e("^(([a-zA-Z]+) (S|M|L|XL|XXL) x([1-9][0-9]*))+$");
    std::smatch m;
    std::string res;

    if (std::regex_search(commandLine, m, e)) {
        commands.emplace_back(m[2], m[3], std::stoi(m[4]));
    } else {
        std::cerr << "not a valid command" << std::endl;
    }
}
