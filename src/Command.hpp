/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Command.hpp
*/

#ifndef PLAZZA_COMMAND_HPP
#define PLAZZA_COMMAND_HPP

#include <string>

namespace plazza {
    struct Command {
        std::string type;
        std::string size;
        int number;
    };
}

#endif
