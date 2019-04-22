/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Stock.hpp
*/

#ifndef PLAZZA_STOCK_HPP
#define PLAZZA_STOCK_HPP

#include <map>
#include "Ingredient.hpp"

namespace plazza {
    class Stock {
    public:
        explicit Stock(size_t quantity);
        size_t count(Ingredient ingredient);
    private:
        std::map<Ingredient, size_t> _ingredients;
    };
}

#endif
