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
}

size_t plazza::Stock::count(plazza::Ingredient ingredient)
{
    return _ingredients.at(DOE);
}
