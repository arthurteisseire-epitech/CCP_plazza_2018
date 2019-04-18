/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** OrderParser.hpp
*/

#ifndef PLAZZA_ORDERPARSER_HPP
#define PLAZZA_ORDERPARSER_HPP

#include <string>
#include "Order.hpp"

namespace plazza {
    class OrderParser {
    public:
        explicit OrderParser(const std::string &commandLine);
    protected:
        void parseCommand(const std::string &command);
        std::vector<Order> orders;
    };
}
#endif
