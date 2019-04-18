/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Order.hpp
*/

#ifndef PLAZZA_ORDER_HPP
#define PLAZZA_ORDER_HPP

#include <string>

namespace plazza {
    struct Order {
        Order(const std::string &type, const std::string &size, int number) :
            type(type),
            size(size),
            number(number)
        {}

        std::string type;
        std::string size;
        int number;
    };
}

#endif
