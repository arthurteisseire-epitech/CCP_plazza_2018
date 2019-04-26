/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Resolver.hpp
*/

#ifndef PLAZZA_RESOLVER_HPP
#define PLAZZA_RESOLVER_HPP

#include <map>
#include "PizzaType.hpp"
#include "PizzaSize.hpp"

namespace plazza {
    class Resolver {
    public:
        static PizzaType findType(const std::string &type);
        static PizzaSize findSize(const std::string &size);
    private:
        static const std::map<std::string, PizzaType> _types;
        static const std::map<std::string, PizzaSize> _sizes;
    };
}

#endif
