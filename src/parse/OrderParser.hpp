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
        static Order parseLine(const std::string &commandLine);
    private:
        static void addPizza(Order &orders, const std::string &command);
    };
}

#endif
