/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaAmericana.hpp
*/

#ifndef PLAZZA_PIZZAAMERICANA_HPP
#define PLAZZA_PIZZAAMERICANA_HPP

#include "APizza.hpp"

namespace plazza {
    class PizzaAmericana : public APizza {
    public:
        explicit PizzaAmericana(PizzaSize size) :
            APizza(PizzaType::Margarita,
                   size,
                   {DOE, TOMATOE, GRUYERE, STEAK},
                   2.0f)
        {}
    };
}

#endif
