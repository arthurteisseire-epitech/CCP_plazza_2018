/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Stock.cpp
*/

#include "Stock.hpp"

plazza::Stock::Stock(size_t quantity)
{
    _ingredients.emplace(DOE, quantity);
    _ingredients.emplace(TOMATOE, quantity);
    _ingredients.emplace(GRUYERE, quantity);
    _ingredients.emplace(HAM, quantity);
    _ingredients.emplace(MUSHROOMS, quantity);
    _ingredients.emplace(STEAK, quantity);
    _ingredients.emplace(EGGPLANT, quantity);
    _ingredients.emplace(GOAT_CHEESE, quantity);
    _ingredients.emplace(CHIEF_LOVE, quantity);
}

size_t plazza::Stock::count(plazza::Ingredient ingredient)
{
    auto it = _ingredients.find(ingredient);

    if (it == _ingredients.end())
        return 0;
    return it->second;
}

bool plazza::Stock::take(size_t quantity, plazza::Ingredient ingredient)
{
    auto it = _ingredients.find(ingredient);

    if (it->second >= quantity) {
        it->second -= quantity;
        return true;
    }
    return false;
}
