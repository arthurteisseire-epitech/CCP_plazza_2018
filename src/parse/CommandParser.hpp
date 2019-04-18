/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** CommandParser.hpp
*/

#ifndef PLAZZA_COMMANDPARSER_HPP
#define PLAZZA_COMMANDPARSER_HPP

#include <string>
#include "Command.hpp"

namespace plazza {
    class CommandParser {
    public:
        explicit CommandParser(const std::string &commandLine);
    protected:
        std::vector<Command> commands;
    };
}
#endif
