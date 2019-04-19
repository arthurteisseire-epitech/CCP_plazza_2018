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
        PizzaFactory() = default;
        std::unique_ptr<IPizza> create(PizzaType type, PizzaSize size) const;
    private:
        typedef std::map<PizzaType, std::function<std::unique_ptr<IPizza>(PizzaSize)>> pizzaMap;
        static const pizzaMap _pizzas;
    };
}

#endif
