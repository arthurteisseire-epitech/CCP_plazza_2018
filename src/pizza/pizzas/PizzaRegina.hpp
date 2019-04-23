/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaRegina.hpp
*/

#ifndef PLAZZA_PIZZAREGINA_HPP
#define PLAZZA_PIZZAREGINA_HPP

#include "APizza.hpp"

namespace plazza {
    class PizzaRegina : public APizza {
    public:
        explicit PizzaRegina(PizzaSize size) :
            APizza(Regina,
                   size,
                   {DOE, TOMATOE, GRUYERE, HAM, MUSHROOMS},
                   2)
        {}
    };
}

#endif
