/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Stock.cpp
*/

#include "Stock.hpp"

plazza::Stock::Stock()
{
    _ingredients.emplace(DOE, 5);
    _ingredients.emplace(TOMATOE, 5);
    _ingredients.emplace(GRUYERE, 5);
    _ingredients.emplace(HAM, 5);
    _ingredients.emplace(MUSHROOMS, 5);
    _ingredients.emplace(STEAK, 5);
    _ingredients.emplace(EGGPLANT, 5);
    _ingredients.emplace(GOAT_CHEESE, 5);
    _ingredients.emplace(CHIEF_LOVE, 5);
}

size_t plazza::Stock::count(plazza::Ingredient ingredient)
{
    return _ingredients.at(ingredient);
}
