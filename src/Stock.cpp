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

size_t plazza::Stock::count(Ingredient ingredient)
{
    auto it = _ingredients.find(ingredient);

    if (it == _ingredients.end())
        return 0;
    return it->second;
}

bool plazza::Stock::take(plazza::Ingredient ingredient)
{
    return take(1, ingredient);
}

bool plazza::Stock::take(size_t quantity, Ingredient ingredient)
{
    bool containsIngredient = contains(quantity, ingredient);

    if (containsIngredient)
        _ingredients.at(ingredient) -= quantity;
    return containsIngredient;
}

bool plazza::Stock::contains(plazza::Ingredient ingredient) const
{
    return contains(1, ingredient);
}

bool plazza::Stock::contains(size_t quantity, Ingredient ingredient) const
{
    auto it = _ingredients.find(ingredient);

    return it != _ingredients.end() && it->second >= quantity;
}

bool plazza::Stock::containsEach(const std::vector<plazza::Ingredient> &ingredients) const
{
    for (const auto &i : ingredients)
        if (!contains(i))
            return false;
    return true;
}
