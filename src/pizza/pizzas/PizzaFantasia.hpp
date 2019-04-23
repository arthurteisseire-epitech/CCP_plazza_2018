/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** PizzaFantasia.hpp
*/

#ifndef PLAZZA_PIZZAFANTASIA_HPP
#define PLAZZA_PIZZAFANTASIA_HPP

#include "APizza.hpp"

namespace plazza {
    class PizzaFantasia : public APizza {
    public:
        explicit PizzaFantasia(PizzaSize size) :
            APizza(Fantasia,
                   size,
                   {DOE, TOMATOE, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE},
                   4)
        {}
    };
}

#endif
