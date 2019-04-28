/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** IPizza.hpp
*/

#ifndef PLAZZA_IPIZZA_HPP
#define PLAZZA_IPIZZA_HPP

#include "Stock.hpp"
#include "SerializedPizza.hpp"

namespace plazza {
    class IPizza {
    public:
        virtual ~IPizza() = default;
        virtual void prepare(double timeMultiplier) const = 0;
        virtual SerializedPizza pack() const = 0;
        virtual const std::vector<Ingredient> &getIngredients() const = 0;
    };
}

#endif
