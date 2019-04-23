/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaMargarita.hpp
*/

#ifndef PLAZZA_PIZZAMARGARITA_HPP
#define PLAZZA_PIZZAMARGARITA_HPP

#include "APizza.hpp"

namespace plazza {
    class PizzaMargarita : public APizza {
    public:
        explicit PizzaMargarita(PizzaSize size) :
            APizza(Margarita,
                   size,
                   {DOE, TOMATOE, GRUYERE},
                   1)
        {}
    };
}

#endif
