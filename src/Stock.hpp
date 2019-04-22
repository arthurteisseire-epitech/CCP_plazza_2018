/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Stock.hpp
*/

#ifndef PLAZZA_STOCK_HPP
#define PLAZZA_STOCK_HPP

#include <map>
#include <vector>
#include "Ingredient.hpp"

namespace plazza {
    class Stock {
    public:
        explicit Stock(size_t quantity);
        size_t count(Ingredient ingredient);
        bool take(Ingredient ingredient);
        bool take(size_t quantity, Ingredient ingredient);
        bool takeEach(const std::vector<Ingredient> &ingredients);
        bool contains(Ingredient ingredient) const;
        bool contains(size_t quantity, Ingredient ingredient) const;
        bool containsEach(const std::vector<Ingredient> &ingredients) const;
    private:
        std::map<Ingredient, size_t> _ingredients;
    };
}

#endif
