/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaException.hpp
*/

#ifndef PLAZZA_PIZZAEXCEPTION_HPP
#define PLAZZA_PIZZAEXCEPTION_HPP

#include <stdexcept>

namespace plazza {
    class PizzaException : public std::runtime_error {
    public:
        explicit PizzaException(const std::string &message) :
            std::runtime_error("Pizza : " + message)
        {};
    };
}

#endif
