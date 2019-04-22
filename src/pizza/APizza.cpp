/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** APizza.cpp
*/

#include <utility>
#include "APizza.hpp"

plazza::APizza::APizza(plazza::PizzaType type, plazza::PizzaSize size,
                       std::vector<plazza::Ingredient> ingredients, double time) :
    _type(type),
    _size(size),
    _ingredients(std::move(ingredients)),
    _time(time)
{
}

bool plazza::APizza::prepare(Stock &stock) const
{
    bool containsAllIngredients = true;

    for (const auto &i : _ingredients)
        if (!stock.contains(i))
            containsAllIngredients = false;
    if (containsAllIngredients)
        for (const auto &i : _ingredients)
            stock.take(i);
    return containsAllIngredients;
}
