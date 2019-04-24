/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaFactory.hpp
*/

#ifndef PLAZZA_PIZZAFACTORY_HPP
#define PLAZZA_PIZZAFACTORY_HPP

#include <map>
#include <functional>
#include <memory>
#include "IPizza.hpp"
#include "PizzaSize.hpp"
#include "PizzaType.hpp"

namespace plazza {
    class PizzaFactory {
    public:
        static IPizza *create(const std::string &type, const std::string &size);
        static IPizza *create(PizzaType type, PizzaSize size);
    private:
        static const std::map<std::string, PizzaType> _types;
        static const std::map<std::string, PizzaSize> _sizes;
        typedef std::map<PizzaType, std::function<IPizza *(PizzaSize)>> pizzaMap;
        static const pizzaMap _pizzas;
    };
}

#endif
